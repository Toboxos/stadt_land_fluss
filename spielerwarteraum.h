#ifndef SPIELERWARTERAUM_H
#define SPIELERWARTERAUM_H

#include <QDialog>

namespace Ui {
class SpielerWarteRaum;
}

class SpielerWarteRaum : public QDialog
{
    Q_OBJECT

public:
    explicit SpielerWarteRaum(QWidget *parent = nullptr);
    ~SpielerWarteRaum();

private slots:
    void on_buttonWeiter_clicked();

private:
    Ui::SpielerWarteRaum *ui;
};

#endif // SPIELERWARTERAUM_H
