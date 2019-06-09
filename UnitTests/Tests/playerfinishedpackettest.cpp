#include "playerfinishedpackettest.h"

PlayerFinishedPacketTest::PlayerFinishedPacketTest() {

}

void PlayerFinishedPacketTest::run() {
    connect(&m_server, SIGNAL(connected(unsigned int)), this, SLOT(server_connected(unsigned int)));
    m_server.listen(PORT);

    connect(&m_client, SIGNAL(timeout()), this, SLOT(client_timeout()));
    connect(&m_client, SIGNAL(error()), this, SLOT(client_error()));

    connect(&m_client, SIGNAL(playerFinished(PlayerFinishedPacket)), this, SLOT(client_playerFinished(PlayerFinishedPacket)));
    m_client.connectTo("localhost", PORT);
}

void PlayerFinishedPacketTest::client_timeout() {
    emit failed("Client connection timeout");
}

void PlayerFinishedPacketTest::client_error() {
    emit failed("Client connection error");
}

void PlayerFinishedPacketTest::server_connected(unsigned int id) {
    PlayerFinishedPacket packet("1PlayerMitLangemNamenÖÄß");
    m_server.send(id, packet);
}

void PlayerFinishedPacketTest::client_playerFinished(PlayerFinishedPacket packet) {
    QCOMPARE(packet.getName(), "1PlayerMitLangemNamenÖÄß");

    emit finished();
}
