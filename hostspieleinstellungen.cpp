#include "Hostspieleinstellungen.h"
#include "ui_hostspieleinstellungen.h"
#include "kategorieeingabe.h"
#include "spielstart.h"
#include "spieleinstellungen.h"
#include <QMessageBox>

// todo Felder überprüfen dass nicht kleiner als 0 oder Sonderzeichen eingegeben werden..............................
//..............................................................................................................
//
HostSpielEinstellungen::HostSpielEinstellungen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HostSpielEinstellungen)
{

   ui->setupUi(this);
   ui->buttonWeiter->setFocus();
   ui->eingegebenerSpielname->setFocus();
   //ui->buttonWeiter->setFocus();
//   ui->eingegebenerSpielname-> curser auf erstes Kästchen.
}

HostSpielEinstellungen::~HostSpielEinstellungen()
{
    delete ui;
}
///
/// \brief HostSpielEinstellungen::on_buttonWeiter_clicked
/// Die eingetragenen Werte der Labels werden in die Variablen geschrieben sobald auf weiter geklickt wurde.
///
void HostSpielEinstellungen::on_buttonWeiter_clicked()
{
    QMessageBox box;
    ui->label->setText(QString::number(ui->eingabeRunden->text().toInt()));
    // abfrage sodass rundendauer nur eine Zahl größer als 0 sein kann.
    /*   if(ui->eingabeZeitlimit->text() == "0")
    {
            box.setText("if");
            box.exec();

    }
        else if(ui->eingabeZeitlimit->text().toInt() == 0)
        {
                box.setText("else if");
                box.exec();
        }
            else
            {
            box.setText("else");
            box.exec();
                _einstellung->setRundendauer(ui->eingabeZeitlimit->text().toInt());
            }*/

    _einstellung->setCountdown(ui->EingabeZeitNachAntwort->text().toInt());
    _einstellung->setSpielname(ui->eingegebenerSpielname->text().toStdString());

    if (checkBoxChecked)
    {
        _einstellung->setRundenanzahl(99);  //Wert 99 steht für unendlich
    }
    else
    {
        _einstellung->setRundenanzahl(ui->eingabeRunden->text().toInt());
    }
    close();
    Kategorieeingabe eingabe;
    eingabe.exec();




}
///
/// \brief HostSpielEinstellungen::on_buttonZurueck_clicked
///sobald zurück geklickt wird werden die Variablen auf Null gesetzt.
///
void HostSpielEinstellungen::on_buttonZurueck_clicked()
{

    _einstellung->setRundendauer(0);
    _einstellung->setCountdown(0);
    _einstellung->setSpielname("");
    _einstellung->setRundenanzahl(0);
    close();
    SpielStart start;
    start.exec();
}

void HostSpielEinstellungen::on_checkBoxUnendlich_stateChanged(int arg1)
{

    ui->label->setText(QString::number(arg1));
     ui->buttonWeiter->setFocus();
    ui->eingabeRunden->clear();
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
    ui->buttonWeiter->setEnabled(true);
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
