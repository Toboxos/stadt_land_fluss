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
    /// \brief starts timer for a new Round
    void startRound();
    /// \brief starts timer for a break between two rounds
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
    /// \brief starts when round is opened for input
    void startInput();
    /// \brief starts when round is closing in 10 seconds
    void receivedPlayerFinished();
    ///\brief starts, when round is closed
    void endRound();
};

#endif // TIMER_H

