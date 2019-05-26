#ifndef NETWORKEXAMPLE_H
#define NETWORKEXAMPLE_H

#include <QObject>

#include "Network/serversocket.h"
#include "Network/clientsocket.h"
#include "Network/Packets/playerjoinpacket.h"

class NetworkExample : public QObject {
    Q_OBJECT

    public:
        NetworkExample() {
            m_server.listen(1234);

            connect(&m_client, SIGNAL(connected()), this, SLOT(connected()));
            m_client.connectTo("localhost", 1234);
        }

    public slots:

        void connected() {
            qDebug("Connected");
            PlayerJoinPacket p("IchBinEinLangerName");
            m_client.send(p);
        }

    private:
        ServerSocket m_server;
        ClientSocket m_client;
};

#endif // NETWORKEXAMPLE_H
