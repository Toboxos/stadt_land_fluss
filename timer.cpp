#include "timer.h"
#include <QtCore>
#include <QtDebug>
#include <spielerliste.h>

///<summary> constructor of timer class </summary>
/// <parameters> </parameters>
timer::timer(CLogik *cLogic)
{
    clogic = cLogic;
    InternalTimer = new QTimer(this);
}
///<summary> destructor of timer class</summary>
/// <parameters></parameters>
timer::~timer()
{
    delete InternalTimer;
}

void timer::startRound(){
    QTimer::singleShot((clogic->getSpieleinstellungen()->getRundendauer()-10)*1000, this, SLOT(endRound()));
}

///<summary> is called on Round end, when a Player completed his words </summary>
///<parameters> </parameters>
void timer::endRound(){
    QTimer::singleShot(clogic->getSpieleinstellungen()->getCountdown()*1000, this, SLOT(roundEnd()));
}

///<summary> slot that executes when timer runs out</summary>
/// <parameters> </parameters>
void timer::roundEndSlot()
{
    qDebug() << "Timer executed";
}

