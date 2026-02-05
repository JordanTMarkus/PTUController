#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include <QObject>
#include <QSerialPort>
#include <QSettings>
#include <QtNetwork/QUdpSocket>
#include <QNetworkDatagram>
#include <QTimer>
#include "serial.h"
#include "UdpServer.h"
#include "UdpClient.h"

class Manager : public QObject {
    Q_OBJECT
public:
    explicit Manager(QObject* parent = nullptr);

public slots:
    void onTimeout();
    void processServerDatagram(QNetworkDatagram&);
    void panChanged(int);
    void tiltChanged(int);

private:
    QString IP;
    quint16 port;
    QTimer *timer;
    int serverPort = 7755;
    int pan = 0;
    int tilt = 0;
    int panSpeed = 30;
    int tiltSpeed = 30;
    int panHeading = 0;
    int tiltHeading = 0;
    int panMinDeg = -167;
    int panMaxDeg = 167;
    int tiltMinDeg = -90;
    int tiltMaxDeg = 30;
    double panDPR = 0.0300024;
    double tiltDPR = 0.0150012;
    QString comPort;
    int baudRate;
    UdpClient *client;
    UdpServer *server;
    Serial *serial;
};



#endif // MANAGER_H
