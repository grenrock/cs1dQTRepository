#ifndef TRIP_H
#define TRIP_H

#include <QDialog>
#include "shortesttrip.h"
#include "visitallwineries.h"

namespace Ui {
class Trip;
}

class Trip : public QDialog
{
    Q_OBJECT

public:
    explicit Trip(QWidget *parent = 0);
    ~Trip();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Trip *ui;
    float totDistance;
};

#endif // TRIP_H
