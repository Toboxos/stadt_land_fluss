#include "gamesettingspackettest.h"

GameSettingsPacketTest::GameSettingsPacketTest() {

}

void GameSettingsPacketTest::run() {
    connect(&m_server, SIGNAL(connected(unsigned int)), this, SLOT(server_connected(unsigned int)));
    m_server.listen(PORT);

    connect(&m_client, SIGNAL(connected()), this, SLOT(client_connected()));
    connect(&m_client, SIGNAL(timeout()), this, SLOT(client_timeout()));
    connect(&m_client, SIGNAL(error()), this, SLOT(client_error()));

    connect(&m_client, SIGNAL(receivedGameSettings(GameSettingsPacket)), this, SLOT(client_receivedGameSettings(GameSettingsPacket)));
    m_client.connectTo("localhost", PORT);
}

void GameSettingsPacketTest::server_connected(unsigned int id) {

    QVector<QString> categories;
    for( int i = 0; i < 5; ++i ) {
        QString s;
        s = "Category ";
        s += QString::number(i);
        categories.push_back(s);
    }

    GameSettingsPacket packet;
    packet.setGameName("TestName");
    packet.setRoundNumbers(123);
    packet.setRoundDuration(456);
    packet.setCountdown(789);
    packet.setCategories(categories);

    m_server.send(id, packet);
}

void GameSettingsPacketTest::client_connected() {
}

void GameSettingsPacketTest::client_timeout() {
    emit failed("Timeout at client connection");
}

void GameSettingsPacketTest::client_error() {
    emit failed("Error at client connection");
}

void GameSettingsPacketTest::client_receivedGameSettings(GameSettingsPacket packet) {
    QVERIFY(packet.getGameName() == "TestName");
    QVERIFY(packet.getRoundNumbers() == 123);
    QVERIFY(packet.getRoundDuration() == 456);
    QVERIFY(packet.getCountown() == 789);

    QVector<QString> categories = packet.getCategories();
    QVERIFY(categories.size() == 5);

    for( int i = 0; i < 5; ++i ) {
        QString s;
        s = "Category ";
        s += QString::number(i);
        QVERIFY(categories[i] == s);
    }

    emit finished();
}
