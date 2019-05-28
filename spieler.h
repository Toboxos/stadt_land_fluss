#ifndef SPIELER_H
#define SPIELER_H
#include <string>
#include <vector>
using namespace std;

class Spieler{


public:
    Spieler(std::string);

    std::string getName();
    int getId();

    int getPunkte();
    void setPunkte(int);

    unsigned int Categories();
    std::string getAnswer(unsigned int);
    void setAnswer(unsigned int,std::string);

    vector<int> getCredit();
    void setCredit(unsigned int,int);

    static int _nextId;
    std::vector<std::string> answers;
private:
    std::string _name;
    int _punkte = 0;
    int _id=0;

    std::vector<int> credits;
};



#endif // SPIELER_H


