#ifndef ANTWORTEN_H
#define ANTWORTEN_H
#include <stdint.h>
#include<vector>
#include <QString>
#include "spieler.h"
using namespace std;

class antworten{
   public:
    antworten(vector<QString>);
    ~antworten();

    vector<QString> getAntworten();
    void setAntworten(QString,int);

    private:
    vector<QString> answers;
};

#endif // ANTWORTEN_H
