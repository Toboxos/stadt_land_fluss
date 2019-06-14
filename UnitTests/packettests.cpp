#include "packettests.h"

#include <QSignalSpy>

#include "UnitTests/Tests/gamesettingspackettest.h"
#include "UnitTests/Tests/roundstartpackettest.h"
#include "UnitTests/Tests/playerjoinpackettest.h"
#include "UnitTests/Tests/playerlistpackettest.h"
#include "UnitTests/Tests/endgamepackettest.h"
#include "UnitTests/Tests/playerfinishedpackettest.h"
#include "UnitTests/Tests/sendanswerspackettest.h"
#include "UnitTests/Tests/sendpointspackettest.h"

void PacketTests::testGameSettingsPacket() {
    // Create actual test object
    GameSettingsPacketTest test;

    // Spies signals
    QSignalSpy finishedSpy(&test, SIGNAL(finished()));
    QSignalSpy failSpy(&test, SIGNAL(failed(QString)));

    // QEventLoop blocks controll flow until the test emits the finished() signal
    // So the application will not quit until test is finished
    QEventLoop loop;
    connect(&test, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(&test, SIGNAL(failed(QString)), &loop, SLOT(quit()));

    // Run actual test
    test.run();

    // When finished signal not already was emitted loop will block until it is emitted
    if( finishedSpy.count() == 0 && failSpy.count() == 0 ) loop.exec();

    if( failSpy.count() > 0 ) {
        QFAIL(failSpy.at(0).at(0).toString().toUtf8().data());
    }
}

void PacketTests::testRoundStartPacket() {
    // Create actual test object
    RoundStartPacketTest test;

    // Spies signals
    QSignalSpy finishedSpy(&test, SIGNAL(finished()));
    QSignalSpy failSpy(&test, SIGNAL(failed(QString)));

    // QEventLoop blocks controll flow until the test emits the finished() signal
    // So the application will not quit until test is finished
    QEventLoop loop;
    connect(&test, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(&test, SIGNAL(failed(QString)), &loop, SLOT(quit()));

    // Run actual test
    test.run();

    // When finished signal not already was emitted loop will block until it is emitted
    if( finishedSpy.count() == 0 && failSpy.count() == 0 ) loop.exec();

    if( failSpy.count() > 0 ) {
        QFAIL(failSpy.at(0).at(0).toString().toUtf8().data());
    }
}

void PacketTests::testPlayerJoinPacket() {
    // Create actual test object
    PlayerJoinPacketTest test;

    // Spies signals
    QSignalSpy finishedSpy(&test, SIGNAL(finished()));
    QSignalSpy failSpy(&test, SIGNAL(failed(QString)));

    // QEventLoop blocks controll flow until the test emits the finished() signal
    // So the application will not quit until test is finished
    QEventLoop loop;
    connect(&test, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(&test, SIGNAL(failed(QString)), &loop, SLOT(quit()));

    // Run actual test
    test.run();

    // When finished signal not already was emitted loop will block until it is emitted
    if( finishedSpy.count() == 0 && failSpy.count() == 0 ) loop.exec();

    if( failSpy.count() > 0 ) {
        QFAIL(failSpy.at(0).at(0).toString().toUtf8().data());
    }
}

void PacketTests::testPlayerListPacket() {
    // Create actual test object
    PlayerListPacketTest test;

    // Spies signals
    QSignalSpy finishedSpy(&test, SIGNAL(finished()));
    QSignalSpy failSpy(&test, SIGNAL(failed(QString)));

    // QEventLoop blocks controll flow until the test emits the finished() signal
    // So the application will not quit until test is finished
    QEventLoop loop;
    connect(&test, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(&test, SIGNAL(failed(QString)), &loop, SLOT(quit()));

    // Run actual test
    test.run();

    // When finished signal not already was emitted loop will block until it is emitted
    if( finishedSpy.count() == 0 && failSpy.count() == 0 ) loop.exec();

    if( failSpy.count() > 0 ) {
        QFAIL(failSpy.at(0).at(0).toString().toUtf8().data());
    }
}

void PacketTests::testEndGamePacket() {
    // Create actual test object
    EndGamePacketTest test;

    // Spies signals
    QSignalSpy finishedSpy(&test, SIGNAL(finished()));
    QSignalSpy failSpy(&test, SIGNAL(failed(QString)));

    // QEventLoop blocks controll flow until the test emits the finished() signal
    // So the application will not quit until test is finished
    QEventLoop loop;
    connect(&test, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(&test, SIGNAL(failed(QString)), &loop, SLOT(quit()));

    // Run actual test
    test.run();

    // When finished signal not already was emitted loop will block until it is emitted
    if( finishedSpy.count() == 0 && failSpy.count() == 0 ) loop.exec();

    if( failSpy.count() > 0 ) {
        QFAIL(failSpy.at(0).at(0).toString().toUtf8().data());
    }
}

void PacketTests::testPlayerFinishedPacket() {
    // Create actual test object
    PlayerFinishedPacketTest test;

    // Spies signals
    QSignalSpy finishedSpy(&test, SIGNAL(finished()));
    QSignalSpy failSpy(&test, SIGNAL(failed(QString)));

    // QEventLoop blocks controll flow until the test emits the finished() signal
    // So the application will not quit until test is finished
    QEventLoop loop;
    connect(&test, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(&test, SIGNAL(failed(QString)), &loop, SLOT(quit()));

    // Run actual test
    test.run();

    // When finished signal not already was emitted loop will block until it is emitted
    if( finishedSpy.count() == 0 && failSpy.count() == 0 ) loop.exec();

    if( failSpy.count() > 0 ) {
        QFAIL(failSpy.at(0).at(0).toString().toUtf8().data());
    }
}

void PacketTests::testSendAnswersPacket() {
    // Create actual test object
    SendAnswersPacketTest test;

    // Spies signals
    QSignalSpy finishedSpy(&test, SIGNAL(finished()));
    QSignalSpy failSpy(&test, SIGNAL(failed(QString)));

    // QEventLoop blocks controll flow until the test emits the finished() signal
    // So the application will not quit until test is finished
    QEventLoop loop;
    connect(&test, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(&test, SIGNAL(failed(QString)), &loop, SLOT(quit()));

    // Run actual test
    test.run();

    // When finished signal not already was emitted loop will block until it is emitted
    if( finishedSpy.count() == 0 && failSpy.count() == 0 ) loop.exec();

    if( failSpy.count() > 0 ) {
        QFAIL(failSpy.at(0).at(0).toString().toUtf8().data());
    }
}

void PacketTests::testSendPointsPacket() {
    // Create actual test object
    SendPointsPacketTest test;

    // Spies signals
    QSignalSpy finishedSpy(&test, SIGNAL(finished()));
    QSignalSpy failSpy(&test, SIGNAL(failed(QString)));

    // QEventLoop blocks controll flow until the test emits the finished() signal
    // So the application will not quit until test is finished
    QEventLoop loop;
    connect(&test, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(&test, SIGNAL(failed(QString)), &loop, SLOT(quit()));

    // Run actual test
    test.run();

    // When finished signal not already was emitted loop will block until it is emitted
    if( finishedSpy.count() == 0 && failSpy.count() == 0 ) loop.exec();

    if( failSpy.count() > 0 ) {
        QFAIL(failSpy.at(0).at(0).toString().toUtf8().data());
    }
}

QTEST_MAIN(PacketTests);
