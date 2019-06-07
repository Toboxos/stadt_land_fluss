#include "hauptspielfenster.h"
#include "ui_hauptspielfenster.h"
#include "spielstart.h"
#include "stadtlandfluss.h"
#include "spieleinstellungen.h"
#include <spielerliste.h>
#include <QString>


HauptSpielFenster::HauptSpielFenster(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HauptSpielFenster)
{
    ui->setupUi(this);
    ui->tableSpiel->resizeColumnsToContents();
    currentRow = 0;
    ui->tableSpiel->setRowCount(0);

}

void HauptSpielFenster::setCategories(QVector<QString> categories) {
    ui->tableSpiel->setColumnCount(categories.size());
    ui->tableSpiel->setHorizontalHeaderLabels(QStringList::fromVector(categories));
    ui->tableSpiel->setRowCount(1);
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

///
/// \brief HauptSpielFenster::ready
///
///
void HauptSpielFenster::fillAnswerVector()
{

    for (int columCount = 0; columCount < ui->tableSpiel->columnCount(); ++columCount)
    {
        answerVector.push_back(ui->tableSpiel->item(currentRow,columCount)->text());
    }
   ui->tableSpiel->setEnabled(true);
}
QVector<QString> HauptSpielFenster::getAnserVector()
{
    return answerVector;
}

HauptSpielFenster::~HauptSpielFenster()
{
    delete ui;
    delete item;
}
void HauptSpielFenster::startCountdown(){
    box.setText("Die Runde startet in 3 Sekunden");
    box.open();
    //Zeige an, dass das Spiel in 3 Sekunden Startet

}
void HauptSpielFenster::enableUserinput(char letter){
    box.close();
    setLetter(letter);
    qDebug() << "Box sollte zu sein";
    //erlaube benutzerinput also gebe die Runde frei
}
void HauptSpielFenster::setLetter(char letter){
    QString letterString(letter);
    if(ui->tableSpiel->item(0,0)==nullptr){

        item = new QTableWidgetItem(letterString, 0);
        item->setText(letterString);
        ui->tableSpiel->setItem(0,0,item);

    }else{

        ui->tableSpiel->item(0,0)->setText(letterString);

    }
    ui->tableSpiel->update();
}
void HauptSpielFenster::on_buttonFertig_clicked()
{

// bei end of countdown table enable und die einträge in array speichern.
// reihe disabel
   fillAnswerVector();
   emit fertig();
}

void HauptSpielFenster::newRow() {
    ++currentRow;
    ui->tableSpiel->setRowCount(currentRow);

}


