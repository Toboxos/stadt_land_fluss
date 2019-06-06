#include "playerfinishedpacket.h"

PlayerFinishedPacket::PlayerFinishedPacket() {
    m_type = PLAYER_FINISHED_PACKET;
}

PlayerFinishedPacket::PlayerFinishedPacket(QString name) {
    m_type = PLAYER_FINISHED_PACKET;
    m_name = name;
}

void PlayerFinishedPacket::setName(QString name) {
    m_name = name;
}

QString PlayerFinishedPacket::getName() {
    return m_name;
}

void PlayerFinishedPacket::writeData(QTcpSocket& socket) {
    writeQString(socket, m_name);
}

void PlayerFinishedPacket::readData(QTcpSocket& socket) {
    readQString(socket, m_name);
}
