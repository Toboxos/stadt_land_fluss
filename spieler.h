#ifndef SPIELER_H
#define SPIELER_H
#include <QString>
#include <QVector>
#include <QString>
using namespace std;

class Spieler{


public:
    Spieler();
    Spieler(QString);

    QString getName();
    int getId();

    void setConnectionId(unsigned int);
    unsigned int getConnectionId();

    int getPunkte();
    void setPunkte(int);

    unsigned int Categories();
    QString getAnswer(unsigned int);
    void setAnswer(unsigned int,QString);
    void setAnswers(QVector<QString> antworten);

    QVector<int> getCredit();
    void setCredit(unsigned int,int);

    static int _nextId;
    QVector<QString> answers;
private:
    QString _name;
    int _punkte = 0;
    int _id=0;
    unsigned int connectionId;

    QVector<int> credits;
};



#endif // SPIELER_H


