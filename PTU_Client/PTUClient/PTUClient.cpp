#include "PTUClient.h"

PTUClient::PTUClient(QObject *parent) : QObject(parent){
    server = new UdpServer(this);
    client = new UdpClient(this);

    connect (server, &UdpServer::datagramReceived, client, &UdpClient::gotMessage);
    connect(server, &UdpServer::sendClientData, this, &PTUClient::updatePTUInfo);
}

void PTUClient::updatePTUInfo(int panmin, int panmax, int tiltmin, int tiltmax, double pandpu, double tiltdpu, int Pan, int Tilt){
    this->PAN_MIN_DEG = panmin;
    this->PAN_MAX_DEG = panmax;
    this->TILT_MIN_DEG = tiltmin;
    this->TILT_MAX_DEG = tiltmax;
    this->panDegreesPerUnit = pandpu;
    this->tiltDegreesPerUnit = tiltdpu;
    this->PanLocation = Pan;
    this->TiltLocation = Tilt;
    emit changeMinMax();
}

void PTUClient::sendCommand(QString &command){
    client->sendCommand(command);
}

void PTUClient::setPan(int degrees){
    qDebug() << "Entered setPan function";
    qDebug() << "DPR for pan is: " << panDegreesPerUnit;
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
    QString cmd = "pp" + QString::number(units) + "\n";
    qDebug() << "Sending this command:" << cmd;
    sendCommand(cmd);
}

void PTUClient::setTilt(int degrees){
    int newPos;
    int units;
    newPos = degrees - panHeading;
    newPos = (newPos + 180) % 360;
    if (newPos < 0){
        newPos += 360;
    }
    newPos -= 180;
    newPos = std::max(TILT_MIN_DEG, std::min(PAN_MAX_DEG, newPos));

    if (newPos >= 0){
        units = qCeil(newPos / tiltDegreesPerUnit);
    } else {
        units = qFloor(newPos / tiltDegreesPerUnit);
    }
    QString cmd = "tp" + QString::number(units) + "\n";
    sendCommand(cmd);
}

void PTUClient::goHome(){
    QString cmd = "pp0\ntp0\n";
    sendCommand(cmd);
}

void PTUClient::stop(){
    QString cmd = "H\n";
    sendCommand(cmd);
}
