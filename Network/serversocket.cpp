#include "serversocket.h"

#include "Network/Packets/playerjoinpacket.h"

unsigned int ServerSocket::idCounter = 0;

ServerSocket::ServerSocket() {

}

ServerSocket::~ServerSocket() {

    // Add sockets to delete event queue
    auto end = m_sockets.end();
    for( auto it = m_sockets.begin(); it != end; ++it ) {
        QTcpSocket* socket = *it;
        socket->deleteLater();
    }
}

bool ServerSocket::listen(quint16 port) {
    if( m_server.listen(QHostAddress::Any, port) ) {
        connect(&m_server, SIGNAL(newConnection()), this, SLOT(newConnection()));
        return true;
    } else {
        return false;
    }
}

void ServerSocket::newConnection() {
    QTcpSocket* socket = m_server.nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));

    unsigned int id = idCounter++;
    m_sockets.insert(id, socket);

    emit connected(id);
}

void ServerSocket::read() {
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());

    // Get the mapped id for socket
    unsigned int id = m_sockets.key(socket);

    while( socket->bytesAvailable() > 0 ) {
        PACKET_TYPE type;
        socket->read(reinterpret_cast<char*>(&type), sizeof(type));

        /* Check wich Packet type have to be loaded */
        switch( type ) {

            case PLAYER_JOIN_PACKET: {
                PlayerJoinPacket p;
                p.readData(*socket);
                emit playerJoined(p, id);
                break;
            }

            case SEND_ANSWERS_PACKET: {
                SendAnswersPacket p;
                p.readData(*socket);
                emit answersSent(p, id);
                break;
            }

            case PLAYER_FINISHED_PACKET: {
                PlayerFinishedPacket p;
                p.readData(*socket);
                emit playerFinished(p, id);
                break;
            }

            default: {

            }
        }
    }
}

bool ServerSocket::send(unsigned int id, Packet& packet) {

    /* Check if player is mapped */
    if( !m_sockets.contains(id) ) {
        return false;
    }
    QTcpSocket* socket = m_sockets.value(id);

    PACKET_TYPE type = packet.getType();
    socket->write(reinterpret_cast<char*>(&type), sizeof(type));

    packet.writeData(*socket);
    return true;
}
