#include "UdpServer.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "protoObjects/ptu.pb.h"

/*
 * UdpServer creates a UDP socket and sets it to receive messages from any IPv4 ip on a specific port. Any message received will call the UdpServer::onReadyRead function.
 * The onReadyRead function goes through all socket datagrams and sends them to processDatagram where it will get parsed as a JSON object. We then grab all data we need and emit signals
 * to send the data to other files that need it. the datagramReceived signal goes to UdpClient, and it updates the IP and port so that we are sending to the right location,
 * and sendClientData goes to mainwindow.cpp so we can update GUI info and update class variables.
 *
 */

UdpServer::UdpServer(QObject *parent) : QObject(parent){
    port = 9000;
    serverSocket = new QUdpSocket(this);
    serverSocket->bind(QHostAddress::AnyIPv4, port);
    connect(serverSocket, &QUdpSocket::readyRead, this, &UdpServer::onReadyRead);
}

void UdpServer::onReadyRead(){
    while (serverSocket->hasPendingDatagrams()){
        QNetworkDatagram datagram = serverSocket->receiveDatagram();
        emit processDatagram(datagram);
    }
}
