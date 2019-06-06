#include "startcountdownpacket.h"

StartCountdownPacket::StartCountdownPacket()
{
    m_type = START_COUNTDOWN_PACKET;
}

void StartCountdownPacket::readData(QTcpSocket& socket){

}

void StartCountdownPacket::writeData(QTcpSocket &socket){

}
