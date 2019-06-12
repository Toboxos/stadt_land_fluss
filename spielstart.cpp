#include "spielstart.h"
#include "spielerliste.h"

#include "clientipeingabe.h"

SpielStart::SpielStart(QWidget *parent, ClientLogic *clientLogic) :
    QDialog(parent),
    ui(new Ui::SpielStart)
{
    _clientLogic = clientLogic;
    ui->setupUi(this);
}

SpielStart::~SpielStart()
{
    delete ui;
}

void SpielStart::on_buttonHost_clicked()
{

// Spieler Join Paket senden

    QString name = "HOST_" + ui->NameEingabe->text(); //Spieler wird Name zugewiesen
    Spieler hostSpieler(name); // 0 muss ersetzt werden mit der Anzahl der Kategorien!!!

    //_clientLogic->getSpielerListe()->push_back(hostSpieler); //pushback das neusete Element wird ans ende der Liste geschubst.

    close();
   _clientLogic->setSpieler(hostSpieler);
   _clientLogic->openServerLogic();


}

void SpielStart::on_NameEingabe_textEdited(const QString &arg1)
{
    ui->buttonHost->setEnabled(true);
    ui->buttonBeitreten->setEnabled(true);

}

void SpielStart::on_NameEingabe_returnPressed()
{
    on_buttonBeitreten_clicked();
}

void SpielStart::on_buttonBeitreten_clicked()
{   
    Spieler spieler(ui->NameEingabe->text());
    _clientLogic->setSpieler(spieler);
    close();
    _clientLogic->openClientIpEingabe();
}
