#ifndef CART_H
#define CART_H

#include <QDialog>
#include "winery.h"
#include <QDebug>

namespace Ui {
class Cart;
}

class Cart : public QDialog
{
    Q_OBJECT

public:
    explicit Cart(QWidget *parent = 0);
    void setCart(QVector<wine> cartWine);
    ~Cart();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Cart *ui;
};

#endif // CART_H
