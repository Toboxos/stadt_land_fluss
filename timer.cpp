#include "timer.h"
#include <QtCore>
#include <QtDebug>
#include <spielerliste.h>

///<summary> constructor of timer class </summary>
/// <parameters> </parameters>
timer::timer()
{
    InternalTimer = new QTimer(this);
    connect(InternalTimer, SIGNAL(timeout()), this, SLOT(slot()));

}
///<summary> destructor of timer class</summary>
/// <parameters></parameters>
timer::~timer()
{
    delete InternalTimer;
}

///<summary> is called on Round end, when a Player completed his words </summary>
///<parameters> </parameters>
void timer::endRound(){
   // InternalTimer->singleShot(_einstellung->getCountdown()*1000, this, SLOT(roundEnd()));
}
///<summary> slot that executes when timer runs out</summary>
/// <parameters> </parameters>
void timer::roundEndSlot()
{

    qDebug() << "Timer executed";

}
