#ifndef CLOGIK_H
#define CLOGIK_H
#include <stdint.h>
#include <iostream>
#include <QVector>
#include <stdlib.h>
#include <QObject>
#include <QString>
#include <ctype.h>

// When unit testing, dont include original ServerSocket
// indeed include MockServerSocket which simulate an ServerSocket
#ifdef UNIT_TEST
#include "UnitTests/mock_classes/mockserversocket.h"
typedef MockServerSocket ServerSocket;
#else
#include "Network/serversocket.h"
#endif

#include "antworten.h"
#include "spieler.h"
#include "punkte.h"

#include "Network/Packets/playerjoinpacket.h"
#include "Network/Packets/startcountdownpacket.h"
#include "Network/Packets/playerlistpacket.h"
#include "Network/Packets/endroundpacket.h"
#include "Network/Packets/playerfinishedpacket.h"
#include "spieleinstellungen.h"
#include "spielerwarteraum.h"
#include "timer.h"

using namespace std;
class CLogik : public QObject {
    Q_OBJECT
public:

    CLogik();
    ~CLogik();

    void run();

    int createPlayer(QString);


    /**
     * @brief sorts answers by category
     * @param number of category
     * @return answers by category
     */
    QVector<QString> sortAnswers(unsigned int category);

    /**
     * @brief awards points for category
     * @param number of category
     * @return points for category
     */
    QVector<int> awardPoints(unsigned int category);

    /**
     * @brief organizes the awarding of points, returning the points to the players, saving the total credits
     */
    void Punktevergabe();

    /**
     * @brief sorts players by total credit
     * @return players organized by rank
     */
    QVector<QString> getWinner();

    /**
     * @brief random letter for round, repeated letters only when every letter in the english alphabet has been used
     * @return letter for round
     */
    char getLetter();

    ///
    /// \brief getSpieleinstellungen
    /// \return
    ///
    Spieleinstellungen* getSpieleinstellungen();

    ///
    /// \brief getSpielerListe
    /// \return
    ///
    QVector<Spieler>* getSpielerListe();
    void starteServerSocket();
    void openHostSpielEinstellungen();
    void openKategorieEingabe();
    void openSpielerWarteRaum();
    void sendeSpielStart();
    void sendeRundenStart();
    void endGame();    
    void sendToAll(Packet& p);
public slots:
    /**
     * @brief nimmt Signal mit Packet entgegen, erstellt neues Spielerobjekt und speichert die VerbindungsID ab
     * @param packet
     * @param id
     */
    void spieler_beitritt(PlayerJoinPacket packet, unsigned int id);
	
    void bekommt_antwort(SendAnswersPacket packet, unsigned int id);

    void startInput();

    void playerFinished();

    void endInput();

    void bekommt_playerFinished(PlayerFinishedPacket packet, unsigned int id);

    void nextRound();

signals:
    void serverBereit();

    void initRoundEnd();

private:
    int answersReceived = 0;
    int currentRound = 0;
    void setupTimer();
    SpielerWarteRaum *warteRaum;
    QVector<Spieler> players;
    QVector<antworten> m_answers;
    QVector<punkte> m_points;
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char usedLetters[26];
    ServerSocket serverSocket;
    Spieleinstellungen  _einstellung ;
    char m_letter;
    timer *roundTimer = nullptr;
};
#endif
