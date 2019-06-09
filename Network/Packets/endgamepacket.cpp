#include "endgamepacket.h"

EndGamePacket::EndGamePacket()
{
    m_type = END_GAME_PACKET;
}

EndGamePacket::EndGamePacket(QVector<QString> ranking, QVector<int> points){
    m_type = END_GAME_PACKET;
    m_ranking = ranking;
    m_points = points;
}

QVector<QString> EndGamePacket::getRanking(){
    return m_ranking;
}
QVector<int> EndGamePacket::getPoints(){
    return m_points;
}
void EndGamePacket::setRanking(QVector<QString> ranking){
    m_ranking = ranking;
}
void EndGamePacket::setPoints(QVector<int> points){
    m_points = points;
}
void EndGamePacket::writeData(QTcpSocket& socket) {
    int size = m_ranking.size();
    writeInteger(socket, size);

    for( int i = 0; i < size; ++i ) {
        writeQString(socket, m_ranking[i]);
    }
    int sizep = m_points.size();
    writeInteger(socket, sizep);

    for( int i = 0; i < sizep; ++i ) {
        writeInteger(socket, m_points[i]);
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
    int sizep = 0;
    readInteger(socket, sizep);

    m_points.clear();
    for(int i = 0; i < sizep; i++){
        int points;
        readInteger(socket, points);
        m_points.push_back(points);
    }
}
