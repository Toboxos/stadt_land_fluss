#ifndef PUNKTE_H
#define PUNKTE_H
#include <vector>

using namespace std;

class punkte
{
public:
    punkte(vector<int>);
    ~punkte();

    vector<int> getPunkte();
    void setPunkte(int,int);

    private:
    std::vector<int> points;
};

#endif // PUNKTE_H
