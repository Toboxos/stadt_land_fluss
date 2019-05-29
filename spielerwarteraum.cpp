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
    QObject::connect(serverLogic, SIGNAL(showPlayer(Spieler)), this, SLOT(onPlayerJoined(Spieler)));


    createTable();

}

SpielerWarteRaum::~SpielerWarteRaum()
{
    delete ui;
}
void SpielerWarteRaum::onPlayerJoined(Spieler newPlayer){

    createTable();
}
void SpielerWarteRaum::createTable()
{

    ui->labelSpielname->setText(_serverLogic->getSpieleinstellungen()->getSpielname());

    int reihenNummer=1;
    for(QVector<Spieler>::iterator it = _serverLogic->getSpielerListe()->begin(); it != _serverLogic->getSpielerListe()->end(); it++,reihenNummer++ )
    {
        ui->tableSpieleruebersicht->setRowCount(reihenNummer);
        QTableWidgetItem tableItem;

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

