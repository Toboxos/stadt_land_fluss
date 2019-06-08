#ifndef MOCKSERVERSOCKET_H
#define MOCKSERVERSOCKET_H

#include <QObject>

#include "Network/Packets/packet.h"
#include "Network/Packets/playerjoinpacket.h"
#include "Network/Packets/sendanswerspacket.h"
#include "Network/Packets/sendpointspacket.h"
#include "Network/Packets/endgamepacket.h"
#include "Network/Packets/playerfinishedpacket.h"

class MockServerSocket : public QObject {
    Q_OBJECT

    public:
        MockServerSocket();
        MockServerSocket(quint16 port);

        void setCallbackListen(bool (*callbackListen)(void*, quint16), void* object = nullptr);
        void setCallbackSend(bool (*callbackSend)(void*, unsigned int, Packet&), void* object = nullptr);

        bool listen(quint16 port);
        bool send(unsigned int id, Packet& packet);

        MockServerSocket& operator=(MockServerSocket& other);

    signals:
        void connected(unsigned int id);
        void playerJoined(PlayerJoinPacket packet, unsigned int id);
        void answersSent(SendAnswersPacket packet, unsigned int id);
        void pointsSent(SendPointsPacket packet, unsigned int id);
        void endGame(EndGamePacket packet, unsigned int id);
        void playerFinished(PlayerFinishedPacket packet, unsigned int id);

    private:
        bool (*m_callbackListen)(void* object, quint16 port);
        bool (*m_callbackSend)(void* object, unsigned int id, Packet& packet);

        void* m_callbackListenObject;
        void* m_callbackSendObject;
};

#endif // MOCKSERVERSOCKET_H
