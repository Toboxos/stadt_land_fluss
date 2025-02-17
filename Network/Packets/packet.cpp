#include "packet.h"

Packet::Packet() {
    m_type = BASE_PACKET;
}

Packet::~Packet() {

}

PACKET_TYPE Packet::getType() {
    return m_type;
}

void Packet::writeQString(QTcpSocket& socket, QString& QString) {
    QByteArray bytes = QString.toUtf8();
    int size = bytes.size();

    socket.write(reinterpret_cast<char*>(&size), sizeof(size));
    socket.write(bytes.data(), size);
}

void Packet::readQString(QTcpSocket& socket, QString& QString) {

    // Read size of incoming QString from socket. Check if size is less than 0 (cant allocate negative amount of memory)
    int size = 0;
    socket.read(reinterpret_cast<char*>(&size), sizeof(size));
    if( size < 0 ) size = 0;

    // Allocate buffer
    char* data = nullptr;
    data = new char[size + 1];

    // Check for correct allocation
    if( data != nullptr ) {
        data[size] = 0;

        socket.read(data, size);
        QString = data;
    }
    else
    {
        //do nothing
    }

    // Free
    delete[] data;
}

void Packet::writeInteger(QTcpSocket& socket, int& integer) {
    socket.write(reinterpret_cast<char*>(&integer), sizeof(integer));
}

void Packet::readInteger(QTcpSocket& socket, int& integer) {
    socket.read(reinterpret_cast<char*>(&integer), sizeof(integer));
}
