#ifndef NETWORKEXAMPLE_H
#define NETWORKEXAMPLE_H

#include <QtCore/QObject>
#include "Network/serversocket.h"
#include "Network/clientsocket.h"
#include "Network/Packets/playerjoinpacket.h"

class NetworkExample : public QObject {
    Q_OBJECT

    public:
        NetworkExample();

    public slots:

        void connected();
        void error();
        void timeout();

        void server_playerJoined(PlayerJoinPacket p, unsigned int id);
        void client_playerJoined(PlayerJoinPacket p);

        void client_receivedPlayerList(PlayerListPacket p);

    private:
        ServerSocket m_server;
        ClientSocket m_client;
};

#endif // NETWORKEXAMPLE_H
