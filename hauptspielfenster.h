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
    ///
    /// \brief setLetter display the letter of the current round. Ensure that the player can not access read olny boxes
    /// and input boxes of previous rounds.
    /// \param letter
    ///
    void setLetter(char letter);

    void newRow();
    QVector<QString> getAnserVector();
    ///
    /// \brief startCountdown change button to default setting. Display text box to announce next round.
    ///
    void startCountdown();
    ///
    /// \brief fillAnswerVector store the answers of each table cell in answerVector.
    ///
    void fillAnswerVector();
    void clearAnswerVector();
    ///
    /// \brief countdownSartet disable ready button and change button text to "countdown" and display time left.
    ///
   void countdownSartet(int countdown);
    ///
    /// \brief increaseCurrentRow increase variable of currentRow of tableSpiel by one.
    ///
    void increaseCurrentRow();

    void startRound(int time);
signals:

    void fertig();

private slots:
    ///
    /// \brief on_buttonFertig_clicked if all cells of the current round are filled out distribute this information.
    ///
    void on_buttonFertig_clicked();



private:
    QMessageBox box;
    ///
    /// \brief obSpielerwirklichFertigIst check whether all necessary cells are filled out.
    /// \return true when all cells are filled out,
    /// \return false if not.
    ///
    bool obSpielerwirklichFertigIst();
    QVector<QString> answerVector ;
    Ui::HauptSpielFenster *ui;
    void ready();
    int currentRow;
    QVector<QTableWidgetItem*> m_letters;
    QVector<QTableWidgetItem*> m_points;
};

#endif // HAUPTSPIELFENSTER_H
