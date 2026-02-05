#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "PTUClient.h"
#include "protoObjects/ptu.pb.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void sendCommand(ptu::PTUCommand &);
    void setPan(int);
    void setTilt(int);
    void goHome();
    void stop();
    int panUnitsToDegrees(int) const;
    int tiltUnitsToDegrees(int) const;
    void enableUI();
    void disableUI();

    int PAN_MIN_DEG;
    int PAN_MAX_DEG;
    int TILT_MIN_DEG;
    int TILT_MAX_DEG;
    int panHeading = 0;
    int tiltHeading;
    double panDegreesPerUnit;
    double tiltDegreesPerUnit;
    int PanLocation = 0;
    int TiltLocation = 0;


private slots:

    void on_PanSubmitPB_clicked();

    void on_TiltSubmitPB_clicked();

    void on_HomePB_clicked();

    void on_StopPB_clicked();

    void on_PanHeadingPB_clicked();

    void on_TiltHeadingPB_clicked();

    void processDatagram(QNetworkDatagram);

private:
    Ui::MainWindow *ui;
    UdpServer *server;
    UdpClient *client;
    QTimer *heartbeatTimer;
};
#endif // MAINWINDOW_H
