#include <QtTest/QtTest>
#include "UnitTests/Tests/gamesettingspackettest.h"
#include "UnitTests/Tests/roundstartpackettest.h"

class PacketTests : public QObject {
    Q_OBJECT

    private slots:
        void testGameSettingsPacket();
        void testRoundStartPacket();

};

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

QTEST_MAIN(PacketTests);
#include "packettests.moc"
