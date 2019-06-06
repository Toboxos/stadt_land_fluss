#ifndef HAUPTSPIELFENSTER_H
#define HAUPTSPIELFENSTER_H

#include <QMainWindow>
namespace Ui {
class HauptSpielFenster;
}

class HauptSpielFenster : public QMainWindow
{
    Q_OBJECT

public:
    explicit HauptSpielFenster(QWidget *parent = nullptr);
    ~HauptSpielFenster();

    void setCategories(QVector<QString> categories);
    void setPlayers(QVector<QString> players, QString clientName);

    void newRow();

    QVector<QString> getAnswers();

signals:
    void fertig();

private slots:
    void on_buttonFertig_clicked();



private:
    Ui::HauptSpielFenster *ui;
    void ready();
    int currentRow;
};

#endif // HAUPTSPIELFENSTER_H
