#ifndef TIMER_H
#define TIMER_H

#include <QtCore>
#include "Network/Packets/playerfinishedpacket.h"
class timer : public QTimer
{

    Q_OBJECT

public:
    timer(unsigned int Rundendauer, unsigned int Countdowndauer, unsigned int zeitNachFinished);
    ~timer();
    void startRound();
    void rundenPausenTimer();
private:
    QTimer *InternalTimer;
    unsigned int roundduration;
    unsigned int countdowntime;
    unsigned int timeafterfinished;
signals:
    void signalStartInput();
    void signalPlayerFinished();
    void signalRoundOver();
    void pausenTimer();
public slots:
    void startInput();
    void receivedPlayerFinished();
    void endRound();
};

#endif // TIMER_H

