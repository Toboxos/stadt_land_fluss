#ifndef TIMER_H
#define TIMER_H

#include <QtCore>

class timer : public QObject
{

    Q_OBJECT

public:
    timer();
    ~timer();
    void endRound();
private:
    QTimer *InternalTimer;

public slots:
    void roundEndSlot();
};

#endif // TIMER_H
