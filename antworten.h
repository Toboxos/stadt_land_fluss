#ifndef ANTWORTEN_H
#define ANTWORTEN_H
#include <stdint.h>
#include<QVector>
#include <QString>
#include "spieler.h"
using namespace std;

class antworten{
   public:
    antworten();
    antworten(QVector<QString>);
    ~antworten();

    QVector<QString> getAntworten();
    void setAntworten(QString,int);

    private:
    QVector<QString> answers;
};

#endif // ANTWORTEN_H
