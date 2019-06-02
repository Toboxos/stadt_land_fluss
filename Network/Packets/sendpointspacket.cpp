#include "sendpointspacket.h"

SendPointsPacket::SendPointsPacket()
{
    m_type = SEND_POINTS_PACKET;
}

SendPointsPacket::SendPointsPacket(QVector<int> v_points, int totalpoints){
    m_type = SEND_POINTS_PACKET;
    m_points = v_points;
    m_totalpoints = totalpoints;
}

QVector<int> SendPointsPacket::getPoints(){
    return m_points;
}

void SendPointsPacket::setPoints(QVector<int> v_points){
    m_points = v_points;
}

int SendPointsPacket::getTotalPoints(){
    return m_totalpoints;
}

void SendPointsPacket::setTotalPoints(int totalpoints){
    m_totalpoints = totalpoints;
}

void SendPointsPacket::writeData(QTcpSocket& socket) {
    int size = m_points.size();
    writeInteger(socket, size);

    for( int i = 0; i < size; ++i ) {
        writeInteger(socket, m_points[i]);
    }

    writeInteger(socket, m_totalpoints);
}

void SendPointsPacket::readData(QTcpSocket& socket) {
    int size = 0;
    readInteger(socket, size);

    m_points.clear();
    for( int i = 0; i < size; ++i ) {
        int point;
        readInteger(socket, point);
        m_points.push_back(point);
    }

    readInteger(socket, m_totalpoints);
}
