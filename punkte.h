#ifndef PUNKTE_H
#define PUNKTE_H
#include <QVector>

using namespace std;

class punkte
{
public:
    punkte();

    ///
    /// \brief creates an object of type punkte, saves the vector<int> p in points
    /// \param points for one round
    ///
    punkte(QVector<int> p);

    ///
    /// \brief gets the points for one round
    /// \return points for one round
    ///
    QVector<int> getPunkte();

    ///
    /// \brief sets the points for category i
    /// \param category number
    /// \param points for category
    ///
    void setPunkte(int i,int p);

    ///
    /// \brief gets the points for category s
    /// \param category number
    /// \return
    ///
    int getEinenPunkt(int s);

    private:
    QVector<int> points;
};

#endif // PUNKTE_H
