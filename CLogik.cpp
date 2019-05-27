#include "CLogik.h"
#include "spieler.h"

//erstellt einen Spieler
void CLogik::createPlayer(string n, int c) {
    Spieler spieler(n, c);
	//speichern in vector players
    players[spieler.getId()] = spieler;
}

//sortiert die Antworten in Kategorien nach Spieler
vector<std::string> CLogik::sortAnswers(unsigned int i) {
    unsigned int anzahl = players.size();
    vector<std::string> antworten;

    for (unsigned int var = 0; var < anzahl; ++var) {
        antworten[var] = players[var].getAnswer(i);
    }

   return antworten;
}

void CLogik::Punktevergabe(){
    unsigned int c = players[0].Categories();
    for (unsigned int var = 0;var < c; ++var) {
        answers[var]= sortAnswers(var);
    }

    for (unsigned int n; n < c; ++n){
        points[n] = awardPoints(n);
    }

}

std::vector<int> CLogik::awardPoints(unsigned int){

}

//gibt den Spieler mit der höchsten Gesamtpunktzahl zurück
//BESSER: gibt die Spieler nach Punktestand zurück
string CLogik::getWinner() {
    unsigned int n;
	int max;
	string name;

    n = players.size();
    max = players[0].getPunkte();
    name = players[0].getName();

    for(unsigned int i; i < n; i++){
        if (players[i].getPunkte() > max){
            max = players[i].getPunkte();
            name = players[i].getName();
        }
    }

	return name;
}
