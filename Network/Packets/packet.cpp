#include "packet.h"

Packet::Packet() {
    m_type = BASE_PACKET;
}

Packet::~Packet() {

}

PACKET_TYPE Packet::getType() {
    return m_type;
}
