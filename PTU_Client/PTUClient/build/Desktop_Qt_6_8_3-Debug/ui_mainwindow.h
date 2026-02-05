/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *NotConnectedWidget;
    QVBoxLayout *verticalLayout_12;
    QLabel *NotConnectedLabel;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_9;
    QPushButton *HomePB;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_2;
    QPushButton *StopPB;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QSpinBox *PanHeadingSB;
    QPushButton *PanHeadingPB;
    QLabel *label;
    QSpinBox *PanSpinBox;
    QPushButton *PanSubmitPB;
    QSpacerItem *verticalSpacer;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QSpinBox *TiltHeadingSB;
    QPushButton *TiltHeadingPB;
    QLabel *label_2;
    QSpinBox *TiltSpinBox;
    QPushButton *TiltSubmitPB;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_7;
    QLabel *PanHeadingLabel;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_5;
    QLabel *PanLocationLabel;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_3;
    QLabel *TiltLocationLabel;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_9;
    QLabel *TiltHeadingLabel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(745, 534);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        NotConnectedWidget = new QWidget(widget_4);
        NotConnectedWidget->setObjectName("NotConnectedWidget");
        verticalLayout_12 = new QVBoxLayout(NotConnectedWidget);
        verticalLayout_12->setObjectName("verticalLayout_12");
        NotConnectedLabel = new QLabel(NotConnectedWidget);
        NotConnectedLabel->setObjectName("NotConnectedLabel");
        NotConnectedLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_12->addWidget(NotConnectedLabel);


        verticalLayout_3->addWidget(NotConnectedWidget);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName("widget_5");
        widget_5->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setObjectName("verticalLayout_4");
        frame_10 = new QFrame(widget_5);
        frame_10->setObjectName("frame_10");
        frame_10->setAutoFillBackground(false);
        frame_10->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(frame_10);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        widget_11 = new QWidget(frame_10);
        widget_11->setObjectName("widget_11");
        widget_11->setAutoFillBackground(false);
        verticalLayout_9 = new QVBoxLayout(widget_11);
        verticalLayout_9->setObjectName("verticalLayout_9");
        HomePB = new QPushButton(widget_11);
        HomePB->setObjectName("HomePB");

        verticalLayout_9->addWidget(HomePB);


        horizontalLayout_4->addWidget(widget_11);

        widget_12 = new QWidget(frame_10);
        widget_12->setObjectName("widget_12");
        widget_12->setAutoFillBackground(false);
        verticalLayout_2 = new QVBoxLayout(widget_12);
        verticalLayout_2->setObjectName("verticalLayout_2");
        StopPB = new QPushButton(widget_12);
        StopPB->setObjectName("StopPB");
        StopPB->setAutoFillBackground(false);

        verticalLayout_2->addWidget(StopPB);


        horizontalLayout_4->addWidget(widget_12);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_4->addWidget(frame_10);

        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        PanHeadingSB = new QSpinBox(widget);
        PanHeadingSB->setObjectName("PanHeadingSB");

        verticalLayout->addWidget(PanHeadingSB);

        PanHeadingPB = new QPushButton(widget);
        PanHeadingPB->setObjectName("PanHeadingPB");

        verticalLayout->addWidget(PanHeadingPB);

        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        PanSpinBox = new QSpinBox(widget);
        PanSpinBox->setObjectName("PanSpinBox");

        verticalLayout->addWidget(PanSpinBox);

        PanSubmitPB = new QPushButton(widget);
        PanSubmitPB->setObjectName("PanSubmitPB");

        verticalLayout->addWidget(PanSubmitPB);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName("widget_6");
        verticalLayout_5 = new QVBoxLayout(widget_6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_6 = new QLabel(widget_6);
        label_6->setObjectName("label_6");

        verticalLayout_5->addWidget(label_6);

        TiltHeadingSB = new QSpinBox(widget_6);
        TiltHeadingSB->setObjectName("TiltHeadingSB");

        verticalLayout_5->addWidget(TiltHeadingSB);

        TiltHeadingPB = new QPushButton(widget_6);
        TiltHeadingPB->setObjectName("TiltHeadingPB");

        verticalLayout_5->addWidget(TiltHeadingPB);

        label_2 = new QLabel(widget_6);
        label_2->setObjectName("label_2");

        verticalLayout_5->addWidget(label_2);

        TiltSpinBox = new QSpinBox(widget_6);
        TiltSpinBox->setObjectName("TiltSpinBox");

        verticalLayout_5->addWidget(TiltSpinBox);

        TiltSubmitPB = new QPushButton(widget_6);
        TiltSubmitPB->setObjectName("TiltSubmitPB");

        verticalLayout_5->addWidget(TiltSubmitPB);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(widget_6);


        verticalLayout_4->addWidget(widget_2);


        verticalLayout_3->addWidget(widget_5);

        widget_7 = new QWidget(widget_4);
        widget_7->setObjectName("widget_7");
        horizontalLayout_3 = new QHBoxLayout(widget_7);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        frame = new QFrame(widget_7);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_10 = new QVBoxLayout(frame);
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");

        verticalLayout_10->addWidget(label_7);

        PanHeadingLabel = new QLabel(frame);
        PanHeadingLabel->setObjectName("PanHeadingLabel");
        PanHeadingLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(PanHeadingLabel);


        horizontalLayout_3->addWidget(frame);

        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName("widget_9");
        verticalLayout_8 = new QVBoxLayout(widget_9);
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_5 = new QLabel(widget_9);
        label_5->setObjectName("label_5");

        verticalLayout_8->addWidget(label_5);

        PanLocationLabel = new QLabel(widget_9);
        PanLocationLabel->setObjectName("PanLocationLabel");
        PanLocationLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_8->addWidget(PanLocationLabel);


        horizontalLayout_3->addWidget(widget_9);

        widget_8 = new QWidget(widget_7);
        widget_8->setObjectName("widget_8");
        verticalLayout_7 = new QVBoxLayout(widget_8);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_3 = new QLabel(widget_8);
        label_3->setObjectName("label_3");

        verticalLayout_7->addWidget(label_3);

        TiltLocationLabel = new QLabel(widget_8);
        TiltLocationLabel->setObjectName("TiltLocationLabel");
        TiltLocationLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_7->addWidget(TiltLocationLabel);


        horizontalLayout_3->addWidget(widget_8);

        frame_2 = new QFrame(widget_7);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_2);
        verticalLayout_11->setObjectName("verticalLayout_11");
        label_9 = new QLabel(frame_2);
        label_9->setObjectName("label_9");

        verticalLayout_11->addWidget(label_9);

        TiltHeadingLabel = new QLabel(frame_2);
        TiltHeadingLabel->setObjectName("TiltHeadingLabel");
        TiltHeadingLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_11->addWidget(TiltHeadingLabel);


        horizontalLayout_3->addWidget(frame_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget_7);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_2->addWidget(widget_4);


        verticalLayout_6->addWidget(widget_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 745, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        NotConnectedLabel->setText(QCoreApplication::translate("MainWindow", "Not Connected!", nullptr));
        HomePB->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        StopPB->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Pan Heading - degrees", nullptr));
        PanHeadingPB->setText(QCoreApplication::translate("MainWindow", "Submit Pan Heading", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Pan - degrees", nullptr));
        PanSubmitPB->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Tilt Heading - degrees", nullptr));
        TiltHeadingPB->setText(QCoreApplication::translate("MainWindow", "Submit Tilt Heading", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Tilt - degrees", nullptr));
        TiltSubmitPB->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Pan Heading", nullptr));
        PanHeadingLabel->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Pan Location:", nullptr));
        PanLocationLabel->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Tilt Location:", nullptr));
        TiltLocationLabel->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Tilt Heading", nullptr));
        TiltHeadingLabel->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
