#ifndef ANTWORTEN_H
#define ANTWORTEN_H
#include <stdint.h>
#include<vector>
#include "spieler.h"
using namespace std;

class antworten{
   public:
    antworten(vector<std::string>);
    ~antworten();

    vector<std::string> getAntworten();
    void setAntworten(std::string,int);

    private:
    std::vector<std::string> answers;
};

#endif // ANTWORTEN_H
