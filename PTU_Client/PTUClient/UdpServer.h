#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QString>
#include <QObject>
#include <QSerialPort>
#include <QtNetwork/QUdpSocket>
#include <QNetworkDatagram>

class UdpServer : public QObject {
    Q_OBJECT
public:
    explicit UdpServer(QObject *parent = nullptr);

signals:
    void datagramReceived(const QByteArray &data, QHostAddress &senderIP, quint16 senderPort);
    void sendClientData(int PanMin, int PanMax, int TiltMin, int TiltMax, double, double, int, int, int, int);
    void processDatagram(QNetworkDatagram&);
private slots:
    void onReadyRead();

private:
    QUdpSocket *serverSocket;
    quint16 port;
};

#endif // UDPSERVER_H
