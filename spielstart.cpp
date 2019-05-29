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


    std::string name = "HOST_" + ui->NameEingabe->text().toStdString(); //Spieler wird Name zugewiesen
    Spieler hostSpieler(name); // 0 muss ersetzt werden mit der Anzahl der Kategorien!!!
    _clientLogic->getSpielerListe()->push_back(hostSpieler); //pushback das neusete Element wird ans ende der Liste geschubst.
    close();
   _clientLogic->openCLogik();


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
    close();
    ClientIpEingabe ClientStart(nullptr, _clientLogic);
    ClientStart.exec();
}
