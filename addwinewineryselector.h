#ifndef ADDWINEWINERYSELECTOR_H
#define ADDWINEWINERYSELECTOR_H

#include <QDialog>
#include "displaywinery.h"
#include "winery.h"

namespace Ui {
class AddWineWinerySelector;
}

class AddWineWinerySelector : public QDialog
{
    Q_OBJECT

public:
    explicit AddWineWinerySelector(QWidget *parent = 0);
    void ReadIn();
    void PrintToFile();
    ~AddWineWinerySelector();

private:
    Ui::AddWineWinerySelector *ui;
    QVector<winery> currentWinery;
    int numWineries;

private slots:
    void on_add_wine_clicked();
    void on_change_prices_clicked();

};

#endif
