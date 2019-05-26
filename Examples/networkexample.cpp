#include "networkexample.h"


NetworkExample::NetworkExample() {
    m_server.listen(1234);

    connect(&m_client, SIGNAL(connected()), this, SLOT(connected()));
    m_client.connectTo("localhost", 1234);
}

void NetworkExample::connected() {
    qDebug("Connected");
    PlayerJoinPacket p("IchBinEinLangerName");
    m_client.send(p);
}
