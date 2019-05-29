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

Kategorieeingabe::Kategorieeingabe(QWidget *parent,ClientLogic *clientLogic) :
    QDialog(parent),
    ui(new Ui::Kategorieeingabe)
{
     _clientLogic = clientLogic;
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
    SpielerWarteRaum warteRaum(nullptr, _clientLogic);
    warteRaum.exec();
}

void Kategorieeingabe::on_buttonZurueck_clicked()
{
    close();
    HostSpielEinstellungen einstellungen(nullptr, _clientLogic);
    einstellungen.exec();

}

void Kategorieeingabe::on_buttonHinzufuegen_clicked()
{
    QString kategorie = ui->einlesenKategorie->text();

    if(_clientLogic->getSpieleinstellungen()->addKategorie(kategorie.toStdString())){


    ui->tableKategorie->setColumnCount(kategorieZaehler);

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



