#include "clientipeingabe.h"
#include "ui_clientipeingabe.h"
#include "spielstart.h"
#include "spielerliste.h"
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

void ClientIpEingabe::on_buttonZurueck_clicked()
{
    close();
    SpielStart start;
    start.exec();
}

void ClientIpEingabe::on_buttonWeiter_clicked()
{

    _clientLogic->connect(_clientLogic->getSpieler().getName(),ui->eingabeIp->text(),PORT);

   /*_clientSocket.connectTo(ui->eingabeIp->text(),PORT);
   PlayerJoinPacket playerJoinPacket("hildegart");
   _clientSocket.send(playerJoinPacket);
*/



}
void ClientIpEingabe::connected()
{
    close();
    HauptSpielFenster hauptSpielFenster(nullptr, _clientLogic);
    hauptSpielFenster.show();

}
