#ifndef ADDNEWWINERIES_H
#define ADDNEWWINERIES_H

#include <QDialog>
#include "winery.h"

namespace Ui {
class AddNewWineries;
}

class AddNewWineries : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewWineries(QWidget *parent = 0);
    void ReadIn();
    void PrintToFile();
    void UpdateDistances(const winery& n);
    ~AddNewWineries();

private:
    Ui::AddNewWineries *ui;
    QVector<winery> currentWinery;
    QVector<winery> newWinery;
    int numWineries;

private slots:
    //void on_add_winery_browse_clicked();
    void on_add_winery_submit_clicked();
};

#endif // ADDNEWWINERIES_H
