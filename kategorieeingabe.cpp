#include "kategorieeingabe.h"
#include "ui_kategorieeingabe.h"
#include "spielerwarteraum.h"
#include "hostspieleinstellungen.h"
#include "spielstart.h"
#include "spieleinstellungen.h"
#include <QTableView>
#include <QStandardItem>
#include <QString>


Kategorieeingabe::Kategorieeingabe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kategorieeingabe)
{

    ui->setupUi(this);
    ui->tableKategorie->setColumnCount(1);
    ui->tableKategorie->setHorizontalHeaderItem(0,new QTableWidgetItem("Buchstabe"));

}

Kategorieeingabe::~Kategorieeingabe()
{
    delete ui;
}

void Kategorieeingabe::on_buttonWeiter_clicked()
{
    close();
    SpielerWarteRaum warteRaum;
    warteRaum.exec();
}

void Kategorieeingabe::on_buttonZurueck_clicked()
{
    close();
    HostSpielEinstellungen einstellungen;
    einstellungen.exec();

}

void Kategorieeingabe::on_buttonHinzufuegen_clicked()
{
    QString kategorie = ui->einlesenKategorie->text();
    _einstellung->setKategorienlListe(kategorie.toStdString());

    ui->tableKategorie->setColumnCount(kategorieZaehler);

    QTableWidgetItem* qtwi = new QTableWidgetItem(QString(kategorie),QTableWidgetItem::Type);
    ui->tableKategorie->setHorizontalHeaderItem(kategorieZaehler-1,qtwi);
    ui->tableKategorie->setColumnCount(kategorieZaehler+1);
    ui->tableKategorie->setHorizontalHeaderItem(kategorieZaehler,new QTableWidgetItem("Punkte"));

    ui->buttonWeiter->setEnabled(true);
    ui->einlesenKategorie->clear();
    kategorieZaehler++;
}

void Kategorieeingabe::on_inputCategorie_textEdited(const QString &arg1)
{
    ui->buttonHinzufuegen->setEnabled(true);
}


