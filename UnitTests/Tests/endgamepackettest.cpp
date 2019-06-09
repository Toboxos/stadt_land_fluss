#include "endgamepackettest.h"

EndGamePacketTest::EndGamePacketTest() {

}

void EndGamePacketTest::run() {
    connect(&m_server, SIGNAL(connected(unsigned int)), this, SLOT(server_connected(unsigned int)));
    m_server.listen(PORT);

    connect(&m_client, SIGNAL(timeout()), this, SLOT(client_timeout()));
    connect(&m_client, SIGNAL(error()), this, SLOT(client_error()));

    connect(&m_client, SIGNAL(endGame(EndGamePacket)), this, SLOT(client_endGame(EndGamePacket)));
    m_client.connectTo("localhost", PORT);
}

void EndGamePacketTest::client_timeout() {
    emit failed("Client connection timeout");
}

void EndGamePacketTest::client_error() {
    emit failed("Client connection error");
}

void EndGamePacketTest::server_connected(unsigned int id) {
    QVector<QString> vec;
    for( int i = 0; i < 5; ++i ) {
        QString s = "Player " + QString::number(i);
        vec.push_back(s);
    }

    EndGamePacket packet(vec);
    m_server.send(id, packet);
}

void EndGamePacketTest::client_endGame(EndGamePacket packet) {
    QVector<QString> players = packet.getRanking();
    for( int i = 0; i < 5; ++i ) {
        QString s = "Player " + QString::number(i);
        QCOMPARE(players[i], s);
    }

    emit finished();
}

