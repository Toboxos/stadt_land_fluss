#include "playerlistpackettest.h"

PlayerListPacketTest::PlayerListPacketTest() {

}

void PlayerListPacketTest::run() {
    connect(&m_server, SIGNAL(connected(unsigned int)), this, SLOT(server_connected(unsigned int)));
    m_server.listen(PORT);

    connect(&m_client, SIGNAL(timeout()), this, SLOT(client_timeout()));
    connect(&m_client, SIGNAL(error()), this, SLOT(client_error()));

    connect(&m_client, SIGNAL(receivedPlayerList(PlayerListPacket)), this, SLOT(client_playerList(PlayerListPacket)));
    m_client.connectTo("localhost", PORT);
}

void PlayerListPacketTest::client_timeout() {
    emit failed("Client connection timeout");
}

void PlayerListPacketTest::client_error() {
    emit failed("Client connection error");
}

void PlayerListPacketTest::server_connected(unsigned int id) {
    QVector<QString> vec;
    for( int i = 0; i < 5; ++i ) {
        QString s = "Player " + QString::number(i);
        vec.push_back(s);
    }

    PlayerListPacket packet(vec);
    m_server.send(id, packet);
}

void PlayerListPacketTest::client_playerList(PlayerListPacket packet) {
    QVector<QString> players = packet.getPlayers();
    for( int i = 0; i < 5; ++i ) {
        QString s = "Player " + QString::number(i);
        QCOMPARE(players[i], s);
    }

    emit finished();
}
