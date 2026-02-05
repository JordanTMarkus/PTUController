QT = core serialport network

# Include your generated protobuf headers and the protobuf source headers
INCLUDEPATH += /home/labuser/Git/protobuf/src \
                $$PWD/protoObjects

QMAKE_CXXFLAGS += -isystem /home/labuser/Git/protobuf/src

SOURCES += \
    UdpClient.cpp \
    UdpServer.cpp \
    main.cpp \
    manager.cpp \
    protoObjects/ptu.pb.cc \
    serial.cpp

HEADERS += \
    UdpClient.h \
    UdpServer.h \
    manager.h \
    protoObjects/ptu.pb.h \
    serial.h

DISTFILES += \
    proto/ptu.proto

# Link your built protobuf library
#LIBS += -L/home/labuser/Git/protobuf/src/.libs -lprotobuf -lpthread -lz
LIBS += -L/usr/local/lib -lprotobuf -lpthread -lz
