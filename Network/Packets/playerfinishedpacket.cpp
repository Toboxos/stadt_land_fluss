#include "playerfinishedpacket.h"

PlayerFinishedPacket::PlayerFinishedPacket()
{
    m_type = PLAYER_FINISHED_PACKET;
}

void PlayerFinishedPacket::writeData(QTcpSocket& socket) {
}

void PlayerFinishedPacket::readData(QTcpSocket& socket) {
}
