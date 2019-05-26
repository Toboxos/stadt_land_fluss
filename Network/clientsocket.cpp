#include "clientsocket.h"

ClientSocket::ClientSocket() {
}

ClientSocket::ClientSocket(QString host, quint16 port) {
    connectTo(host, port);
}

void ClientSocket::connectTo(QString host, quint16 port) {
    m_socket.connectToHost(host, port);

    connect(&m_socket, SIGNAL(connected()), this, SIGNAL(connected()));
    connect(&m_socket, SIGNAL(readyRead()), this, SLOT(read()));
}

void ClientSocket::send(Packet& packet) {
    PACKET_TYPE type = packet.getType();

    m_socket.write(reinterpret_cast<char*>(&type), sizeof(type));
    packet.writeData(&m_socket);
}

void ClientSocket::read() {

}
