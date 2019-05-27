#include "CLogik.h"
#include "spieler.h"
#include "antworten.h"
#include "punkte.h"

//erstellt einen Spieler
void CLogik::createPlayer(string n) {
    Spieler spieler(n);
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

    for (unsigned int n = 0; n < c; ++n){
        points[n] = awardPoints(n);
    }

    unsigned int anzahl = players.size();
    for (unsigned int m = 0; m < anzahl; ++m){
        Spieler player = players[m];
        int speicher = 0;
        for (unsigned int l = 0; l < c; ++l){
            vector<int> punkte = points[l].getPunkte();
            player.setCredit(l, punkte[l]);
            speicher = speicher + punkte[l];
        }

        int now = player.getPunkte();
        player.setPunkte(now + speicher);
    }

}

std::vector<int> CLogik::awardPoints(unsigned int i){
    vector<std::string> antworten = answers[i].getAntworten();
    unsigned int anzahl = antworten.size();
    vector<int> points;
    int sum = 0;

    for (unsigned int var = 0; var < anzahl; ++var) {
        if (antworten[var] == "empty"){
            points[var] = 0;
        }
        else {
            points[var] = 10;
        }
        for (unsigned int n = 0; n < anzahl; ++n) {
            if (n != var){
                if (antworten[var] == antworten [n]){
                    points[var] = 5;
                }
            }
        }
    }

    for (unsigned int v = 0; v < anzahl; ++v){
        for (unsigned int z = 0; z < anzahl; ++z){
            sum = sum + points[z];
        }
        if (sum == points[v]){
            points[v] = 20;
        }
    }

    return points;
}

//gibt den Spieler mit der höchsten Gesamtpunktzahl zurück
//BESSER: gibt die Spieler nach Punktestand zurück
vector<std::string> CLogik::getWinner() {
    unsigned int anzahl = players.size();
	int max;
    vector<std::string> names;

    for (unsigned int n = 0; n < anzahl; ++n){
        names[n] = players[n].getName();

    }

    /*
    max = players[0].getPunkte();
    name = players[0].getName();

    for(unsigned int i = 0; i < n; i++){
        if (players[i].getPunkte() > max){
            max = players[i].getPunkte();
            name = players[i].getName();
        }
    }*/

    return names;
}
