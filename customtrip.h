#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QDialog>
#include "winery.h"

namespace Ui {
class CustomTrip;
}

class CustomTrip : public QDialog
{
    Q_OBJECT

public:
    explicit CustomTrip(QWidget *parent = 0);
    void ReadIn();
    ~CustomTrip();

private slots:
    void on_startingWinery_activated(const QString &arg1);

    void on_add_clicked();

    void on_add_2_clicked();



    void on_createTrip_clicked();

private:
    Ui::CustomTrip *ui;
    QVector<winery> currentWinery;
    QVector<winery> otherWineries;
    QVector<winery> trip;
    int numWineries;

};

#endif // CUSTOMTRIP_H
