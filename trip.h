#ifndef TRIP_H
#define TRIP_H

#include <QDialog>

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

private:
    Ui::Trip *ui;
};

#endif // TRIP_H
