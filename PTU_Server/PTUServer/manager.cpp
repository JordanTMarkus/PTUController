#include "manager.h"
#include "UdpClient.h"
#include "UdpServer.h"
#include "serial.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "protoObjects/ptu.pb.h"
#include <google/protobuf/stubs/common.h>

Manager::Manager(QObject *parent) : QObject(parent){
    QSettings qsettings("/home/labuser/Desktop/config.ini", QSettings::IniFormat);

    // IP and port of other computer
    qsettings.beginGroup("guiudpsocket");
    IP = qsettings.value("ip", "10.0.8.131").toString();
    port = qsettings.value("port", 9000).toUInt();
    qsettings.endGroup();

    // serverPort will be put in JSON object so that the other computer knows which port to send commands to
    qsettings.beginGroup("udpsocket");
    serverPort = qsettings.value("port", 7755).toInt();
    qsettings.endGroup();

    // PTU information that the GUI needs
    qsettings.beginGroup("ptuinfo");
    pan = qsettings.value("pan",0).toInt();
    tilt = qsettings.value("tilt",0).toInt();
    panSpeed = qsettings.value("panspeed",30).toInt();
    tiltSpeed = qsettings.value("tiltspeed",30).toInt();
    panHeading = qsettings.value("panheading",0).toInt();
    tiltHeading = qsettings.value("tiltheading",0).toInt();
    panMinDeg = qsettings.value("panmindeg",-167).toInt();
    panMaxDeg = qsettings.value("panmaxdeg",167).toInt();
    tiltMinDeg = qsettings.value("tiltmindeg",-90).toInt();
    tiltMaxDeg = qsettings.value("tiltmaxdeg",30).toInt();
    panDPR = qsettings.value("pandegreesperunit",0.0300024).toDouble();
    tiltDPR = qsettings.value("tiltdegreesperunit",0.0150012).toDouble();
    qsettings.endGroup();

    qsettings.beginGroup("ptusettings");
    comPort = qsettings.value("com").toString();
    baudRate = qsettings.value("baudrate", 9600).toInt();
    qsettings.endGroup();

    qDebug() << "\nClient Info " << IP << ", " << port;

    client = new UdpClient(this);
    server = new UdpServer(serverPort, this);
    serial = new Serial(comPort, baudRate, this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Manager::onTimeout);
    connect(server, &UdpServer::processDatagram, this, &Manager::processServerDatagram);
    connect(serial, &Serial::panChanged, this, &Manager::panChanged);
    connect(serial, &Serial::tiltChanged, this, &Manager::tiltChanged);

    // 5 seconds
    timer->start(5000);
}

void Manager::onTimeout()
{
    // protobuf
    ptu::PTUStatus status;
    status.set_pan_units(pan);
    status.set_tilt_units(tilt);
    status.set_pan_speed(panSpeed);
    status.set_tilt_speed(tiltSpeed);
    status.set_pan_degrees_per_unit(panDPR);
    status.set_tilt_degrees_per_unit(tiltDPR);
    status.set_pan_heading(panHeading);
    status.set_tilt_heading(tiltHeading);
    status.set_pan_min_deg(panMinDeg);
    status.set_pan_max_deg(panMaxDeg);
    status.set_tilt_min_deg(tiltMinDeg);
    status.set_tilt_max_deg(tiltMaxDeg);
    status.set_port(serverPort);

    std::string buffer;
    status.SerializeToString(&buffer);

    QByteArray payload(buffer.data(), static_cast<int>(buffer.size()));

    client->sendMessage(payload, IP, port);

}

void Manager::panChanged(int pan){
    this->pan = pan;
}

void Manager::tiltChanged(int tilt){
    this->tilt = tilt;
}

void Manager::processServerDatagram(QNetworkDatagram &datagram){
    QByteArray data = datagram.data();

    ptu::PTUCommand status;

    if (!status.ParseFromArray(data.constData(), data.size())){
        qWarning() << "Failed to parse PTUCommand!";
        return;
    }

    switch (status.command()) {
    case ptu::PTUType::HOME:
        serial->sendCommand("pp0\n");
        serial->sendCommand("tp0\n");
        break;
    case ptu::PTUType::STOP:
        serial->sendCommand("h\n");
        break;
    case ptu::PTUType::SET_PAN:
        serial->sendCommand("pp" + QString::number(status.value()) + "\n");
        break;
    case ptu::PTUType::SET_TILT:
        serial->sendCommand("tp" + QString::number(status.value()) + "\n");
        break;
    case ptu::PTUType::SET_PAN_HEADING:
        this->panHeading = status.value();
        break;
    case ptu::PTUType::SET_TILT_HEADING:
        this->tiltHeading = status.value();
        break;
    default:
        qDebug() << "Unknown PTU command received";
        break;
    }
}

