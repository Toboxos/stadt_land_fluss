#include "lettertest.h"

LetterTest::LetterTest() {

}

void LetterTest::run(ServerLogic *logic) {

    // Used letters are indicated with true at letter index position
    // letter index is orrucent in alphabet
    bool usedLetters[26];
    for( int i = 0; i < 26; ++i ) {
        usedLetters[i] = false;
    }

    // generate 26 times a letter. Each time the letter should be different from all before
    for( int i = 0; i < 26; ++i ) {
        char letter = logic->getLetter();
        int index = letter - 'a';
        qDebug() << "[" << i << "]" << "Letter generated: " << letter;

        QVERIFY(letter >= 'a' && letter <= 'z');
        QCOMPARE(usedLetters[index], false);

        usedLetters[index] = true;
    }
}
