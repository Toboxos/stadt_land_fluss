#ifndef HAUPTSPIELFENSTER_H
#define HAUPTSPIELFENSTER_H

#include <QMainWindow>
#include "QMessageBox"
#include "QTableWidgetItem"
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
    QVector<QString> getAnserVector();
    void startCountdown();
    void enableUserinput(char letter);
    void fillAnswerVector();
signals:

    void fertig();

private slots:
    void on_buttonFertig_clicked();



private:
    QMessageBox box;
    void setLetter(char letter);

    QVector<QString> answerVector ;
    Ui::HauptSpielFenster *ui;
    void ready();
    int currentRow;
    QTableWidgetItem* item = nullptr;
};

#endif // HAUPTSPIELFENSTER_H
