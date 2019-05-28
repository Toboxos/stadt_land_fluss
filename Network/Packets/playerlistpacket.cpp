#include "playerlistpacket.h"

PlayerListPacket::PlayerListPacket() {
    m_type = PLAYER_LIST_PACKET;
}

PlayerListPacket::PlayerListPacket(QVector<QString> players) {
    m_type = PLAYER_LIST_PACKET;
    m_players = players;
}

void PlayerListPacket::setPlayers(QVector<QString> players) {
    m_players = players;
}

QVector<QString> PlayerListPacket::getPlayers() {
    return m_players;
}

void PlayerListPacket::writeData(QTcpSocket& socket) {
    int size = m_players.size();
    writeInteger(socket, size);

    for( int i = 0; i < size; ++i ) {
        writeQString(socket, m_players[i]);
    }
}

void PlayerListPacket::readData(QTcpSocket& socket) {
    int size = 0;
    readInteger(socket, size);

    m_players.clear();
    for( int i = 0; i < size; ++i ) {
        QString player;
        readQString(socket, player);
        m_players.push_back(player);
    }
}
