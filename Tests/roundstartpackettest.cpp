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
    qDebug() << "RoundStartPacketTest: Server: Client connected";

    RoundStartPacket packet('x');
    m_server.send(id, packet);
}

void RoundStartPacketTest::client_connected() {
    qDebug() << "RoundStartPacketTest: Client: connected";
}

void RoundStartPacketTest::client_timeout() {
    qDebug() << "RoundStartPacketTest: Client: timeout";
}

void RoundStartPacketTest::client_error() {
    qDebug() << "RoundStartPacketTest: Client: error";
}

void RoundStartPacketTest::client_roundStart(RoundStartPacket packet) {
    qDebug() << "RoundStartPacketTest: Client: round start";
    qDebug() << "   " << packet.getLetter();
}
