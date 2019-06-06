#include "timer.h"

///<summary> constructor of timer class </summary>
/// <parameters> </parameters>
timer::timer(unsigned int Rundendauer, unsigned int Countdowndauer, unsigned int zeitNachFinished)
{
    roundduration = Rundendauer;
    countdowntime = Countdowndauer;
    timeafterfinished = zeitNachFinished;
    InternalTimer = new QTimer(this);
}
///<summary> destructor of timer class</summary>
/// <parameters></parameters>
timer::~timer()
{
    delete InternalTimer;
}

///<summary>is called when the round is supposed to start </summary>
///<parameters> </parameters>
void timer::startRound(){
    emit signalStartCountdown();
    this->singleShot(countdowntime*1000, this, SLOT(startInput()));
}

///<summary> slot is called when Player input should be started</summary>
///<parameters> </parameters>
void timer::startInput()
{
    this->stop();
    emit signalStartInput();
    this->singleShot((roundduration-timeafterfinished)*1000, this, SLOT(receivedPlayerFinished()));
}

///<summary> slot that executes when Player completed his caregories or time runs out</summary>
/// <parameters> </parameters>
void timer::receivedPlayerFinished()
{
    this->stop();
    emit signalPlayerFinished();
    this->singleShot(timeafterfinished*1000, this, SLOT(endRound()));
}

///<summary> slot is called when Player input should be closed</summary>
///<parameters> </parameters>
void timer::endRound()
{
    this->stop();
    emit signalRoundOver();
}
