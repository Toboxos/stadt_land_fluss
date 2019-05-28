#include "networkexample.h"


NetworkExample::NetworkExample() {
    //connect(&m_server, SIGNAL(playerJoined(PlayerJoinPacket, unsigned int)), this, SLOT(server_playerJoined(PlayerJoinPacket, unsigned int)));

    //m_server.listen(PORT);

    connect(&m_client, SIGNAL(connected()), this, SLOT(connected()));
    connect(&m_client, SIGNAL(timeout()), this, SLOT(timeout()));
    connect(&m_client, SIGNAL(error()), this, SLOT(error()));

    connect(&m_client, SIGNAL(playerJoined(PlayerJoinPacket)), this, SLOT(client_playerJoined(PlayerJoinPacket)));
    connect(&m_client, SIGNAL(receivedPlayerList(PlayerListPacket)), this, SLOT(client_receivedPlayerList(PlayerListPacket)));
    m_client.connectTo("localhost", PORT);

}

void NetworkExample::connected() {
    qDebug("Connected");

    PlayerJoinPacket p("IchBinEinLangerName");
    PlayerJoinPacket p2("Spielr2");

    m_client.send(p);
    m_client.send(p2);
}

void NetworkExample::error() {
    qDebug("ClientSocket emitted error()");
}

void NetworkExample::timeout() {
    qDebug("ClientSocket emitted timeout()");
}

void NetworkExample::server_playerJoined(PlayerJoinPacket p, unsigned int id) {
    qDebug("Server received PlayerJoinedPacket");

    qDebug() << "ID of connection:" << id << " Name of player:" << p.getName();

    QVector<QString> players;
    players.push_back("Player 1");
    players.push_back("Player 2");
    players.push_back("Player 3");

    PlayerJoinPacket p1("IchBinGeradeBeigetreten-Name");
    PlayerListPacket p2(players);

    m_server.send(id, p1);
    m_server.send(id, p2);

}

void NetworkExample::client_playerJoined(PlayerJoinPacket p) {
    qDebug("Client received PlayerJoinedPacket");

    qDebug() << "Name of player:" << p.getName();
}

void NetworkExample::client_receivedPlayerList(PlayerListPacket p) {
    qDebug("Client received PlayerListPacket");

    qDebug("Players:");
    QVector<QString> players = p.getPlayers();
    for( int i = 0; i < players.size(); ++i ) {
        qDebug() << players[i];
    }
}
