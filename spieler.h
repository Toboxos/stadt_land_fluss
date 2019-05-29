#ifndef SPIELER_H
#define SPIELER_H
#include <string>
#include <vector>
#include <QString>
using namespace std;

class Spieler{


public:
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

    vector<int> getCredit();
    void setCredit(unsigned int,int);

    static int _nextId;
    std::vector<QString> answers;
private:
    QString _name;
    int _punkte = 0;
    int _id=0;
    unsigned int connectionId;

    std::vector<int> credits;
};



#endif // SPIELER_H


