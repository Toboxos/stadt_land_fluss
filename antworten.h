#ifndef ANTWORTEN_H
#define ANTWORTEN_H
#include <stdint.h>
#include<QVector>
#include <QString>
#include "spieler.h"
#include <QDebug>
using namespace std;

class antworten{
   public:
    antworten();

    ///
    /// \brief creates an object of type antworten and saves the received answers for one round in vector answers
    /// \param received answers for one round
    ///
    antworten(QVector<QString> a);

    ///
    /// \brief gets the answers for one round
    /// \return answers
    ///
    QVector<QString> getAntworten();

    ///
    /// \brief saves the answer for category i
    /// \param answer for category
    /// \param category number
    ///
    void setAntworten(QString a,int i);

    private:
    QVector<QString> answers;
};

#endif // ANTWORTEN_H
