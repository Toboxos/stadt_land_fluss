#include "jointest.h"

JoinTest::JoinTest() {

}

void JoinTest::run(CLogik* logic) {
    m_testStep = 0;
    for( unsigned int id = 0; id < m_playerCount; ++id ) {
        QString s = "Player " + QString::number(id);
        PlayerJoinPacket packet(s);

        m_testStep = id;

        /* Expect for all players which are connected (or will connect this iteration)
         * that they dont have received their needed packets */
        for( int i = 0; i < m_testStep + 1; ++i ) {
            m_receivedPackets[i] = false;
        }

        // Mock server player connected
        logic->spieler_beitritt(packet, id);

        for( int i = 0; i < m_testStep + 1; ++i ) {
            if( !m_receivedPackets[i] ) {
                QString s = "Player " + QString::number(i) + " didnt get expected packets";
                QFAIL(s.toUtf8().data());
            }
            else {}
        }
    }
}

void JoinTest::send(void* object, unsigned int id, Packet& packet) {
    QVERIFY(id < m_playerCount);

    JoinTest* test = reinterpret_cast<JoinTest*>(object);


    qDebug() << "[" << test->m_testStep << "] " << id << ": " << PACKET_TYPE_NAMES[packet.getType()];

    /*
     * Player has less id than actual step -> player already joined:
     * - player should received player join packet
     * - name of joined player should be with current step
     */
    if( id < test->m_testStep ) {
        QVERIFY(packet.getType() == PLAYER_JOIN_PACKET );

        PlayerJoinPacket* realPacket = reinterpret_cast<PlayerJoinPacket*>(&packet);
        QString s = "Player " + QString::number(test->m_testStep);
        QVERIFY(realPacket->getName() == s);
        test->m_receivedPackets[id] = true;
    }

    /*
     * Player is player which joined.
     * - should receive player list packet
     * - packet should contain all names from players before
     */
    else if( id == test->m_testStep ) {
        QVERIFY(packet.getType() == PLAYER_LIST_PACKET);

        PlayerListPacket* realPacket = reinterpret_cast<PlayerListPacket*>(&packet);
        QVector<QString> players = realPacket->getPlayers();

        QVERIFY(players.size() == test->m_testStep);
        for( int i = 0; i < test->m_testStep; ++i ) {
            QString s = "Player " + QString::number(i);
            QVERIFY(players.contains(s));
        }

        test->m_receivedPackets[id] = true;
    }

    else {}
}
