#ifndef CART_H
#define CART_H

#include <QDialog>
#include "winery.h"
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class Cart;
}

class Cart : public QDialog
{
    Q_OBJECT

public:
    explicit Cart(QWidget *parent = 0);
    void setCart(QVector<wine> &cartWine);
    bool getPurchased();
    ~Cart();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Cart *ui;
    QVector<wine> cartOrder;
    bool purchased;
};

#endif // CART_H
