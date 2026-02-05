#ifndef UDPCLIENT_H
#define UDPCLIENT_H

/*
udpclient will be responsible for sending the entire ptuinfo group to
the server of the GUI from the config.ini.
*/

#include <QString>
#include <QObject>
#include <QSerialPort>
#include <QSettings>
#include <QtNetwork/QUdpSocket>
#include <QNetworkDatagram>
#include <QTimer>

class UdpClient : public QObject {
    Q_OBJECT
public:
    explicit UdpClient(QObject* parent = nullptr);

public slots:
    void sendMessage(QByteArray,QString, quint16);

private:
    QUdpSocket *clientSocket;
};




#endif // UDPCLIENT_H
