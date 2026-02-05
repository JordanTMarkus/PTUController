#ifndef UDPSERVER_H
#define UDPSERVER_H

/*
udpserver will be responsible for getting commands from GUI and sending
it to PTU
*/

#include <QString>
#include <QObject>
#include <QSerialPort>
#include <QSettings>
#include <QtNetwork/QUdpSocket>
#include <QNetworkDatagram>
#include "serial.h"

class UdpServer : public QObject {
    Q_OBJECT
public:
    explicit UdpServer(quint16 udpPort, QObject *parent = nullptr);
    void onSocketReadyRead();
    void refreshConfig();
signals:
    void ptuSettingChanged();
    void panHasChanged(int);
    void tiltHasChanged(int);
    void panHeadingChanged(int);
    void tiltHeadingChanged(int);
    void sendSerialCommand(QString);
    void processDatagram(QNetworkDatagram &);
private:
    QUdpSocket *serverSocket;
    quint16 udpPort;
    double panDegreesPerUnit;
    double tiltDegreesPerUnit;
};

#endif // UDPSERVER_H
