#include "packet.h"

Packet::Packet() {
    m_type = BASE_PACKET;
}

Packet::~Packet() {

}

int Packet::getType() {
    return m_type;
}
