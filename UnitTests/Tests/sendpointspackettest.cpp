#include "sendpointspackettest.h"

SendPointsPacketTest::SendPointsPacketTest() {

}

void SendPointsPacketTest::run() {
    connect(&m_server, SIGNAL(connected(unsigned int)), this, SLOT(server_connected(unsigned int)));
    m_server.listen(PORT);

    connect(&m_client, SIGNAL(timeout()), this, SLOT(client_timeout()));
    connect(&m_client, SIGNAL(error()), this, SLOT(client_error()));

    connect(&m_client, SIGNAL(pointsSent(SendPointsPacket)), this, SLOT(client_points(SendPointsPacket)));
    m_client.connectTo("localhost", PORT);
}

void SendPointsPacketTest::client_timeout() {
    emit failed("Client connection timeout");
}

void SendPointsPacketTest::client_error() {
    emit failed("Client connection error");
}

void SendPointsPacketTest::server_connected(unsigned int id) {
    QVector<int> vec;
    for( int i = 0; i < 10; ++i ) {
        vec.push_back(i*2);
    }

    SendPointsPacket packet(vec, 999);
    m_server.send(id, packet);
}

void SendPointsPacketTest::client_points(SendPointsPacket packet) {
    QVector<int> points = packet.getPoints();
    QCOMPARE(packet.getTotalPoints(), 999);

    for( int i = 0; i < 10; ++i ) {
        QCOMPARE(points[i], i*2);
    }

    emit finished();
}
