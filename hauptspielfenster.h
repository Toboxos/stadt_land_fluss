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
    void setTotalPoints(int points);
    void setCategories(QVector<QString> categories);
    void setPlayers(QVector<QString> players, QString clientName);
    void setLetter(char letter);

    void newRow();
    QVector<QString> getAnserVector();
    void startCountdown();
    void fillAnswerVector();
    void clearAnswerVector();
signals:

    void fertig();

private slots:
    void on_buttonFertig_clicked();



private:
    QMessageBox box;
    bool obSpielerwirklichFertigIst();
    QVector<QString> answerVector ;
    Ui::HauptSpielFenster *ui;
    void ready();
    int currentRow;
    QVector<QTableWidgetItem*> m_letters;
    QVector<QTableWidgetItem*> m_points;
};

#endif // HAUPTSPIELFENSTER_H
