#include "cart.h"
#include "ui_cart.h"

Cart::Cart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cart)
{
    ui->setupUi(this);
}

void Cart::setCart(QVector<wine> cartWine)
{
    float totalPrice = 0.0;
    float currentPrice;
    QString priceFinal;
    QString second;
    int j = 0;

    for(int i = 0; i < cartWine.size(); i ++)
    {
        ui->listWidget->addItem("Name: "  + cartWine[i].name);
        ui->listWidget->addItem("Year: "  + cartWine[i].year);
        ui->listWidget->addItem("Price: " + cartWine[i].price);

        cartWine[i].price.remove(0,8);
        currentPrice = cartWine[i].price.toFloat();
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
}

Cart::~Cart()
{
    delete ui;
}

void Cart::on_pushButton_clicked()
{
    this->close();
}
