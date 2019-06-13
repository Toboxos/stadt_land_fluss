#include "kategorieeingabe.h"
#include "ui_kategorieeingabe.h"
#include "spielerwarteraum.h"
#include "hostspieleinstellungen.h"
#include "spielstart.h"
#include "spieleinstellungen.h"
#include <QTableView>
#include <QStandardItem>
#include <QString>
#include <QMessageBox>


Kategorieeingabe::Kategorieeingabe(QWidget *parent,ServerLogic *serverLogic) :

    QDialog(parent),
    ui(new Ui::Kategorieeingabe)
{
     _serverLogic = serverLogic;
    ui->setupUi(this);
    ui->tableKategorie->setColumnCount(1);
    ui->tableKategorie->setHorizontalHeaderItem(0,new QTableWidgetItem("Buchstabe"));
    _serverLogic->getSpieleinstellungen()->addKategorie("Buchstabe");


}

Kategorieeingabe::~Kategorieeingabe()
{
    delete ui;
}

void Kategorieeingabe::on_buttonWeiter_clicked()
{
    _serverLogic->getSpieleinstellungen()->addKategorie("Punkte");
    close();
    _serverLogic->openSpielerWarteRaum();

}

void Kategorieeingabe::on_buttonZurueck_clicked()
{
    close();
    _serverLogic->openHostSpielEinstellungen();

}

void Kategorieeingabe::on_buttonHinzufuegen_clicked()
{
    QString kategorie = ui->einlesenKategorie->text();


    if(_serverLogic->getSpieleinstellungen()->addKategorie(kategorie)){



    ui->tableKategorie->setColumnCount(kategorieZaehler);

    // pointer will deletet by table, no deletion needed from user
    QTableWidgetItem* qtwi = new QTableWidgetItem(QString(kategorie),QTableWidgetItem::Type);
    ui->tableKategorie->setHorizontalHeaderItem(kategorieZaehler-1,qtwi);
    ui->tableKategorie->setColumnCount(kategorieZaehler+1);
    ui->tableKategorie->setHorizontalHeaderItem(kategorieZaehler,new QTableWidgetItem("Punkte"));

    ui->buttonWeiter->setEnabled(true);
    ui->einlesenKategorie->clear();
    kategorieZaehler++;
    }else {
    QMessageBox box;
    box.setText("Diese Kategorie hast du bereits eingegeben");
    box.exec();
}
}

void Kategorieeingabe::on_einlesenKategorie_textEdited(const QString &arg1)
{
    ui->buttonHinzufuegen->setEnabled(true);
}



