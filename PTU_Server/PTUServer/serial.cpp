#include "serial.h"

/*
 * Basic flow:
 *
 * On startup, we grab com port and baudrate of the PTU from the config file. We make an attempt to connect to the PTU with that info.
 * Serial::sendCommand will get called by UdpServer and a command will be passed in. Serial.cpp will then send that command to the PTU
 * Any response from the PTU will get handled by the Serial::onSerialReadyRead function. This function reads from the serial connection,
 * making sure each line is correct, then sends it to the Serial::handleResponse function. This function checks if the command failed or not,
 * and makes sure that if it was a movement command, it updates the variables inside the UdpClient with the updated values by emiting a signal.
 *
 */

Serial::Serial(QString comPort, int baudRate, QObject *parent) : QObject(parent), comPort(comPort), baudRate(baudRate){

    serial.setPortName(comPort);
    serial.setBaudRate(baudRate);

    if (!serial.open(QIODevice::ReadWrite)){
        qDebug() << "Couldn't connect to device";
    }

    if (serial.isOpen()){
        qDebug() << "Serial is connected to PTU!";
    }

    connect(&serial, &QSerialPort::readyRead, this, &Serial::onSerialReadyRead);
}

void Serial::sendCommand(const QString& message){
    if (!serial.isOpen()){
        qDebug() << "No connection to device";
        return;
    }
    qDebug() << "Command went through";
    serial.write(message.toLatin1());
}

void Serial::onSerialReadyRead(){
    static QByteArray buffer;
    buffer += serial.readAll();

    if (!buffer.contains('\r')) return;

    QList<QByteArray> lines = buffer.split('\r');
    buffer = lines.takeLast();

    for (const QByteArray& line : lines){
        handleResponse(QString::fromLatin1(line).trimmed());
    }
}

void Serial::handleResponse(QString message)
{
    if (message.isEmpty())
        return;

    if (message.startsWith('!')) {
        emit commandFailure();
        return;
    }

    if (message == "*") {
        emit commandSuccess();
        return;
    }

    if (message.startsWith("pp")) {
        int pan;
        QString number = "";
        bool isNegative = false;
        for (int i = 0; i < message.length(); i++){
            if (message[i] >= '0' && message[i] <= '9'){
                number += message[i];
            }
            if (message[i] == '-'){
                isNegative = true;
            }
        }
        if (isNegative){
            pan = -1 * number.toInt();
        }
        else{
            pan = number.toInt();
        }
        qDebug() << "PAN EMITTED: " + QString::number(pan);
        emit panChanged(pan);
        return;
    }

    if (message.startsWith("tp")) {
        int tilt;
        QString number = "";
        bool isNegative = false;
        for (int i = 0; i < message.length(); i++){
            if (message[i] >= '0' && message[i] <= '9'){
                number += message[i];
            }
            if (message[i] == '-'){
                isNegative = true;
            }
        }
        if (isNegative){
            tilt = -1 * number.toInt();
        }
        else{
            tilt = number.toInt();
        }
        qDebug() << "TILT EMITTED";
        emit tiltChanged(tilt);
        return;
    }

    qDebug() << "Unhandled PTU message:" << message;
}

