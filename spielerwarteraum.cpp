#include "spielerwarteraum.h"
#include "ui_spielerwarteraum.h"
#include "hauptspielfenster.h"
#include "kategorieeingabe.h"
#include "spieler.h"
#include <QTableWidgetItem>
#include "stdio.h"
#include "spielerliste.h"
#include "spieleinstellungen.h"

SpielerWarteRaum::SpielerWarteRaum(QWidget *parent,ClientLogic *clientLogic) :
    QDialog(parent),
    ui(new Ui::SpielerWarteRaum)
{

    ui->setupUi(this);
    _clientLogic = clientLogic;

    ui->labelSpielname->setText(QString::fromStdString(_clientLogic->getSpieleinstellungen()->getSpielname()));
    int reihenNummer=1;
    for(std::vector<Spieler>::iterator it = _clientLogic->getSpielerListe()->begin(); it != _clientLogic->getSpielerListe()->end(); it++,reihenNummer++ )
    {
        ui->tableSpieleruebersicht->setRowCount(reihenNummer);
        QTableWidgetItem tableItem;

        ui->tableSpieleruebersicht->setItem(reihenNummer-1,1,new QTableWidgetItem(QString::fromStdString(it->getName())));

        ui->tableSpieleruebersicht->setItem(reihenNummer-1,0,new QTableWidgetItem(QString::number(it->getId())));

    }
}

SpielerWarteRaum::~SpielerWarteRaum()
{
    delete ui;
}

void SpielerWarteRaum::on_buttonWeiter_clicked()
{

    close();
    HauptSpielFenster *spielFenster = new HauptSpielFenster(nullptr, _clientLogic);
       spielFenster->show();

}

