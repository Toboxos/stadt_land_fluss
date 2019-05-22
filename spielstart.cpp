#include "spielstart.h"
#include "spielerliste.h"
#include "clientipeingabe.h"

SpielStart::SpielStart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpielStart)
{
    ui->setupUi(this);
}

SpielStart::~SpielStart()
{
    delete ui;
}

void SpielStart::on_buttonHost_clicked()
{
    std::string name = "HOST_" + ui->NameEingabe->text().toStdString(); //Spieler wird Name zugewiesen
    Spieler hostSpieler(name);
    _spielerListe.push_back(hostSpieler); //pushback das neusete Element wird ans ende der Liste geschubst.
    close();
    HostSpielEinstellungen einstellungen;
    einstellungen.exec();

}

void SpielStart::on_NameEingabe_textEdited(const QString &arg1)
{
    ui->buttonHost->setEnabled(true);
    ui->buttonBeitreten->setEnabled(true);

}

void SpielStart::on_NameEingabe_returnPressed()
{
    on_buttonHost_clicked();
}

void SpielStart::on_buttonBeitreten_clicked()
{
    close();
    ClientIpEingabe ClientStart;
    ClientStart.exec();
}
