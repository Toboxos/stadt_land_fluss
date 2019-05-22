#ifndef TIMER_H
#define TIMER_H

#include <QtCore>

class timer : public QObject
{

    Q_OBJECT

public:
    timer();

private:
    QTimer *InternalTimer;

public slots:
    void slot();
};

#endif // TIMER_H
