#include "roundstartpacket.h"

RoundStartPacket::RoundStartPacket() {
    m_type = ROUND_START_PACKET;
}

RoundStartPacket::RoundStartPacket(const char letter) {
    m_type = ROUND_START_PACKET;
    m_letter = letter;
}

void RoundStartPacket::setLetter(const char letter) {
    m_letter = letter;
}

char RoundStartPacket::getLetter() {
    return m_letter;
}

void RoundStartPacket::writeData(QTcpSocket &socket) {
    socket.write(&m_letter, sizeof(m_letter));
}

void RoundStartPacket::readData(QTcpSocket &socket) {
    socket.read(&m_letter, sizeof(m_letter));
}
