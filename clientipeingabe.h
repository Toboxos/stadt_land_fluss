#ifndef CLIENTIPEINGABE_H
#define CLIENTIPEINGABE_H

#include <QDialog>
//was sind die Spieleinstellungen.......................................................................
//der Serverrechner muss dem Client die Daten übertragen die im Server stehen damit das
//Hauptspielfenster aufgeht
// Kategorien werden im Client nicht gefüllt


namespace Ui {
class ClientIpEingabe;
}

class ClientIpEingabe : public QDialog
{
    Q_OBJECT

public:
    explicit ClientIpEingabe(QWidget *parent = nullptr);
    ~ClientIpEingabe();

private slots:
    void on_eingabeIp_textEdited(const QString &arg1);

    void on_buttonZurueck_clicked();

   // void on_buttonWeiter_clicked();

private:
    Ui::ClientIpEingabe *ui;
};

#endif // CLIENTIPEINGABE_H
