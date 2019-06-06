#ifndef TIMER_H
#define TIMER_H

#include <QtCore>
class timer : public QTimer
{

    Q_OBJECT

public:
    timer(unsigned int Rundendauer, unsigned int Countdowndauer, unsigned int zeitNachFinished);
    ~timer();
    void startRound();
private:
    QTimer *InternalTimer;
    unsigned int roundduration;
    unsigned int countdowntime;
    unsigned int timeafterfinished;
signals:
    void signalStartCountdown();
    void signalStartInput();
    void signalPlayerFinished();
    void signalRoundOver();
public slots:
    void startInput();
    void receivedPlayerFinished();
    void endRound();
};

#endif // TIMER_H
/*
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
