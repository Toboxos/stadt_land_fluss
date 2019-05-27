#include "serversocket.h"

#include "Network/Packets/playerjoinpacket.h"

ServerSocket::ServerSocket() {

}

ServerSocket::ServerSocket(quint16 port) {
    listen(port);
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
#ifdef QT_DEBUG
    qDebug("New Client connection");
#endif
    QTcpSocket* socket = m_server.nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));

    m_sockets.push_back(socket);
}

void ServerSocket::read() {
    qDebug("READ");
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());

    PACKET_TYPE type;
    socket->read(reinterpret_cast<char*>(&type), sizeof(type));

    /* Check wich Packet type have to be loaded */
    switch( type ) {

        case PLAYER_JOIN_PACKET: {
            PlayerJoinPacket p2("");
            p2.readData(*socket);
            qDebug() << "Player Join Packet erhalten:" << p2.getName();
            break;
        }

        default: {

        }
    }
}

bool ServerSocket::send(QString player, Packet& packet) {

    /* Check if player is mapped */
    if( !m_mapped.contains(player) ) {
        return false;
    }

    packet.writeData(*m_mapped.value(player));
    return true;
}
