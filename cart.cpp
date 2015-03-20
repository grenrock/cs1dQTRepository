#include "cart.h"
#include "ui_cart.h"

Cart::Cart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cart)
{
    purchased = false;
    ui->setupUi(this);
}

void Cart::setCart(QVector<wine> &cartWine)
{
    float totalPrice = 0.0;
    float currentPrice;
    QString priceFinal;
    QString second;
    int j = 0;

    for(int i = 0; i < cartWine.size(); i ++)
    {

        cartOrder.push_back(cartWine[i]);
        qDebug() << cartWine[i].name;
        qDebug() << cartWine[i].year;
        qDebug() << cartWine[i].price;
        ui->listWidget->addItem("Name: "  + cartWine[i].name);
        ui->listWidget->addItem(cartWine[i].year);
        ui->listWidget->addItem(cartWine[i].price);

        second = cartWine[i].price;
        second.remove(0,8);
        currentPrice = second.toFloat();
        totalPrice += currentPrice;
    }
    priceFinal = QString::number(totalPrice);
    if(priceFinal.contains('.'))
    {
        ui->totPrice->setText("$" + priceFinal + "0");
    }
    else
    {
        ui->totPrice->setText("$" + priceFinal + ".00");
    }

    ui->totPrice->show();
    cartOrder.clear();
}

Cart::~Cart()
{
    delete ui;
}

void Cart::on_pushButton_clicked()
{
    this->close();
}
bool Cart::getPurchased()
{
    return purchased;
}

void Cart::on_pushButton_2_clicked()
{
    QMessageBox::warning(this, tr("error"), tr("Thank you for your purchase!"));
    ui->listWidget->clear();
    purchased = true;
    this->close();
}
