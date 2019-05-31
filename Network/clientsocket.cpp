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
    while( m_socket.bytesAvailable() > 0 ) {
        PACKET_TYPE type;
        m_socket.read(reinterpret_cast<char*>(&type), sizeof(type));

        switch( type ) {
            case PLAYER_JOIN_PACKET: {
                PlayerJoinPacket p;
                p.readData(m_socket);
                emit playerJoined(p);
                break;
            }

            case PLAYER_LIST_PACKET: {
                PlayerListPacket p;
                p.readData(m_socket);
                emit receivedPlayerList(p);
                break;
            }

            case GAME_SETTINGS_PACKET: {
                GameSettingsPacket p;
                p.readData(m_socket);
                emit receivedGameSettings(p);
                break;
            }

            default: {

            }
        }
    }


}

void ClientSocket::handleConnection() {
    m_status = CONNECTED;

    emit connected();
}

void ClientSocket::handleTimeout() {
    if( m_status == CONNECTING ) {
        emit timeout();
    }
}

void ClientSocket::handleError() {
    m_status = ERROR;

    emit error();
}
