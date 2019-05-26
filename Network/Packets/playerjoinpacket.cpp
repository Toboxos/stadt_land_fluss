#include "playerjoinpacket.h"

PlayerJoinPacket::PlayerJoinPacket(QString name) {
    m_type = PLAYER_JOIN_PACKET;
    m_name = name;
}

QString PlayerJoinPacket::getName() {
    return m_name;
}

void PlayerJoinPacket::writeData(QTcpSocket* socket) {
    QByteArray bytes = m_name.toUtf8();
    int size = bytes.size();
    socket->write(reinterpret_cast<char*>(&size), sizeof(size));
    socket->write(bytes.data(), size);
};

void PlayerJoinPacket::readData(QTcpSocket* socket) {
    int size = 0;
    socket->read(reinterpret_cast<char*>(&size), sizeof(size));

    char* bytes = nullptr;
    bytes = new char[size+1];
    bytes[size] = '\0';
    socket->read(bytes, size);

    m_name = bytes;
}
