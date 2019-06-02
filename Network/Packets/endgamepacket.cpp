#include "endgamepacket.h"

EndGamePacket::EndGamePacket()
{
    m_type = END_GAME_PACKET;
}

EndGamePacket::EndGamePacket(QVector<QString> ranking){
    m_type = END_GAME_PACKET;
    m_ranking = ranking;
}

QVector<QString> EndGamePacket::getRanking(){
    return m_ranking;
}

void EndGamePacket::setRanking(QVector<QString> ranking){
    m_ranking = ranking;
}

void EndGamePacket::writeData(QTcpSocket& socket) {
    int size = m_ranking.size();
    writeInteger(socket, size);

    for( int i = 0; i < size; ++i ) {
        writeQString(socket, m_ranking[i]);
    }
}

void EndGamePacket::readData(QTcpSocket& socket) {
    int size = 0;
    readInteger(socket, size);

    m_ranking.clear();
    for( int i = 0; i < size; ++i ) {
        QString name;
        readQString(socket, name);
        m_ranking.push_back(name);
    }
}
