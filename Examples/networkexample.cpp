#include "networkexample.h"


NetworkExample::NetworkExample() {
    m_server.listen(PORT);

    connect(&m_client, SIGNAL(connected()), this, SLOT(connected()));
    connect(&m_client, SIGNAL(timeout()), this, SLOT(timeout()));
    connect(&m_client, SIGNAL(error()), this, SLOT(error()));
    //m_client.connectTo("localhost", PORT);
    m_client.connectTo("peter12341234gibtesnicht.org", 8000, 10000);
}

void NetworkExample::connected() {
    qDebug("Connected");
    PlayerJoinPacket p("IchBinEinLangerName");
    m_client.send(p);
}

void NetworkExample::error() {
    qDebug("ClientSocket emitted error()");
}

void NetworkExample::timeout() {
    qDebug("ClientSocket emitted timeout()");
}
