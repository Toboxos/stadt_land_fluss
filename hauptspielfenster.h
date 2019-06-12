#ifndef HAUPTSPIELFENSTER_H
#define HAUPTSPIELFENSTER_H

#include <QMainWindow>
#include <QTimer>
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
    void countdownSartet(int countdown);
    void startRound(int time);
    void increaseCurrentRow();
signals:

    void fertig();

private slots:
    void on_buttonFertig_clicked();
    void timerEvent();


private:
    QMessageBox box;
    bool obSpielerwirklichFertigIst();
    QVector<QString> answerVector ;
    Ui::HauptSpielFenster *ui;
    void ready();
    int currentRow;
    QVector<QTableWidgetItem*> m_letters;
    QVector<QTableWidgetItem*> m_points;

    QTimer m_timer;
    int m_timeRemaining;
};

#endif // HAUPTSPIELFENSTER_H
