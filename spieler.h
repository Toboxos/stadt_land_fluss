#ifndef SPIELER_H
#define SPIELER_H
#include <QString>
#include <QVector>
#include <QString>
using namespace std;

class Spieler{


public:
    Spieler();

    ///
    /// \brief creates an object of type player with the name "name"
    /// \param name of player
    ///
    Spieler(QString name);

    ///
    /// \brief returns name of player
    /// \return Qstring _name
    ///
    QString getName();

    ///
    /// \brief returns player ID
    /// \return ID of player
    ///
    int getId();

    ///
    /// \brief sets the player's connection ID
    /// \param player's connection ID
    ///
    void setConnectionId(unsigned int);

    ///
    /// \brief gets the player's connection ID
    /// \return player's connection ID
    ///
    unsigned int getConnectionId();

    ///
    /// \brief gets the player's total score
    /// \return total score
    ///
    int getPunkte();

    ///
    /// \brief set's the player's total score
    /// \param total score
    ///
    void setPunkte(int);

    ///
    /// \brief gets the number of categories
    /// \return number of categories
    ///
    unsigned int Categories();

    ///
    /// \brief gets the round's saved answer for one category in round
    /// \param category number
    /// \return answer for category (category number)
    ///
    QString getAnswer(unsigned int);

    ///
    /// \brief sets the player's answer for one category in round
    /// \param category number
    /// \param answer for category
    ///
    void setAnswer(unsigned int,QString);

    ///
    /// \brief saves the player's answer for one round
    /// \param answers for one round
    ///
    void setAnswers(QVector<QString> antworten);

    ///
    /// \brief gets the credit the player received for the round
    /// \return points for round
    ///
    QVector<int> getCredit();

    ///
    /// \brief sets the credit the player receives for the round
    ///
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


