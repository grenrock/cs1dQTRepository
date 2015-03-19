#ifndef PURCHASEWINE_H
#define PURCHASEWINE_H

#include <QDialog>
#include "winery.h"
#include "QDebug"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "cart.h"
#include "shortesttrip.h"

namespace Ui {
class PurchaseWine;
}

class PurchaseWine : public QDialog
{
    Q_OBJECT

public:
    explicit PurchaseWine(QWidget *parent = 0);
    void setList(winery inWinery, QVector<wine> inOrder);
    void initiate();
    QVector<wine> cart;
    ~PurchaseWine();

private slots:
    void on_wineName_activated(const QString &arg1);

    void on_addToCart_clicked();

    void on_pushButton_clicked();

    void on_view_clicked();

    void on_Back_clicked();

private:
    Ui::PurchaseWine *ui;
    QVector<wine> purchaseList;
    QVector<wine> order;
    int index;

};

#endif // PURCHASEWINE_H
