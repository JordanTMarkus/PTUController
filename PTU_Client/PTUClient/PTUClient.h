#ifndef PTUCLIENT_H
#define PTUCLIENT_H

#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <QNetworkDatagram>
#include <QSettings>
#include <QByteArray>
#include <QQueue>
#include "UdpServer.h"
#include "UdpClient.h"

class PTUClient : public QObject{
    Q_OBJECT

public:
    explicit PTUClient(QObject *parent = nullptr);


};

#endif // PTUCLIENT_H
