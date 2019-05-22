#include "timer.h"
#include <QtCore>
#include <QtDebug>

timer::timer()
{
    InternalTimer = new QTimer(this);
    connect(InternalTimer, SIGNAL(timeout()), this, SLOT(slot()));
    InternalTimer->start(1000);

}

void timer::slot()
{

    qDebug() << "Timer executed";

}
