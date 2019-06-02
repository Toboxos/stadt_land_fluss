#ifndef TIMER_H
#define TIMER_H

#include <QtCore>
#include "CLogik.h"
class timer : public QObject
{

    Q_OBJECT

public:
    timer(CLogik *cLogic);
    ~timer();
    void endRound();
    void startRound();
private:
    QTimer *InternalTimer;
    CLogik *clogic;
public slots:
    void roundEndSlot();
};

#endif // TIMER_H
