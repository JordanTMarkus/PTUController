#include "UdpClient.h"

/*
 * On startup we create a UDP socket. When the gotMessage slot is called from the UdpServer signal, we set the ip and port of the computer we want to send data to.
 * When sendCommand gets called from mainwindow.cpp, we take the command and call the writeDatagram method to send the command to the IP and port using the UDP socket we created.
 *
 */

UdpClient::UdpClient(QObject *parent) : QObject(parent){
    clientSocket = new QUdpSocket(this);
    haveReceivedMessage = false;
}

// slot gets called when a message is recieved, that way we can use the ip and port of the sender
void UdpClient::gotMessage(const QByteArray &data, const QHostAddress &ip, quint16 port){
    IP = ip;
    this->port = port;
    haveReceivedMessage = true;
}

void UdpClient::sendCommand(QByteArray &command){
    //qDebug() << "Sending cmd!";
    clientSocket->writeDatagram(command, IP, port);
    qDebug() << "Command was sent!";
}
