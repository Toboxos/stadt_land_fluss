#include "hostspieleinstellungen.h"
#include "ui_hostspieleinstellungen.h"
#include "kategorieeingabe.h"
#include "spielstart.h"
#include "spieleinstellungen.h"
#include "CLogik.h"
#include <QMessageBox>

/*###################################################################################
    Methode                 :
    Funktion der Methode    :
    Ersteller               : Alexandra Eberle
 ###################################################################################*/
HostSpielEinstellungen::HostSpielEinstellungen(QWidget *parent,CLogik *serverLogic) :
    QDialog(parent),
    ui(new Ui::HostSpielEinstellungen)
{

   ui->setupUi(this);

   _serverLogic = serverLogic;

   ui->buttonNext->setFocus();
   ui->inputGameName->setFocus();
}

HostSpielEinstellungen::~HostSpielEinstellungen()
{
    delete ui;
}
/*###################################################################################
    Methode                 : on_buttonWeiter_clicked()
    Funktion der Methode    :   Sobald auf den ButtonWeiter geklickt wird, werden die
                            Werte übernommen und in Vaiablen geschrieben.
                            Außerdem wird überprüft, dass keine Buchstaben und Werte
                            kleiner als Null eingegeben wurden.
    Ersteller               : Alexandra Eberle
 ###################################################################################*/
void HostSpielEinstellungen::on_buttonNext_clicked()
{
    bool correctUserEntry = true;
    QMessageBox box;
     // Abfrage dass bei den Runden kein Bullshit eingegeben wurde.
    if(ui->inputRoundNumber->text().toInt() == 0)
    {
        box.setText("Bitte keine Buchstaben eingeben");
        correctUserEntry = false;
        box.exec();

    }
    else if(ui->inputRoundNumber->text().toInt() >= 0)
    {
        _serverLogic->getSpieleinstellungen()->setRoundNumber(ui->inputRoundNumber->text().toInt());


    }
    else
    {
        box.setText("Bitte einen Wert größer als Null eingeben");
        correctUserEntry = false;
        box.exec();

    }

    // Abfrage, dass bei kein Bullshit steht.
    if(ui->inputRoundTimeLimit->text().toInt() == 0)
    {
        box.setText("Bitte keine Buchstaben eingeben");
        correctUserEntry = false;
        box.exec();

    }
    else if(ui->inputRoundTimeLimit->text().toInt() >= 0)
    {
        _serverLogic->getSpieleinstellungen()->setRoundTimeLimit(ui->inputRoundTimeLimit->text().toInt());

    }
    else
    {
        box.setText("Bitte einen Wert größer als Null eingeben");
        correctUserEntry = false;
        box.exec();

    }


    if(ui->inputCountdown->text().toInt() == 0)
    {
        box.setText("Bitte keine Buchstaben eingeben");
        correctUserEntry = false;
        box.exec();

    }
    else if(ui->inputCountdown->text().toInt() >= 0)
    {
        _serverLogic->getSpieleinstellungen()->setCountdown(ui->inputCountdown->text().toInt());

    }
    else
    {
        box.setText("Bitte einen Wert größer als Null eingeben");
        correctUserEntry = false;
        box.exec();

    }

    _serverLogic->getSpieleinstellungen()->setPlayName(ui->inputGameName->text());

    if (checkBoxChecked)
    {
        _serverLogic->getSpieleinstellungen()->setRoundNumber(99);  //Wert 99 steht für unendlich
    }
    else
    {
      _serverLogic->getSpieleinstellungen()->setRoundNumber(ui->inputRoundNumber->text().toInt());
    }

    if(correctUserEntry == true)
    {
    close();

    _serverLogic->openKategorieEingabe();


    }
    else {
        //do nothing
    }
}
/*###################################################################################
    Methode                 : on_buttonZurueck_click
    Funktion der Methode    : Die Variablen werden wieder resetet. Und auf das Fenster
                              "Spielstart" gewechslet.
    Ersteller               : Alexandra Eberle
 ###################################################################################*/



void HostSpielEinstellungen::on_checkBoxUnendlich_stateChanged(int arg1)
{

    ui->label->setText(QString::number(arg1));
    ui->buttonNext->setFocus();
    ui->inputRoundNumber->clear();
    if(arg1 !=0)
    {
        checkBoxChecked = true; //unendlich
    }
    else
    {
        checkBoxChecked = false; //nicht unendlich
    }
}




void HostSpielEinstellungen::on_inputGameName_textEdited(const QString &arg1)
{
    ui->buttonNext->setEnabled(true);
}
