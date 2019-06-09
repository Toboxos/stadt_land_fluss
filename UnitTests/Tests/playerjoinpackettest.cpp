#include "playerjoinpackettest.h"

PlayerJoinPacketTest::PlayerJoinPacketTest() {

}

void PlayerJoinPacketTest::run() {
    connect(&m_server, SIGNAL(connected(unsigned int)), this, SLOT(server_connected(unsigned int)));
    m_server.listen(PORT);

    connect(&m_client, SIGNAL(timeout()), this, SLOT(client_timeout()));
    connect(&m_client, SIGNAL(error()), this, SLOT(client_error()));

    connect(&m_client, SIGNAL(playerJoined(PlayerJoinPacket)), this, SLOT(client_playerJoin(PlayerJoinPacket)));
    m_client.connectTo("localhost", PORT);
}

void PlayerJoinPacketTest::client_timeout() {
    emit failed("Client connection timeout");
}

void PlayerJoinPacketTest::client_error() {
    emit failed("Client connection error");
}

void PlayerJoinPacketTest::server_connected(unsigned int id) {
    PlayerJoinPacket packet("1PlayerMitLangemNamenÖÄß");
    m_server.send(id, packet);
}

void PlayerJoinPacketTest::client_playerJoin(PlayerJoinPacket packet) {
    QCOMPARE(packet.getName(), "1PlayerMitLangemNamenÖÄß");

    emit finished();
}
