#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PTUClient.h"
#include "ptu.pb.h"

/*
 * This file creates the server and client for this program, and makes the slots for all the inputs. It also does degrees to PTU unit calculations in the setPan and setTilt functions.
 * This file after creation will sit idly waiting for slot calls from UdpServer, or user input. Whever we receive slot calls, we update variables and GUI components, and when we
 * get user input, we send commands to UdpClient.
 *
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    heartbeatTimer = new QTimer(this);
    heartbeatTimer->setInterval(15000);
    heartbeatTimer->setSingleShot(true);

    connect(heartbeatTimer, &QTimer::timeout, this, [=](){
        qDebug() << "No data received from server for 15 seconds!";
        disableUI();
    });

    ui->widget_11->setAttribute(Qt::WA_StyledBackground, true);
    ui->widget_12->setAttribute(Qt::WA_StyledBackground, true);


    disableUI();

    server = new UdpServer(this);
    client = new UdpClient(this);

    connect(server, &UdpServer::processDatagram, this, &MainWindow::processDatagram);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processDatagram(QNetworkDatagram datagram){
    qDebug() << "GUI has received a datagram from the UdpServer!";
    QByteArray data = datagram.data();
    QHostAddress senderIP = datagram.senderAddress();

    ptu::PTUStatus status;
    if (!status.ParseFromArray(data.constData(), data.size())){
        qWarning() << "Failed to parse PTUStatus protobuf message in UdpServer::processDatagram()";
        return;
    }

    int Pan = status.pan_units();
    int Tilt = status.tilt_units();
    PAN_MIN_DEG = status.pan_min_deg();
    PAN_MAX_DEG = status.pan_max_deg();
    TILT_MIN_DEG = status.tilt_min_deg();
    TILT_MAX_DEG = status.tilt_max_deg();
    panDegreesPerUnit = status.pan_degrees_per_unit();
    tiltDegreesPerUnit = status.tilt_degrees_per_unit();
    quint16 senderPort = status.port();
    panHeading = status.pan_heading();
    tiltHeading = status.tilt_heading();

    heartbeatTimer->start(); // restart heartbeat
    ui->PanSpinBox->setMinimum(0);
    ui->PanSpinBox->setMaximum(359);
    ui->TiltSpinBox->setMinimum(TILT_MIN_DEG);
    ui->TiltSpinBox->setMaximum(TILT_MAX_DEG);
    ui->PanLocationLabel->setText(QString::number(panUnitsToDegrees(Pan)));
    ui->TiltLocationLabel->setText(QString::number(tiltUnitsToDegrees(Tilt)));
    enableUI();
    ui->PanHeadingLabel->setText(QString::number(panHeading));
    ui->TiltHeadingLabel->setText(QString::number(tiltHeading));

    client->gotMessage(data, senderIP, senderPort);
}

void MainWindow::disableUI(){
    ui->HomePB->setDisabled(true);
    ui->StopPB->setDisabled(true);
    ui->PanSpinBox->setDisabled(true);
    ui->TiltSpinBox->setDisabled(true);
    ui->PanSubmitPB->setDisabled(true);
    ui->TiltSubmitPB->setDisabled(true);
    ui->PanHeadingPB->setDisabled(true);
    ui->TiltHeadingPB->setDisabled(true);
    ui->PanHeadingSB->setDisabled(true);
    ui->TiltHeadingSB->setDisabled(true);
    ui->NotConnectedWidget->show();
    ui->PanHeadingLabel->setText("N/A");
    ui->TiltHeadingLabel->setText("N/A");
    ui->PanLocationLabel->setText("N/A");
    ui->TiltLocationLabel->setText("N/A");
}

void MainWindow::on_PanSubmitPB_clicked()
{
    int deg = ui->PanSpinBox->value();
    qDebug() << "pan degree:" << deg;
    setPan(deg);
}

void MainWindow::on_TiltSubmitPB_clicked()
{
    int deg = ui->TiltSpinBox->value();
    setTilt(deg);
}


void MainWindow::on_HomePB_clicked()
{
    goHome();
}

void MainWindow::on_StopPB_clicked(){
    stop();
}

void MainWindow::enableUI(){
    ui->HomePB->setDisabled(false);    // send the command to the ptu
    ui->StopPB->setDisabled(false);
    ui->PanSpinBox->setDisabled(false);
    ui->TiltSpinBox->setDisabled(false);
    ui->PanSubmitPB->setDisabled(false);
    ui->TiltSubmitPB->setDisabled(false);
    ui->PanHeadingSB->setDisabled(false);
    ui->TiltHeadingSB->setDisabled(false);
    ui->PanHeadingPB->setDisabled(false);
    ui->TiltHeadingPB->setDisabled(false);
    ui->NotConnectedWidget->hide();
}

int MainWindow::panUnitsToDegrees(int units) const {
    double degrees = units * panDegreesPerUnit;
    degrees += panHeading;
    if (degrees > PAN_MAX_DEG) degrees = PAN_MAX_DEG;
    if (degrees < PAN_MIN_DEG) degrees = PAN_MIN_DEG;
    return static_cast<int>(degrees);
}

int MainWindow::tiltUnitsToDegrees(int units) const {
    double degrees = units * tiltDegreesPerUnit;
    degrees += tiltHeading;
    if (degrees > TILT_MAX_DEG) degrees = TILT_MAX_DEG;
    if (degrees < TILT_MIN_DEG) degrees = TILT_MIN_DEG;
    return static_cast<int>(degrees);
}

void MainWindow::sendCommand(ptu::PTUCommand &command){
    QByteArray buffer(command.ByteSizeLong(), 0);
    if (!command.SerializeToArray(buffer.data(), buffer.size())){
        qWarning() << "Failed to seralize PTUCommand!";
        return;
    }
    client->sendCommand(buffer);
}

void MainWindow::setPan(int degrees){
    int newPos;
    int units;
    newPos = degrees - panHeading;
    newPos = (newPos + 180) % 360;
    if (newPos < 0){
        newPos += 360;
    }
    newPos -= 180;
    newPos = std::max(PAN_MIN_DEG, std::min(PAN_MAX_DEG, newPos));

    if (newPos >= 0){
        units = qCeil(newPos / panDegreesPerUnit);
    }else{
        units = qFloor(newPos / panDegreesPerUnit);
    }
    ptu::PTUCommand command;
    command.set_command(ptu::PTUType::SET_PAN);
    command.set_value(units);
    sendCommand(command);
}

void MainWindow::setTilt(int degrees){
    int newPos;
    int units;
    newPos = degrees - tiltHeading;
    newPos = (newPos + 180) % 360;
    if (newPos < 0){
        newPos += 360;
    }
    newPos -= 180;
    newPos = std::max(TILT_MIN_DEG, std::min(TILT_MAX_DEG, newPos));

    if (newPos >= 0){
        units = qCeil(newPos / tiltDegreesPerUnit);
    } else {
        units = qFloor(newPos / tiltDegreesPerUnit);
    }

    ptu::PTUCommand command;
    command.set_command(ptu::PTUType::SET_TILT);
    command.set_value(units);
    sendCommand(command);
}

void MainWindow::goHome(){
    ptu::PTUCommand command;
    command.set_command(ptu::PTUType::HOME);
    command.set_value(0);
    sendCommand(command);
}

void MainWindow::stop(){
    ptu::PTUCommand command;
    command.set_command(ptu::PTUType::STOP);
    command.set_value(0);
    sendCommand(command);
}




void MainWindow::on_PanHeadingPB_clicked()
{
    int heading = ui->PanHeadingSB->value();
    ptu::PTUCommand command;
    command.set_command(ptu::PTUType::SET_PAN_HEADING);
    command.set_value(heading);
    sendCommand(command);
}


void MainWindow::on_TiltHeadingPB_clicked()
{
    int heading = ui->TiltHeadingSB->value();
    ptu::PTUCommand command;
    command.set_command(ptu::PTUType::SET_TILT_HEADING);
    command.set_value(heading);
    sendCommand(command);
}

