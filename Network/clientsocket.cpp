#include "clientsocket.h"

ClientSocket::ClientSocket() {
}

ClientSocket::ClientSocket(QString host, quint16 port) {
    connectTo(host, port);
}

void ClientSocket::connectTo(QString host, quint16 port, int timeout) {
    m_socket.connectToHost(host, port);

    m_status = CONNECTING;
    QTimer::singleShot(timeout, this, SLOT(handleTimeout()));

    connect(&m_socket, SIGNAL(connected()), this, SLOT(handleConnection()));
    connect(&m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(handleError()));
    connect(&m_socket, SIGNAL(readyRead()), this, SLOT(read()));
}

void ClientSocket::send(Packet& packet) {
    PACKET_TYPE type = packet.getType();

    m_socket.write(reinterpret_cast<char*>(&type), sizeof(type));
    packet.writeData(m_socket);
}

void ClientSocket::read() {

}

void ClientSocket::handleConnection() {
    m_status = CONNECTED;

    emit connected();
}

void ClientSocket::handleTimeout() {
    if( m_status == CONNECTING ) {
        qDebug("handleTimeout");
        qDebug() << m_status;
        emit timeout();
    }
}

void ClientSocket::handleError() {
    m_status = ERROR;

    emit error();
}
