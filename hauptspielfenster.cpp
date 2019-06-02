#include "hauptspielfenster.h"
#include "ui_hauptspielfenster.h"
#include "spielstart.h"
#include "stadtlandfluss.h"
#include "spieleinstellungen.h"
#include <spielerliste.h>
#include <QString>



HauptSpielFenster::HauptSpielFenster(QWidget *parent,ClientLogic *clientLogic) :
    QMainWindow(parent),
    ui(new Ui::HauptSpielFenster)
{
//...................................... todo Punkte und Buchstabenriehe enablen.....................................................................................................................................................
   _clientLogic = clientLogic;
    ui->setupUi(this);
    ui->tableSpiel->resizeColumnsToContents();
    int zeilenZaehler =2;


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
    _clientLogic->done();
}
HauptSpielFenster::~HauptSpielFenster()
{
    delete ui;
}

void HauptSpielFenster::on_buttonFertig_clicked()
{
// todo an server soll gemeldet werden dass ferttig, dann countdown runterzählen. bei end of countdown table enable und die einträge in array speichern.
}


