#include "playerjoinpacket.h"

PlayerJoinPacket::PlayerJoinPacket() {

}

PlayerJoinPacket::PlayerJoinPacket(QString name) {
    m_type = PLAYER_JOIN_PACKET;
    m_name = name;
}

QString PlayerJoinPacket::getName() {
    return m_name;
}

void PlayerJoinPacket::writeData(QTcpSocket& socket) {
    writeQString(socket, m_name);
};

void PlayerJoinPacket::readData(QTcpSocket& socket) {
    readQString(socket, m_name);
}
