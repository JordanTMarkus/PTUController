QT       += core gui network serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Sources
SOURCES += \
    UdpClient.cpp \
    UdpServer.cpp \
    main.cpp \
    mainwindow.cpp \
    protoObjects/ptu.pb.cc

# Headers
HEADERS += \
    UdpClient.h \
    UdpServer.h \
    mainwindow.h \
    protoObjects/ptu.pb.h

FORMS += \
    mainwindow.ui

# Include path for the generated protobuf headers
INCLUDEPATH += $$PWD/protoObjects
# System protobuf headers should already be in /usr/local/include

# Link against system-installed protobuf library
LIBS += -L/usr/local/lib -lprotobuf -lpthread -lz

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Resources and extra files
RESOURCES += \
    styles.qrc

DISTFILES += \
    styles.qss
