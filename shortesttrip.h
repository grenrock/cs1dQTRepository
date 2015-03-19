#ifndef SHORTESTTRIP_H
#define SHORTESTTRIP_H

#include <QDialog>
#include "winery.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "purchasewine.h"
#include "warning.h"

namespace Ui {
class ShortestTrip;
}

class ShortestTrip : public QDialog
{
    Q_OBJECT

public:
    explicit ShortestTrip(QWidget *parent = 0);
    void setTrip(QVector<winery> custom, winery starting, int numWineries);
    void calculateShortest(winery startWinery,
                          QVector<winery>& tour,   // empty list where the planned route for the tour will be stored
                          QVector<winery>& places, // user's selection of tour locations (the front of the list being the starting point)
                          float& totalDistance,
                          int numberOfVisits);
    void readIn();
    void setComboBox();
    void setOrder(QVector<wine> orderSet);
    void setExitWarning(bool set);
    ~ShortestTrip();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_purchaseWine_clicked();

    void on_back_clicked();

private:
    Ui::ShortestTrip *ui;
    QVector<winery> currentWinery;
    QVector<winery> empty;
    QVector<wine> shoppingOrder;
    int numWineries;
    int wineriesToVist;
    float totalDistanceTraveled;
    int count;
    bool clearTrip;
    bool exitReturn;
};

#endif // SHORTESTTRIP_H
