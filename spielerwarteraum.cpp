#include "spielerwarteraum.h"
#include "ui_spielerwarteraum.h"
#include "hauptspielfenster.h"
#include "kategorieeingabe.h"
#include "spieler.h"
#include <QTableWidgetItem>
#include "stdio.h"
#include "spielerliste.h"
#include "spieleinstellungen.h"

SpielerWarteRaum::SpielerWarteRaum(QWidget *parent, CLogik *serverLogic) :
    QDialog(parent),
    ui(new Ui::SpielerWarteRaum)
{

    ui->setupUi(this);
    _serverLogic = serverLogic;
    createTable();

}

SpielerWarteRaum::~SpielerWarteRaum()
{
    delete ui;
}
void SpielerWarteRaum::showPlayer(){
    createTable();
}
void SpielerWarteRaum::createTable()
{

    ui->labelSpielname->setText(_serverLogic->getSpieleinstellungen()->getSpielname());
    qDebug() << "jemand da" << endl;
    int reihenNummer=1;
    QVector<Spieler> spieler = *_serverLogic->getSpielerListe();
    qDebug() << spieler.size() << endl;
    auto end = spieler.end();
    for(auto it = spieler.begin(); it != end; it++,reihenNummer++ )
    {
        ui->tableSpieleruebersicht->setRowCount(reihenNummer);
        QTableWidgetItem tableItem;
        qDebug() << it->getName() << "test" << endl;
        ui->tableSpieleruebersicht->setItem(reihenNummer-1,1,new QTableWidgetItem(it->getName()));

      //  ui->tableSpieleruebersicht->setItem(reihenNummer-1,0,new QTableWidgetItem(QString::number(it->getId())));

    }
   }
void SpielerWarteRaum::on_buttonWeiter_clicked()
{

    close();
    //############################################ Hier wird ein Paket versendet mit den gameeinstellungen

 //   HauptSpielFenster *spielFenster = new HauptSpielFenster(nullptr, _clientLogic);
   //    spielFenster->show();

}

