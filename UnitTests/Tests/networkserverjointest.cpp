#include "networkserverjointest.h"

NetworkServerJoinTest::NetworkServerJoinTest() {

}

void NetworkServerJoinTest::run() {
    for( int i = 0; i < 2; ++i ) {
        ClientSocket* client = new ClientSocket();
        m_clients.push_back(client);
    }

    connectClient(m_clients[0]);
}

void NetworkServerJoinTest::connectClient(ClientSocket* client) {
    connect(client, SIGNAL(connected()), this, SLOT(connected()));
    connect(client, SIGNAL(timeout()), this, SLOT(timeout()));
    connect(client, SIGNAL(error()), this, SLOT(error()));

    connect(client, SIGNAL(playerJoined(PlayerJoinPacket)), this, SLOT(playerJoined(PlayerJoinPacket)));
    connect(client, SIGNAL(receivedPlayerList(PlayerListPacket)), this, SLOT(receivedPlayerList(PlayerListPacket)));

    client->connectTo("localhost", PORT);
}

void NetworkServerJoinTest::connected() {
    ClientSocket* client = reinterpret_cast<ClientSocket*>(sender());
    int id = m_clients.indexOf(client);

    qDebug() << "NetworkServerJoinTest: Client " << id << " connected";

    QString name("Client ");
    name += QString::number(id);

    PlayerJoinPacket p(name);
    client->send(p);

    if( id == 0 ) {
        connectClient(m_clients[1]);
    }
}

void NetworkServerJoinTest::timeout() {
    ClientSocket* client = reinterpret_cast<ClientSocket*>(sender());
    int id = m_clients.indexOf(client);

    qDebug() << "NetworkServerJoinTest: Client " << id << " timeout";
}

void NetworkServerJoinTest::error() {
    ClientSocket* client = reinterpret_cast<ClientSocket*>(sender());
    int id = m_clients.indexOf(client);

    qDebug() << "NetworkServerJoinTest: Client " << id << " error";
}

void NetworkServerJoinTest::playerJoined(PlayerJoinPacket p) {
    ClientSocket* client = reinterpret_cast<ClientSocket*>(sender());
    int id = m_clients.indexOf(client);

    qDebug() << "NetworkServerJoinTest: Client " << id << " received PlayerJoinPacket";

    qDebug() << "   " << p.getName();
}

void NetworkServerJoinTest::receivedPlayerList(PlayerListPacket p) {
    ClientSocket* client = reinterpret_cast<ClientSocket*>(sender());
    int id = m_clients.indexOf(client);

    qDebug() << "NetworkServerJoinTest: Client " << id << " received PlayerListPacket";

    auto begin = p.getPlayers().begin();
    auto end = p.getPlayers().end();
    for( int i = 0; i < p.getPlayers().size(); ++i  ) {
        qDebug() << "   " << p.getPlayers()[i];
    }

}
