#ifndef VIEWCUSTOMTRIP_H
#define VIEWCUSTOMTRIP_H

#include <QDialog>
#include "winery.h"

namespace Ui {
class ViewCustomTrip;
}

class ViewCustomTrip : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCustomTrip(QWidget *parent = 0);
    void setTrip(QVector<winery> custom);
    void setNumWineries(int num);
    void addToList();
    ~ViewCustomTrip();

private:
    Ui::ViewCustomTrip *ui;
    QVector<winery> cTrip;
    int numWineries;
};

#endif // VIEWCUSTOMTRIP_H
