#ifndef CHANGEPRICE_H
#define CHANGEPRICE_H

#include <QDialog>
#include "winery.h"

namespace Ui {
class ChangePrice;
}

class ChangePrice : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePrice(QWidget *parent = 0);
    ~ChangePrice();
    void changePrice();
    void SetCurrentWine(wine* w);

private:
    Ui::ChangePrice *ui;
    wine *current;

private slots:
    void on_change_price_ok_clicked();
};

#endif // CHANGEPRICE_H
