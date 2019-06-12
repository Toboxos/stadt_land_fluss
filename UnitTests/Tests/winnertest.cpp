#include "winnertest.h"

WinnerTest::WinnerTest() {

}

void WinnerTest::run(ServerLogic* logic) {

    // Create a vector with players
    // Each player has different points for testing the leaderboard order
    QVector<Spieler> players;
    for( int i = 0; i < 5; ++i ) {
        QString name = "Player " + QString::number(i);
        Spieler player(name);

        switch( i ) {
            case 0:
                player.setPunkte(100);
                break;

           case 1:
                player.setPunkte(20);
                break;

           case 2:
                player.setPunkte(85);
                break;

           case 3:
                player.setPunkte(60);
                break;

           case 4:
                player.setPunkte(60);
                break;
        }

        players.push_back(player);
    }

    logic->m_players = players;

    EndGamePacket packet = logic->getWinner();

    QVector<int> points = packet.getPoints();
    QVector<QString> ranking = packet.getRanking();

    QCOMPARE(points.size(), 5);
    QCOMPARE(ranking.size(), 5);

    for( int i = 0 ; i < 5; ++i ) {
        switch( i ) {

            case 0:
                QCOMPARE(points[i], 100);
                QCOMPARE(ranking[i], "Player 0");
                break;

            case 1:
                QCOMPARE(points[i], 85);
                QCOMPARE(ranking[i], "Player 2");
                break;

            case 2:
                QCOMPARE(points[i], 60);
                QCOMPARE(ranking[i], "Player 3");
                break;

           case 3:
                QCOMPARE(points[i], 60);
                QCOMPARE(ranking[i], "Player 4");
                break;

           case 4:
                QCOMPARE(points[i], 20);
                QCOMPARE(ranking[i], "Player 1");
        }
    }
}
