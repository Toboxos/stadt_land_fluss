#include "clientlogic.h"
#include "spielstart.h"
#include "clientipeingabe.h"
#include "hauptspielfenster.h"
#include "statistic.h"
#include <QDebug>
ClientLogic::ClientLogic() : _ServerLogic(nullptr), _hautpSpielFenster(nullptr)
{

    SpielStart spielstart(nullptr, this);
    spielstart.exec();
}

ClientLogic::~ClientLogic() {
    delete _ServerLogic;
    delete _hautpSpielFenster;
}

void ClientLogic::closeGame(){
    qApp->exit();
}

void ClientLogic::setAnswerVector(QVector<QString> answerVector)
{
    _answerVector = answerVector;
}

void ClientLogic::connect(QString name, QString ip, quint16 port, ClientIpEingabe *window)
{

    _clientSocket.connectTo(ip,port);
   QObject::connect(&_clientSocket, SIGNAL(receivedGameSettings(GameSettingsPacket)), this, SLOT(starteSpiel(GameSettingsPacket)));
   QObject::connect(&_clientSocket, SIGNAL(playerJoined(PlayerJoinPacket)), this, SLOT(playerJoinedSlot(PlayerJoinPacket)));
   QObject::connect(&_clientSocket, SIGNAL(receivedPlayerList(PlayerListPacket)), this, SLOT(receivedPlayerListSlot(PlayerListPacket)));
   QObject::connect(&_clientSocket, SIGNAL(startCountdown(StartCountdownPacket)), this, SLOT(receivedStartCountdown(StartCountdownPacket)));
   QObject::connect(&_clientSocket, SIGNAL(roundStart(RoundStartPacket)), this, SLOT(receivedRoundStart(RoundStartPacket)));
   QObject::connect(&_clientSocket, SIGNAL(endGame(EndGamePacket)), this, SLOT(receivedEndGame(EndGamePacket)));
   QObject::connect(&_clientSocket, SIGNAL(endRound(EndRoundPacket)), this, SLOT(receivedRoundEnd(EndRoundPacket)));
   QObject::connect(&_clientSocket, SIGNAL(playerFinished(PlayerFinishedPacket)), this, SLOT(playerFinished(PlayerFinishedPacket)));
   QObject::connect(&_clientSocket, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
   QObject::connect(&_clientSocket, SIGNAL(connected()), this, SLOT(connectedSlot()));
   QObject::connect(&_clientSocket, SIGNAL(error()), this, SLOT(errorSlot()));
   QObject::connect(&_clientSocket, SIGNAL(pointsSent(SendPointsPacket)), this, SLOT(receivedPoints(SendPointsPacket)));
   if( window != nullptr ) QObject::connect(&_clientSocket, SIGNAL(connected()), window, SLOT(connected()));

}

void ClientLogic::receivedPoints(SendPointsPacket Packet){
    //update the player's points
    //shows the current total points in the game table
    clientSpieler.setPunkte(Packet.getTotalPoints());
    _hautpSpielFenster->setTotalPoints(clientSpieler.getPunkte());
}

void ClientLogic::openServerLogic() {
    //creates an object of ServerLogic
    _ServerLogic  = new ServerLogic();
    QObject::connect(_ServerLogic, SIGNAL(serverBereit()), this, SLOT(serverBereit()));
    _ServerLogic->run();
}

void ClientLogic::serverBereit() {
    connect(clientSpieler.getName(), "localhost", PORT, nullptr);
}

void ClientLogic::sendAnswers(){
    //gets the player's answer for the round
    //saves answers and sends them to the server
    _hautpSpielFenster->fillAnswerVector();
    clientSpieler.setAnswers(_hautpSpielFenster->getAnserVector());

    SendAnswersPacket packet(clientSpieler.m_answers);

    _clientSocket.send(packet);
    _hautpSpielFenster->clearAnswerVector();
}

void ClientLogic::playerJoinedSlot(PlayerJoinPacket Packet){
    this->_spielerListe.push_back(Packet.getName());
    //Anzeige?
}

void ClientLogic::receivedPlayerListSlot(PlayerListPacket Packet){
    for (unsigned int var = 0; var < Packet.getPlayers().size(); ++var) {
        this->_spielerListe.push_back(*new Spieler(Packet.getPlayers()[var]));
    }

    if( _hautpSpielFenster != nullptr ) {
        _hautpSpielFenster->setPlayers(Packet.getPlayers(), clientSpieler.getName());
    }
    //Anzeigen??
}

void ClientLogic::receivedStartCountdown(StartCountdownPacket packet){
    qDebug() << "Runde startet in 3 Sekunden";

    //updates the game table
    _hautpSpielFenster->newRow();
    //starts countdown to new round
    _hautpSpielFenster->startCountdown();
}

void ClientLogic::receivedRoundEnd(EndRoundPacket Packet){
    //sends answers and updates game table
    sendAnswers();
    _hautpSpielFenster->increaseCurrentRow();


    qDebug() << "Runde ist beendet, receivedRoundEnd";
}

void ClientLogic::timeoutSlot(){
    //timeout
    qDebug() << "Timeout :((" << endl;

}

void ClientLogic::connectedSlot(){
    //connects client's player with server
    PlayerJoinPacket playerJoinPacket(this->getSpieler().getName());
    _clientSocket.send(playerJoinPacket);
    qDebug() << "connected :))" << endl;
}

void ClientLogic::errorSlot(){
    //error
    qDebug() << "Error :(((" << endl;
}

void ClientLogic::openClientIpEingabe()
{
    //creates window for server ip address input
    ClientIpEingabe ClientStart(nullptr,this);
    ClientStart.exec();
}

void ClientLogic::openHauptSpielFenster(){
    //creates main game window
    _hautpSpielFenster = new HauptSpielFenster();
    QObject::connect(_hautpSpielFenster, SIGNAL(fertig()), this, SLOT(fensterFertig()));
    _hautpSpielFenster->show();
}

Spieler ClientLogic::getSpieler(){
    return clientSpieler;
}

void ClientLogic::setSpieler(Spieler spieler){
    clientSpieler = spieler;
}

void ClientLogic::playerFinished(PlayerFinishedPacket Packet){
    qDebug() << "Nur noch zehn Sekunden, beeile dich!";
    //upon receiving that one player is finished
    //triggers 10s countdown until the round ends
    _hautpSpielFenster->countdownSartet(_einstellung.getCountdown());
}

void ClientLogic::starteSpiel(GameSettingsPacket Packet){
    //adopt game settings
    //open main game window

    _einstellung.setCountdown(Packet.getCountown());
    _einstellung.setPlayName(Packet.getGameName());
    _einstellung.setRoundNumber(Packet.getRoundNumbers());
    _einstellung.setRoundTimeLimit(Packet.getRoundDuration());
    _einstellung.setKategories(Packet.getCategories());
    openHauptSpielFenster();
    _hautpSpielFenster->setCategories(Packet.getCategories());
}

void ClientLogic::fensterFertig() {
    //inform server that player has finished round

    PlayerFinishedPacket packet(getSpieler().getName());
    _clientSocket.send(packet);
}
void ClientLogic::receivedRoundStart(RoundStartPacket Packet){
    //pass on the letter's round and duration to the main game window

    _hautpSpielFenster->setLetter(Packet.getLetter());
    _hautpSpielFenster->startRound(_einstellung.getRundendauer());
}

void ClientLogic::receivedEndGame(EndGamePacket Packet){
    //get ranking from EndGamePacket
    //open statistic window

    QVector<QString> winner = Packet.getRanking();
    QVector<int> points = Packet.getPoints();
    Statistic statistic(nullptr,this, &winner, &points);
    statistic.exec();
}
