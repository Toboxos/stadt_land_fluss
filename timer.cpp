#include "timer.h"


timer::timer(unsigned int Rundendauer, unsigned int Countdowndauer, unsigned int zeitNachFinished)
{
    roundduration = Rundendauer;
    countdowntime = Countdowndauer;
    timeafterfinished = zeitNachFinished;
    InternalTimer = new QTimer(this);
}

timer::~timer()
{
    delete InternalTimer;
}

void timer::startRound(){
    singleShot(countdowntime*1000, this, SLOT(startInput()));
}


void timer::startInput()
{
    emit signalStartInput();
    singleShot((roundduration*60-timeafterfinished)*1000, this, SLOT(receivedPlayerFinished()));
}
void timer::rundenPausenTimer(){
    singleShot(5*1000, this, SIGNAL(pausenTimer()));
}

void timer::receivedPlayerFinished()
{
    stop();
    emit signalPlayerFinished();
    singleShot(timeafterfinished*1000, this, SLOT(endRound()));
}


void timer::endRound()
{
    stop();
    emit signalRoundOver();
}
