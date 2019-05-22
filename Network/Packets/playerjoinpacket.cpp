#include "playerjoinpacket.h"

PlayerJoinPacket::PlayerJoinPacket(QString name) {
    m_type = PLAYER_JOIN_PACKET;
    m_name = name;
}

QTcpSocket& PlayerJoinPacket::operator<<(QTcpSocket& socket) {
    socket.write(reinterpret_cast<char*>(&m_type), sizeof(m_type));

    QByteArray bytes = m_name.toUtf8();
    int size = bytes.size();
    socket.write(reinterpret_cast<char*>(&size), sizeof(size));
    socket.write(bytes.data(), size);

    return socket;
};

QTcpSocket& PlayerJoinPacket::operator>>(QTcpSocket& socket) {
    socket.write(reinterpret_cast<char*>(&m_type), sizeof(m_type));

    int size = 0;
    socket.read(reinterpret_cast<char*>(&size), sizeof(size));

    char* bytes = nullptr;
    bytes = new char[size];
    socket.read(bytes, size);

    m_name = bytes;
}
