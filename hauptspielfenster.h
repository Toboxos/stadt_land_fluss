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
    ///
    /// \brief setTotalPoints
    /// \param points
    ///
    void setTotalPoints(int points);
    void setCategories(QVector<QString> categories);
    void setPlayers(QVector<QString> players, QString clientName);
    ///
    /// \brief setLetter der Buchste der zu spielenden runde wird angezeigt.
    /// Die letzen eingaben kann man nicht mehr verändern.
    /// \param letter
    ///
    void setLetter(char letter);
    ///
    /// \brief newRow create new Row in tableSpiel
    ///
    void newRow();
    QVector<QString> getAnserVector();
    ///
    /// \brief startCountdown Button wird wieder auf Fertig gesetzt. Textbox erscheint.
    ///
    void startCountdown();
    ///
    /// \brief fillAnswerVector Die Zellen mit den Antworden der jeweiligen Runde werden in einen vector geschrieben.
    ///
    void fillAnswerVector();
    void clearAnswerVector();
    ///
    /// \brief countdownSartet Button wird auf "COUNTDOWN" gestellt und disabled.
    ///
    void countdownSartet();
    ///
    /// \brief increaseCurrentRow Die Zeile der tableSpiel wird hochgezählt.
    ///
    void increaseCurrentRow();
signals:

    void fertig();

private slots:
    ///
    /// \brief on_buttonFertig_clicked Wenn alle Zellen gefüllt sind wird weiter gegeben dass ein SPieler fertig ist.
    ///
    void on_buttonFertig_clicked();
    void timerEvent();


private:
    QMessageBox box;
    ///
    /// \brief obSpielerwirklichFertigIst Überprüfung ob alle zu füllenden Zellen gefüllt sind.
    /// \return true wennn alle Zellen gefüllt sind, false wenn nicht.
    ///
    bool obSpielerwirklichFertigIst();
    QVector<QString> answerVector ;
    Ui::HauptSpielFenster *ui;
    int currentRow;
    QVector<QTableWidgetItem*> m_letters;
    QVector<QTableWidgetItem*> m_points;

    QTimer m_timer;
    int m_timeRemaining;
};

#endif // HAUPTSPIELFENSTER_H
