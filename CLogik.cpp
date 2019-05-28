#include "CLogik.h"
#include "spieler.h"
#include "antworten.h"
#include "punkte.h"

CLogik::CLogik(){
    connect(&serverSocket, SIGNAL(playerJoined(PlayerJoinPacket, unsigned int)), this, SLOT(spieler_beitritt(PlayerJoinPacket, unsigned int)));
    serverSocket.listen(PORT);
}

void CLogik::spieler_beitritt(PlayerJoinPacket packet, unsigned int id){
    Spieler spieler(packet.getName().toStdString());
    players.push_back(spieler);

    spieler.setConnectionId(id);

    qDebug() << "Spieler beigetreten";

    for (unsigned int var = 0; var < players.size(); ++var) {
        std::cout << players[var].getName() << std::endl;
    }

}

/// erhält den Spielernamen als string
/// erstellt einen Spielerobjekt und speichert es im vector players ab
/// gibt Spieler ID zurück
int CLogik::createPlayer(string name) {
    Spieler spieler(name);
	//speichern in vector players
    players[spieler.getId()] = spieler;
    return spieler.getId();
}

///speichert die Antworten aller Spieler geordnet in einen vector für eine Kategorie
///int anzahl = Anzahl der Spieler
///Rückgabe: vector<string> antwortenKategorie
vector<std::string> CLogik::sortAnswers(unsigned int category) {
    unsigned int anzahl = players.size();
    vector<std::string> antwortenKategorie;

    for (unsigned int var = 0; var < anzahl; ++var) {
        antwortenKategorie[var] = players[var].getAnswer(category);
    }

   return antwortenKategorie;
}

void CLogik::Punktevergabe(){
    /// unsigned int categories = Anzahl Kategorien
    unsigned int categories = players[0].Categories();

    /// sortiert Antworten nach Kategorie für alle Kategorien
    /// speichert vector<string> in ein Objekt "answers" für eine Kategorie
    for (unsigned int var = 0;var < categories; ++var) {
        answers[var]= sortAnswers(var);
    }

    /// gibt Punkte für Kategorie für alle Kategorien
    /// speichert vector<int> mit Punkten von einer Kategorie in ein Objekt "points"
    for (unsigned int n = 0; n < categories; ++n){
        points[n] = awardPoints(n);
    }

    /// unsigned int anzahl = Spieleranzahl
    unsigned int anzahl = players.size();

    for (unsigned int m = 0; m < anzahl; ++m){
        /// für jedes Spielerobjekt
        Spieler player = players[m];

        /// int speicher = Zwischenspeicher für Gesamtpunktzahl
        int speicher = 0;

        /// speichert die Punkte für einen Spieler in der aktuellen Runde im jew. Spielerobjekt
        for (unsigned int l = 0; l < categories; ++l){
            ///vector<int> punkte = Zwischenspeicher für
            vector<int> punkte = points[l].getPunkte();
            player.setCredit(l, punkte[l]);
            speicher = speicher + punkte[l];
        }

        /// int jetzt = aktueller Gesamtpunktestand
        /// fügt dem Gesamtpunktestand des jew. Spielerobjekts die zwischengespeicherten Punkte der aktuellen Runde hinzu
        int jetzt = player.getPunkte();
        player.setPunkte(jetzt + speicher);
    }

}

//gibt die Punkte für eine Kategorie
std::vector<int> CLogik::awardPoints(unsigned int category){
    ///
    vector<std::string> antworten = answers[category].getAntworten();
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


//gibt die Spieler nach Gesamtpunktzahl geordnet zurück
vector<std::string> CLogik::getWinner() {
    unsigned int anzahl = players.size();
    vector<std::string> names;
    vector<int> allPoints;

    for (unsigned int var = 0; var < anzahl; ++var) {
        allPoints[var] = players[var].getPunkte();
    }

    bool sorted = false;

    while(!sorted){
        sorted = true;

        for (unsigned int i = 0;i < anzahl; ++i) {

            if (allPoints[i]<allPoints[i+1]){
                int temp = allPoints[i];
                allPoints[i] = allPoints[i+1];
                allPoints[i+1] = temp;
            }

            sorted = false;
        }
    }

    for (unsigned int n = 0; n < anzahl; ++n) {
        for (unsigned int p = 0; p < anzahl; ++p){
            if (allPoints[n] = players[p].getPunkte()){
                names[n] = players[p].getName();
            }
        }


    }
    return names;
}

char CLogik::getLetter(){
    if (usedLetters[25] != 0x00){
        for (int var = 0; var < 26; ++var) {
            usedLetters[var] = 0x00;
        }
    }

    char letter;
    bool success = false;

    while(!success){
    int choose = rand() % 26;
    success = true;
    letter = letters[choose];

    for (int var = 0; var < 26; ++var) {
        if (usedLetters[var] = letter){
            success = false;
        }
    }

    }

    return letter;
}
