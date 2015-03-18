#ifndef WINESELECTOR_H
#define WINESELECTOR_H

#include <QDialog>
#include "displaywinery.h"
#include "winery.h"

namespace Ui {
class WineSelector;
}

class WineSelector : public QDialog
{
    Q_OBJECT

public:
    explicit WineSelector(QWidget *parent = 0);
    void ReadIn();
    void PrintToFile();
    void SetCurrentWinery(winery* w);
    ~WineSelector();

private:
    Ui::WineSelector *ui;
    QVector<wine> currentWine;
    winery* current;
    int numWines;
    void PopulateComboBox();

private slots:
    void on_wine_selector_ok_clicked();
};

#endif // WINESELECTOR_H
