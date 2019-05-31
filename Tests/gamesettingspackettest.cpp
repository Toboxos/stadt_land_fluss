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
    qDebug() << "GameSettingsPacketTest: Server: Client connected";

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
    qDebug() << "GameSettingsPacketTest: Client: connected";
}

void GameSettingsPacketTest::client_timeout() {
    qDebug() << "GameSettingsPacketTest: Client: timeout";
}

void GameSettingsPacketTest::client_error() {
    qDebug() << "GameSettingsPacketTest: Client: error";
}

void GameSettingsPacketTest::client_receivedGameSettings(GameSettingsPacket packet) {
    qDebug() << "GameSettingsPacketTest: Client: received game settings";

    qDebug() << "   " << packet.getGameName();
    qDebug() << "   " << packet.getRoundNumbers();
    qDebug() << "   " << packet.getRoundDuration();
    qDebug() << "   " << packet.getCountown();
    qDebug() << "   " << "Categories:";

    QVector<QString> categories = packet.getCategories();

    auto end = categories.end();
    for( auto it = categories.begin(); it != end; ++it ) {
        qDebug() << "   " << " - " << *it;
    }
}
