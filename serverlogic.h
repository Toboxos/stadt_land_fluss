#ifndef ServerLogic_H
#define ServerLogic_H
#include <stdint.h>
#include <iostream>
#include <QVector>
#include <stdlib.h>
#include <QObject>
#include <QString>
#include <ctype.h>

// When unit testing, dont include original ServerSocket
// indeed include MockServerSocket which simulates a ServerSocket
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
class ServerLogic : public QObject {
    Q_OBJECT
public:

    ServerLogic();
    ~ServerLogic();

    ///
    /// \brief create object HostSpielEinstellungen and execute
    ///
    void run();

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
    void punktevergabe();

    /**
     * @brief sorts players by total credit, packs ranking by names and credit in EndGamePacket
     * @return EndGamePacket
     */
    EndGamePacket getWinner();

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

    ///
    /// \brief starts server socket
    ///
    void starteServerSocket();

    ///
    /// \brief opens the game settings window
    ///
    void openHostSpielEinstellungen();

    ///
    /// \brief opens window to set categories
    ///
    void openKategorieEingabe();

    ///
    /// \brief opens player waiting room
    ///
    void openSpielerWarteRaum();

    ///
    /// \brief sends a GameSettingsPacket and PlayerListPacket to every client
    ///
    void sendeSpielStart();

    ///
    /// \brief sends a StartCountdownPacket to every client, sends EndGamePacket should the maximum number of rounds be achieved
    ///
    void sendeRundenStart();

    ///
    /// \brief endGame
    ///
    void endGame();

    ///
    /// \brief sends a packet to every client
    /// \param packet that is to be sent
    ///
    void sendToAll(Packet& p);
public slots:
    /**
     * @brief triggered by signal playerJoined, creates new player object and saves connection id
     * @param PlayerJoinPacket
     * @param connection id client
     */
    void spieler_beitritt(PlayerJoinPacket packet, unsigned int id);
	
    ///
    /// \brief saves the received answers from every player, triggers awarding of points
    /// \param SendAnswersPacket
    /// \param connection id
    ///
    void bekommt_antwort(SendAnswersPacket packet, unsigned int id);

    ///
    /// \brief sends a RoundStartPacket with the round's letter to every player
    ///
    void startInput();

    ///
    /// \brief sends a PlayerFinishedPacket to every client
    ///
    void playerFinished();

    ///
    /// \brief sends an EndRoundPacket to every client
    ///
    void endInput();

    ///
    /// \brief emit signal initRoundEnd
    /// \param PlayerFinishedPacket
    /// \param connection id
    ///
    void bekommt_playerFinished(PlayerFinishedPacket packet, unsigned int id);

    ///
    /// \brief triggers sendeRundenStart
    ///
    void nextRound();

signals:
    void serverBereit();

    void initRoundEnd();

private:
    int m_answersReceived = 0;
    int m_currentRound = 0;

    ///
    /// \brief setupTimer
    ///
    void setupTimer();

    SpielerWarteRaum *warteRaum;
    QVector<Spieler> m_players;
    QVector<antworten> m_answers;
    QVector<punkte> m_points;
    char m_letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char m_usedLetters[26];
    ServerSocket serverSocket;
    Spieleinstellungen  m_einstellung ;
    char m_letter;
    timer *roundTimer = nullptr;
};
#endif
