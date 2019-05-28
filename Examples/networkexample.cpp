#include "networkexample.h"


NetworkExample::NetworkExample() {
    m_server.listen(PORT);

    connect(&m_client, SIGNAL(connected()), this, SLOT(connected()));
    m_client.connectTo("localhost", PORT);
}

void NetworkExample::connected() {
    qDebug("Connected");
    PlayerJoinPacket p("IchBinEinLangerName");
    m_client.send(p);
}
