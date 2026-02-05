#ifndef SERIAL_H
#define SERIAL_H


#include <QString>
#include <QObject>
#include <QSerialPort>
#include <QSettings>
#include <QtNetwork/QUdpSocket>
#include <QNetworkDatagram>

class Serial : public QObject{
    Q_OBJECT
public:
    explicit Serial(QString, int, QObject *parent = nullptr);

    void sendCommand(const QString&);
    void onSerialReadyRead();
    void handleResponse(QString);
    void applyCommandToConfig(QString&);

signals:
    void commandSuccess();
    void commandFailure();
    void panChanged(int);
    void tiltChanged(int);
private:
    QSerialPort serial;
    QString comPort;
    int baudRate;
    QString lastCommandEcho;
};

#endif // SERIAL_H
