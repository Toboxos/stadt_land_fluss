#include "clientipeingabe.h"
#include "ui_clientipeingabe.h"
#include "spielstart.h"
#include "hauptspielfenster.h"
#include "Network/clientsocket.h"


ClientIpEingabe::ClientIpEingabe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientIpEingabe)
{
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
//...................................................................................
// todo überlegen wie das umzusetzen ist.
/*void ClientIpEingabe::on_buttonWeiter_clicked()
{
    close();
    HauptSpielFenster hauptspielFenster;
    hauptspielFenster.show();
}
*/

void ClientIpEingabe::on_buttonWeiter_clicked()
{
   ClientSocket clientSocket;
   clientSocket.connectTo(ui->eingabeIp->text(),5);
}
