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
//...................................... todo Punkte und Buchstabenriehe enablen.....................................................................................................................................................
    ui->setupUi(this);
    ui->tableSpiel->resizeColumnsToContents();
    currentRow = 0;


    ui->tableSpiel->setRowCount(0);
    //ui->tableSpiel->resizeColumnsToContents();
    //ui->tableSpiel->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
   /*
    *  QVector<QString> kategorienVector=std::move( _clientLogic->getSpieleinstellungen()->getKategorienListe());
    ui->tableSpiel->setColumnCount(1);
    ui->tableSpiel->setHorizontalHeaderItem(0,new QTableWidgetItem("Buchstabe"));
    for (QVector<QString>::iterator iter = kategorienVector.begin() ;iter!=kategorienVector.end();iter++,zeilenZaehler++)
    {
        ui->tableSpiel->setColumnCount(zeilenZaehler);
        QTableWidgetItem* qtwi = new QTableWidgetItem(QString::fromStdString(*iter),QTableWidgetItem::Type);
        ui->tableSpiel->setHorizontalHeaderItem(zeilenZaehler-1,qtwi);
    }
    ui->tableSpiel->setColumnCount(zeilenZaehler);
    ui->tableSpiel->setHorizontalHeaderItem(zeilenZaehler-1,new QTableWidgetItem("Punkte"));

    ui->tableSpiel->setRowCount(2);
    */
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

///
/// \brief HauptSpielFenster::ready
///
///
void HauptSpielFenster::ready()
{
   QVector<QString> answerVector ;
    for (int columCount = 0; columCount < ui->tableSpiel->columnCount(); ++columCount) {

        answerVector.push_back(ui->tableSpiel->item(0,columCount)->text());

    }
}
HauptSpielFenster::~HauptSpielFenster()
{
    delete ui;
}

void HauptSpielFenster::on_buttonFertig_clicked()
{
// todo an server soll gemeldet werden dass ferttig, dann countdown runterzählen. bei end of countdown table enable und die einträge in array speichern.
// reihe disabel
    emit fertig();
}

void HauptSpielFenster::newRow() {
    ++currentRow;
    ui->tableSpiel->setRowCount(currentRow);

}


