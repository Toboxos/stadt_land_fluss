#include "hauptspielfenster.h"
#include "ui_hauptspielfenster.h"
#include "spielstart.h"
#include "stadtlandfluss.h"
#include "spieleinstellungen.h"
#include <QString>


HauptSpielFenster::HauptSpielFenster(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HauptSpielFenster)
{
    ui->setupUi(this);

    ui->tableSpiel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    currentRow = 0;
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
    m_timer.setInterval(1000);


}
void HauptSpielFenster::increaseCurrentRow()
{
    currentRow++;
}
void HauptSpielFenster::setCategories(QVector<QString> categories) {
    ui->tableSpiel->setColumnCount(categories.size());
    ui->tableSpiel->setHorizontalHeaderLabels(QStringList::fromVector(categories));


}

void HauptSpielFenster::setPlayers(QVector<QString> players, QString clientName) {
    ui->listSpieler->clear();

    for( int i = 0; i < players.size(); ++i ) {
        if( players[i] == clientName ) {
            players[i] = "<" + players[i] + ">";
        }
        ui->listSpieler->addItem(players[i]);
    }
}


void HauptSpielFenster::fillAnswerVector()
{
    for (int columCount = 1; columCount < (ui->tableSpiel->columnCount()) -1; ++columCount)
    {
        if(ui->tableSpiel->item(currentRow,columCount) != nullptr)
            answerVector.push_back(ui->tableSpiel->item(currentRow,columCount)->text());
        else
            answerVector.push_back("");
    }
   ui->tableSpiel->setEnabled(false);
}
QVector<QString> HauptSpielFenster::getAnserVector() {

    return answerVector;
}
HauptSpielFenster::~HauptSpielFenster()
{
    delete ui;

    for( int i = 0; i < m_points.size(); ++i ) {
        delete m_points[i];
    }

    for(int i = 0; i < m_letters.size(); ++i ) {
        delete m_letters[i];
    }
}
void HauptSpielFenster::startCountdown(){
    ui->buttonFertig->setText("F\nE\nR\nT\nI\nG");
    ui->buttonFertig->setStyleSheet("background-color: rgba(0, 204, 0, 0.8);");
    ui->buttonFertig->setEnabled(true);
    ui->tableSpiel->setEnabled(true);
    box.setText("Die Runde startet in 3 Sekunden");
    box.open();

}
void HauptSpielFenster::setLetter(char letter){
    box.close();
    QString letterString(letter);
    qDebug() << "Row" << currentRow;
    if(ui->tableSpiel->item(currentRow,0)==nullptr){
        m_letters.push_back(new QTableWidgetItem(0));
        m_letters.last()->setText(letterString);
        ui->tableSpiel->setItem(currentRow,0,m_letters.last());

    }else{
        ui->tableSpiel->item(currentRow,0)->setText(letterString);
    }

    ui->tableSpiel->item(currentRow,0)->setFlags(Qt::ItemIsEnabled);
    ui->tableSpiel->update();
    ui->tableSpiel->setEditTriggers(QAbstractItemView::AllEditTriggers);
}
void HauptSpielFenster::setTotalPoints(int points){
    m_points.push_back( new QTableWidgetItem(0));
    m_points.last()->setText(QString::number(points));

    ui->tableSpiel->setItem(currentRow-1, ui->tableSpiel->columnCount()-1, m_points.last());
    //diable cells for writing
    for (int columCount =0; columCount < ui->tableSpiel->columnCount(); columCount++)
    {

        if( ui->tableSpiel->item(currentRow-1,columCount) != nullptr)
            ui->tableSpiel->item(currentRow-1,columCount)->setFlags(Qt::ItemIsEnabled);

    }


}
void HauptSpielFenster::on_buttonFertig_clicked()
{

    if (obSpielerwirklichFertigIst())
    {
        emit fertig();
        ui->tableSpiel->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    else
    {
        //do nothing
    }
}

bool HauptSpielFenster::obSpielerwirklichFertigIst()
{
    bool fertig = true;
    for (int columCount = 1; columCount < (ui->tableSpiel->columnCount()) -1; ++columCount)
    {
        if(ui->tableSpiel->item(currentRow,columCount) == nullptr)
        {
            fertig = false;
        }
        else
        {
            //do nothing
        }
    }

    if (fertig)
    {
        ui->buttonFertig->setEnabled(false);
    }
    else
    {
        box.setText("Du bist doch noch gar nicht Fertig.\n Versuche es nocheinmal");
        box.exec();
    }
    return fertig;
}
void HauptSpielFenster::newRow() {
    ui->tableSpiel->setRowCount(currentRow+1);
    ui->tableSpiel->update();

}
void HauptSpielFenster::clearAnswerVector(){
    answerVector.clear();
}

void HauptSpielFenster::countdownSartet(int countdown)
{
   ui->buttonFertig->setText("C\nO\nU\nN\nT\nD\nO\nW\nN");
   ui->buttonFertig->setStyleSheet("background-color: rgba(225, 0, 0, 0.8);");
   ui->buttonFertig->setEnabled(false);
   m_timeRemaining = countdown;
   ui->lblStatus->setText("Zeit verbleibend: " + QString::number(m_timeRemaining) + "s");
   m_timer.start();
}

void HauptSpielFenster::startRound(int time) {
    m_timeRemaining = time * 60;
    ui->lblStatus->setText("Zeit verbleibend: " + QString::number(m_timeRemaining) + "s");
    m_timer.start();
}

void HauptSpielFenster::timerEvent() {
    ui->lblStatus->setText("Zeit verbleibend: " + QString::number(--m_timeRemaining) + "s");

    if( m_timeRemaining == 0 )
    {
        m_timer.stop();
    }
}
