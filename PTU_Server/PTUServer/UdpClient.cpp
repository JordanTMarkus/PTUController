#include "UdpClient.h"


/*
 * Basic flow:
 *
 * On startup, we open the config.ini file and set all variables with the config information. This information is PTU related information, and IP and port of the computer we want to send data to.
 * We create a UDP socket and a timer that times out every 5 seconds. Every time the timer times out, our UdpClient::onTimeout function gets called.
 * When called, we create a JSON object and store all needed information inside, then we use the socket to send that data to the other computer.
 *
 * onPanChanged, onTiltChanged, onPanHeadingChanged, onTiltHeadingChanged are all slots that are called by signals in UdpServer
 *
 *
 *
 */

UdpClient::UdpClient(QObject *parent) : QObject(parent){
    clientSocket = new QUdpSocket(this);
}

void UdpClient::sendMessage(QByteArray msg, QString IP, quint16 port){
    clientSocket->writeDatagram(msg, QHostAddress(IP), port);
}
