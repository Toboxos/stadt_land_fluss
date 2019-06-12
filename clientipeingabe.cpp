#include "clientipeingabe.h"
#include "ui_clientipeingabe.h"
#include "spielstart.h"
#include "hauptspielfenster.h"
#include "Network/clientsocket.h"
#include "Network/Packets/playerjoinpacket.h"



ClientIpEingabe::ClientIpEingabe(QWidget *parent,ClientLogic *clientLogic) :
    QDialog(parent),
    ui(new Ui::ClientIpEingabe)
{
    _clientLogic = clientLogic;
    ui->setupUi(this);
    ui->eingabeIp->setInputMask("000.000.000.000");
}

ClientIpEingabe::~ClientIpEingabe()
{
    delete ui;
}

void ClientIpEingabe::on_eingabeIp_textEdited(const QString &arg1)
{
    ui->buttonWeiter->setEnabled(true);
}



void ClientIpEingabe::on_buttonWeiter_clicked()
{

    _clientLogic->connect(_clientLogic->getSpieler().getName(),ui->eingabeIp->text(),PORT, this);



}
void ClientIpEingabe::connected()
{
    close();

}
