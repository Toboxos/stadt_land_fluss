#include "endroundpacket.h"

EndRoundPacket::EndRoundPacket()
{
    m_type = END_ROUND_PACKET;
}

void EndRoundPacket::readData(QTcpSocket &socket){

}

void EndRoundPacket::writeData(QTcpSocket &socket){

}
