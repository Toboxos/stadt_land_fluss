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
    for (int columCount = 1; columCount < (ui->tableSpiel->columnCount()) -1; ++columCount)
    {
        if(ui->tableSpiel->item(currentRow,columCount) != nullptr)
            answerVector.push_back(ui->tableSpiel->item(currentRow,columCount)->text());           
        else
            answerVector.push_back("");
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
    m_points.clear();
    m_letters.clear();
}
void HauptSpielFenster::startCountdown(){
    box.setText("Die Runde startet in 3 Sekunden");
    box.open();
}
void HauptSpielFenster::setLetter(char letter){
    box.close();
    QString letterString(letter);
    if(ui->tableSpiel->item(currentRow,0)==nullptr){
        m_letters.push_back(new QTableWidgetItem(0));
        m_letters.last()->setText(letterString);
        ui->tableSpiel->setItem(currentRow,0,m_letters.last());

    }else{
        ui->tableSpiel->item(currentRow,0)->setText(letterString);

    }
    ui->tableSpiel->update();
    ui->tableSpiel->setEditTriggers(QAbstractItemView::AllEditTriggers);
}
void HauptSpielFenster::setTotalPoints(int points){
    m_points.push_back( new QTableWidgetItem(0));
    m_points.last()->setText(QString::number(points));
    ui->tableSpiel->setItem(currentRow-1, ui->tableSpiel->columnCount()-1, m_points.last());

}
void HauptSpielFenster::on_buttonFertig_clicked()
{
   emit fertig();
   ui->tableSpiel->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
void HauptSpielFenster::newRow() {
    ++currentRow;
    qDebug() << "newRow: " <<currentRow;
    //ui->tableSpiel->insertRow(currentRow);
    ui->tableSpiel->setRowCount(currentRow+1);
    ui->tableSpiel->update();

}
void HauptSpielFenster::clearAnswerVector(){
    answerVector.clear();
}

