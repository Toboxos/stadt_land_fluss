#include "Hostspieleinstellungen.h"
#include "ui_hostspieleinstellungen.h"
#include "kategorieeingabe.h"
#include "spielstart.h"
#include "spieleinstellungen.h"
#include <QMessageBox>

/*###################################################################################
    Methode                 :
    Funktion der Methode    :
    Ersteller               : Alexandra Eberle
 ###################################################################################*/
HostSpielEinstellungen::HostSpielEinstellungen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HostSpielEinstellungen)
{

   ui->setupUi(this);
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
void HostSpielEinstellungen::on_buttonWeiter_clicked()
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
        _einstellung->setRoundNumber(ui->inputRoundNumber->text().toInt());

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
        _einstellung->setRoundTimeLimit(ui->inputRoundTimeLimit->text().toInt());

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
        _einstellung->setCountdown(ui->inputCountdown->text().toInt());

    }
    else
    {
        box.setText("Bitte einen Wert größer als Null eingeben");
        correctUserEntry = false;
        box.exec();

    }

    _einstellung->setPlayName(ui->inputGameName->text().toStdString());

    if (checkBoxChecked)
    {
        _einstellung->setRoundNumber(99);  //Wert 99 steht für unendlich
    }
    else
    {
        _einstellung->setRoundNumber(ui->inputRoundNumber->text().toInt());
    }

    if(correctUserEntry == true)
    {
    close();
        Kategorieeingabe eingabe;
        eingabe.exec();
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

void HostSpielEinstellungen::on_buttonZurueck_clicked()
{

    _einstellung->setRoundTimeLimit(0);
    _einstellung->setCountdown(0);
    _einstellung->setPlayName("");
    _einstellung->setRoundNumber(0);
    close();
    SpielStart start;
    start.exec();
}

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

void HostSpielEinstellungen::on_eingegebenerSpielname_textEdited(const QString &arg1)
{
    ui->buttonNext->setEnabled(true);
    //ui->buttonWeiter->setFocus();
}
void HostSpielEinstellungen::on_eingabeRunden_textEdited(const QString &arg1)
{
    // ui->buttonWeiter->setFocus();
}

void HostSpielEinstellungen::on_eingabeZeitlimit_textEdited(const QString &arg1)
{
  //   ui->buttonWeiter->setFocus();
}

void HostSpielEinstellungen::on_EingabeZeitNachAntwort_textEdited(const QString &arg1)
{
    // ui->buttonWeiter->setFocus();
}
