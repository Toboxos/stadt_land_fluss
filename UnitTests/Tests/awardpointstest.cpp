#include "awardpointstest.h"
#include "spieler.h"

AwardPointsTest::AwardPointsTest() {
    srand(time(nullptr));
}

void AwardPointsTest::run(CLogik *logic) {
    // Spieler erzeugen
    for( unsigned int i = 0; i < 3; ++i ) {
        Spieler player("Player " + QString::number(i));
        QVector<QString> answers;

        switch( i ) {
            case 0: {
                answers.push_back("augsburg");
                answers.push_back("algerien");
                answers.push_back("");
                break;
            }

            case 1: {
                answers.push_back("aachen");
                answers.push_back("albanien");
                answers.push_back("");
                break;
            }

            case 2: {
                answers.push_back("");
                answers.push_back("albanien");
                answers.push_back("aland");
                break;
            }
        }

        player.setAnswers(answers);
        logic->players.push_back(player);
    }

    // Test is made for letter a
    logic->m_letter = 'a';

    // For each categorie sort the answers for the ServerLogic
    for( int i = 0; i < 3; ++i ) {
        QVector<QString> answers = logic->sortAnswers(i);
        QCOMPARE(answers.size(), 3);

        switch( i ) {
            case 0: {
                QCOMPARE(answers[0], "augsburg");
                QCOMPARE(answers[1], "aachen");
                QCOMPARE(answers[2], "");
                break;
            }

            case 1: {
                QCOMPARE(answers[0], "algerien");
                QCOMPARE(answers[1], "albanien");
                QCOMPARE(answers[2], "albanien");
                break;
            }

            case 2: {
                QCOMPARE(answers[0], "");
                QCOMPARE(answers[1], "");
                QCOMPARE(answers[2], "aland");
                break;
            }
        }

        logic->m_answers.push_back(answers);
    }

    // Test points for all categories
    for( unsigned int i = 0 ; i < 3; ++i ) {
        QVector<int> points = logic->awardPoints(i);
        switch( i ) {
            case 0: {
                QCOMPARE(points[0], 10);
                QCOMPARE(points[1], 10);
                QCOMPARE(points[2], 0);
                break;
            }

            case 1: {
                QCOMPARE(points[0], 10);
                QCOMPARE(points[1], 5);
                QCOMPARE(points[2], 5);
                break;
            }

            case 2: {
                QCOMPARE(points[0], 0);
                QCOMPARE(points[1], 0);
                QCOMPARE(points[2], 20);
                break;
            }
        }
    }
}
