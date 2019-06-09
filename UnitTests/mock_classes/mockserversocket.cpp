#include "mockserversocket.h"

MockServerSocket::MockServerSocket() :
    m_callbackListen(nullptr), m_callbackSend(nullptr),
    m_callbackListenObject(nullptr), m_callbackSendObject(nullptr)
{

}

MockServerSocket& MockServerSocket::operator=(MockServerSocket& other) {
    m_callbackSend = other.m_callbackSend;
    m_callbackSendObject = other.m_callbackSendObject;

    m_callbackListen = other.m_callbackListen;
    m_callbackListenObject = other.m_callbackListenObject;

    return *this;
}

bool MockServerSocket::send(unsigned int id, Packet& packet) {
    if( m_callbackSend == nullptr ) {
        return false;
    }

    else {
        m_callbackSend(m_callbackSendObject, id, packet);
        return true;
    }
}

bool MockServerSocket::listen(quint16 port) {
    if( m_callbackListen == nullptr ) {
        return false;
    }

    else {
        m_callbackListen(m_callbackListenObject, port);
        return true;
    }
}

void MockServerSocket::setCallbackSend(void (*callbackSend)(void*, unsigned int, Packet&), void* object) {
    m_callbackSend = callbackSend;
    m_callbackSendObject = object;
}

void MockServerSocket::setCallbackListen(void (*callbackListen)(void*, quint16), void* object) {
    m_callbackListen = callbackListen;
    m_callbackListenObject = object;
}
