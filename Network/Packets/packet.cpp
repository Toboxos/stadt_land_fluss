#include "packet.h"

Packet::Packet() {
    m_type = BASE_PACKET;
}

Packet::~Packet() {

}

int Packet::getType() {
    return m_type;
}

QTcpSocket& Packet::operator<<(QTcpSocket& socket) {
    socket.write(reinterpret_cast<char*>(&m_type), sizeof(m_type));

    return socket;
}

QTcpSocket& Packet::operator>>(QTcpSocket& socket) {
    socket.read(reinterpret_cast<char*>(&m_type), sizeof(m_type));

    return socket;
}
