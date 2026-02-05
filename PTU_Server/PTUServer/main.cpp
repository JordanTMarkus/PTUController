#include <QCoreApplication>
#include "manager.h"
#include <google/protobuf/any.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GOOGLE_PROTOBUF_VERIFY_VERSION;

    /*
     * This is the application that will run on the computer that is connected to the Pan-Tilt Unit.
     *
     * Basic flow:
     * On start, program will instantiate variables from a .ini config file.
     * These variabels are PTU specific data, ip of the computer that will get sent the data, and ports that will host the UDP sockets.
     * Every 5 seconds UdpClient will attempt to send all PTU information and IP and port of machine to the other computer.
     * UdpServer hosts a UDP socket on a specific port found in the config file, and waits for a response from any IPv4 ip.
     * Any response will get parsed and sent to serial.cpp where it will get sent to the PTU as a command.
     * serial.cpp will get any response from the PTU to check if it was a movement command, and if so will emit a signal to change the value in memory.
     * The next time the PTU information is sent to the other computer, it will have the updated values.
     *
     */
    Manager manager;



    return a.exec();

    google::protobuf::ShutdownProtobufLibrary();
}
