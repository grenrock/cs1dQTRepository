#ifndef VIEWCUSTOMTRIP_H
#define VIEWCUSTOMTRIP_H

#include <QDialog>
#include "winery.h"
#include <QVector>
#include <QMessageBox>
#include "purchasewine.h"
#include "warning.h"
namespace Ui {
class ViewCustomTrip;
}

class ViewCustomTrip : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCustomTrip(QWidget *parent = 0);
    void setTrip(QVector<winery> custom, winery starting);
    void setNumWineries(int num);
    void addToList();
    void readIn();
    void calculateTourRoute(QVector<winery>& tour,   // empty list where the planned route for the tour will be stored
                            QVector<winery>& places, // user's selection of tour locations (the front of the list being the starting point)
                            float& totalDistance);
    QVector<wine> shoppingOrder;
    void setOrder(QVector<wine> orderSet);
    ~ViewCustomTrip();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ViewCustomTrip *ui;
    QVector<winery> cTrip;
    int numWineries;
    QVector<winery> emptyVec;
    float totalDist;
    bool exitRet;
    QVector<wine> vWine;
};

#endif // VIEWCUSTOMTRIP_H
