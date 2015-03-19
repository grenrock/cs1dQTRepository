#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H
#include "winery.h"
#include <QDialog>
#include "warning.h"
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

    void on_pushButton_clicked();

private:
    Ui::CustomTrip *ui;
    QVector<winery> currentWinery;
    QVector<winery> otherWineries;
    QVector<winery> trip;
    winery startingWinery;
    int numWineries;
    bool eStatus;

};

#endif // CUSTOMTRIP_H

