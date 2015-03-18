#ifndef ADDWINE_H
#define ADDWINE_H

#include <QDialog>
#include <QString>
#include "winery.h"

namespace Ui {
class AddWine;
}

class AddWine : public QDialog
{
    Q_OBJECT

public:
    explicit AddWine(QWidget *parent = 0);
    void addWineToList();
    void setCurrentWinery(winery *c);
    ~AddWine();

private:
    Ui::AddWine *ui;
    wine info;
    winery* current;


private slots:
    void on_submit_clicked();
};

#endif // ADDWINE_H
