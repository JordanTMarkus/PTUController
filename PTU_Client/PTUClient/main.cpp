#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>

/*
 * Basic flow of the program:
 *
 * On startup, a MainWindow object is created, upon the creation of this object, a UdpClient and UdpServer object are created. The program will sit idly until UdpServer gets sent a JSON message. This
 * JSON message will have PTU information and information about the IP and port of the sending computer. UdpServer will then get the values from the JSON message, and emit signals. The first signal is
 * gotMessage, and the slot for it is in UdpClient. When this is called the IP and port of the senders running UDP Server is sent with it, so that UdpClient can get ready to send commands to it. The second
 * signal takes needed information from the message, and sends it to updatePtuInfo function inside the mainwindow file. This function updates all GUI components with the correct information, and sets the variables
 * needed for degrees to PTU units calculations. The program then waits for user input, and once received, a command is made to do what the user wants, whether its to pan the ptu 50 degrees, or change the tilt heading.
 * The command is created inside mainwindow, then sent to UdpClient, then sent to the IP and port of the server on the computer that is hosting the PTU.
 *
 *
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleFile(":/styles.qss");
    if (styleFile.open(QFile::ReadOnly | QFile::Text)){
        QTextStream stream(&styleFile);
        a.setStyleSheet(stream.readAll());
        styleFile.close();
    } else {
        qDebug() << "Could not load style.qss";
    }

    MainWindow w;
    w.show();
    return a.exec();
}
