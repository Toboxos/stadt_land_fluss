#ifndef PACKETTESTS_H
#define PACKETTESTS_H

#include <QtTest/QTest>

/**
 * @brief Unittest for testing that packet data is transfered successfully
 */
class PacketTests : public QObject {
    Q_OBJECT

    private slots:
        void testGameSettingsPacket();
        void testRoundStartPacket();
        void testPlayerJoinPacket();
        void testPlayerListPacket();
        void testEndGamePacket();
        void testPlayerFinishedPacket();
        void testSendAnswersPacket();
        void testSendPointsPacket();

};

#endif // PACKETTESTS_H
