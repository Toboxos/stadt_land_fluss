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
                qDebug() << "Received Player Join Packet";
                break;
            }

            case PLAYER_LIST_PACKET: {
                PlayerListPacket p;
                p.readData(m_socket);
                emit receivedPlayerList(p);
                qDebug() << "Received Player List Packet";
                break;
            }

            case GAME_SETTINGS_PACKET: {
                GameSettingsPacket p;
                p.readData(m_socket);
                emit receivedGameSettings(p);
                qDebug() << "Received Game Settings Packet";
                break;
            }

            case ROUND_START_PACKET: {
                RoundStartPacket p;
                p.readData(m_socket);
                emit roundStart(p);
                qDebug() << "Received Round start packet";
                break;
            }

            case SEND_ANSWERS_PACKET: {
                SendAnswersPacket p;
                p.readData(m_socket);
                emit answersSent(p);
                qDebug() << "Received Send answers packet";
                break;
            }

            case SEND_POINTS_PACKET: {
                SendPointsPacket p;
                p.readData(m_socket);
                emit pointsSent(p);
                qDebug() << "Received Send Points Packet";
                break;
            }

            case END_GAME_PACKET: {
                 EndGamePacket p;
                 p.readData(m_socket);
                 emit endGame(p);
                 qDebug() << "Received End Game Packet";
                 break;
            }
            case PLAYER_FINISHED_PACKET:{
                PlayerFinishedPacket p;
                p.readData(m_socket);
                emit playerFinished(p);
                qDebug() << "Received Player Finished Packet";
                break;
            }

            case START_COUNTDOWN_PACKET: {
                StartCountdownPacket p;
                p.readData(m_socket);
                emit startCountdown(p);
                qDebug() << "Received Start Countdown Packet";
                break;
            }
            case END_ROUND_PACKET: {
                EndRoundPacket p;
                p.readData(m_socket);
                emit endRound(p);
                qDebug() << "Received End Round Packet";
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
