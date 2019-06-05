#ifndef NETWORKSERVERJOINTEST_H
#define NETWORKSERVERJOINTEST_H

#include "../Network/clientsocket.h"
#include "../Network/Packets/playerjoinpacket.h"

class NetworkServerJoinTest : public QObject {
    Q_OBJECT

    public:
        NetworkServerJoinTest();
        void run();

    private slots:
        void connected();
        void error();
        void timeout();

        void playerJoined(PlayerJoinPacket p);
        void receivedPlayerList(PlayerListPacket p);


    private:
        QVector<ClientSocket*> m_clients;

        void connectClient(ClientSocket* client);
};

#endif // NETWORKSERVERJOINTEST_H
