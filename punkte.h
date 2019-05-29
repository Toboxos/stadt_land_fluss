#ifndef PUNKTE_H
#define PUNKTE_H
#include <QVector>

using namespace std;

class punkte
{
public:
    punkte();
    punkte(QVector<int>);
    ~punkte();

    QVector<int> getPunkte();
    void setPunkte(int,int);

    private:
    QVector<int> points;
};

#endif // PUNKTE_H
