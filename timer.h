#ifndef TIMER_H
#define TIMER_H

#include <QtCore>
#include "Network/Packets/playerfinishedpacket.h"
class timer : public QTimer
{

    Q_OBJECT

public:
    /// \brief creates new Timer
    /// \param Rundendauer
    /// \param Countdowndauer
    /// \param zeitNachFinished
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
/*
From: Prof Hoff
To: all
666 hail satan 666
ich bin eine böse hexe
    /\
___/__\___
\
 \
  \
   \  |
    \ |
     \|

Alle blöden Programmierer sind gegen die Hexenverschwörung
ermordet sie
brennt sie ab
landet nicht selber in den Flammen Schwestern der Hölle!
wir werden siegriech sein
hail samhain
*/
