#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QString>
#include <QObject>
#include <QSerialPort>
#include <QtNetwork/QUdpSocket>
#include <QNetworkDatagram>
#include <QTimer>

// on creation wait for a message then get ip and port from message, thats how we know
// who to send the commands to. Until message appears, have every button greyed out

// this class will send commands to the server on PTUServer.
class UdpClient : public QObject {
    Q_OBJECT
public:
    explicit UdpClient(QObject* parent = nullptr);

    void sendCommand(QByteArray&);
    void gotMessage(const QByteArray &, const QHostAddress &, quint16);

private:
    QUdpSocket *clientSocket;
    QHostAddress IP;
    quint16 port;
    bool haveReceivedMessage;
};

#endif // UDPCLIENT_H
