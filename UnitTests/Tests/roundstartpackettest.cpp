#include "roundstartpackettest.h"

RoundStartPacketTest::RoundStartPacketTest() {

}

void RoundStartPacketTest::run() {
    connect(&m_server, SIGNAL(connected(unsigned int)), this, SLOT(server_connected(unsigned int)));
    m_server.listen(PORT);

    connect(&m_client, SIGNAL(connected()), this, SLOT(client_connected()));
    connect(&m_client, SIGNAL(timeout()), this, SLOT(client_timeout()));
    connect(&m_client, SIGNAL(error()), this, SLOT(client_error()));

    connect(&m_client, SIGNAL(roundStart(RoundStartPacket)), this, SLOT(client_roundStart(RoundStartPacket)));
    m_client.connectTo("localhost", PORT);
}

void RoundStartPacketTest::server_connected(unsigned int id) {
    RoundStartPacket packet('x');
    m_server.send(id, packet);
}

void RoundStartPacketTest::client_connected() {
}

void RoundStartPacketTest::client_timeout() {
    emit failed("Client connection timeout");
}

void RoundStartPacketTest::client_error() {
    emit failed("Client connection error");
}

void RoundStartPacketTest::client_roundStart(RoundStartPacket packet) {
    QVERIFY(packet.getLetter() == 'x');

    emit finished();
}
