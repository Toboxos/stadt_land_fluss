#-------------------------------------------------
#
# Project created by QtCreator 2019-05-19T13:38:33
#
#-------------------------------------------------

QT       += core gui \
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StadtLandFluss
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += PORT=1234

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    Network/Packets/endroundpacket.cpp \
    Network/Packets/startcountdownpacket.cpp \
    Network/serversocket.cpp \
    Network/clientsocket.cpp \
    Network/Packets/packet.cpp \
    Network/Packets/playerjoinpacket.cpp \
    Network/Packets/endgamepacket.cpp \
    Network/Packets/gamesettingspacket.cpp \
    Network/Packets/playerfinishedpacket.cpp \
    Network/Packets/playerlistpacket.cpp \
    Network/Packets/roundstartpacket.cpp \
    Network/Packets/sendanswerspacket.cpp \
    Network/Packets/sendpointspacket.cpp \
    antworten.cpp \
        clientipeingabe.cpp \
    clientlogic.cpp \
    einwand.cpp \
        hauptspielfenster.cpp \
        hostspieleinstellungen.cpp \
        kategorieeingabe.cpp \
        main.cpp \
    punkte.cpp \
        spieleinstellungen.cpp \
        spieler.cpp \
        spielerwarteraum.cpp \
        spielstart.cpp \
        CLogik.cpp \
        timer.cpp


HEADERS += \
    Network/Packets/endroundpacket.h \
    Network/Packets/startcountdownpacket.h \
    Network/serversocket.h \
    Network/clientsocket.h \
    Network/Packets/packet.h \
    Network/Packets/playerjoinpacket.h \
    Network/Packets/endgamepacket.h \
    Network/Packets/gamesettingspacket.h \
    Network/Packets/playerfinishedpacket.h \
    Network/Packets/playerlistpacket.h \
    Network/Packets/roundstartpacket.h \
    Network/Packets/sendanswerspacket.h \
    Network/Packets/sendpointspacket.h \
    antworten.h \
        clientipeingabe.h \
    clientlogic.h \
    einwand.h \
        hauptspielfenster.h \
        hostspieleinstellungen.h \
        kategorieeingabe.h \
    punkte.h \
        spieleinstellungen.h \
        spieler.h \
        spielerliste.h \
        spielerwarteraum.h \
        spielstart.h \
        CLogik.h \
        timer.h

FORMS += \
        clientipeingabe.ui \
        einwand.ui \
        hauptspielfenster.ui \
        hostspieleinstellungen.ui \
        kategorieeingabe.ui \
        spielerwarteraum.ui \
        spielstart.ui

PacketTests {
    TARGET = PacketTest
    QT += testlib

    SOURCES -=  main.cpp

    SOURCES +=  UnitTests/packettests.cpp \
                UnitTests/Tests/gamesettingspackettest.cpp \
                UnitTests/Tests/roundstartpackettest.cpp
    HEADERS +=  UnitTests/Tests/test.h \
                UnitTests/Tests/gamesettingspackettest.h \
                UnitTests/Tests/roundstartpackettest.h
}

ServerLogicTest {
    TARGET = ServerLogicTest
    QT += testlib
    DEFINES +=  UNIT_TEST

    SOURCES -=  main.cpp \
                Network/serversocket.cpp
    HEADERS -=  Network/serversocket.h

    SOURCES +=  UnitTests/serverlogictest.cpp \
                UnitTests/mock_classes/mockserversocket.cpp \
                UnitTests/Tests/jointest.cpp
    HEADERS +=  UnitTests/mock_classes/mockserversocket.h \
                UnitTests/Tests/jointest.h
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
