#include "UdpServer.h"
#include "protoObjects/ptu.pb.h"
/*
 * Basic flow:
 *
 * On startup, this program creates a Serial object, a UDP socket with the port found in config, and connections to the slots in UdpClient.
 * We constantly wait for data to be received, and when we get data, onSocketReadyRead is called. It goes through the pending datagrams, and
 * sends it to the processDatagram function as a QNetworkDatagram. This function figures out if its a move command or heading change command.
 * If it't a movement command we just send it to the serial object using its sendCommand function, if it's a heading command we grab the value,
 * and emit a signal that has that value inside.
 *
 */

UdpServer::UdpServer(quint16 port, QObject *parent) : QObject(parent), udpPort(port){

    serverSocket = new QUdpSocket(this);
    // UDP socket hosted on the port the variable udpPort holds, and it can receive data from any IPv4 ip.
    serverSocket->bind(QHostAddress::AnyIPv4, udpPort);
    connect(serverSocket, &QUdpSocket::readyRead, this, &UdpServer::onSocketReadyRead);
}

// Gets called whenever serverSocket gets a datagram
void UdpServer::onSocketReadyRead(){
    qDebug() << "Received Datagram!";
    while (serverSocket->hasPendingDatagrams()){
        QNetworkDatagram datagram = serverSocket->receiveDatagram();
        emit processDatagram(datagram);
    }
}
