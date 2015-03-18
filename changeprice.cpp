#include "changeprice.h"
#include "ui_changeprice.h"
#include <math.h>
#include <QMessageBox>
#include <QDebug>

ChangePrice::ChangePrice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePrice)
{
    ui->setupUi(this);
    current = 0;
}

ChangePrice::~ChangePrice()
{
    delete ui;
}

void ChangePrice::SetCurrentWine(wine *w){
    current = w;
}

void ChangePrice::on_change_price_ok_clicked(){
    QMessageBox messageBox;
    current->price = ui->change_price_new_price->text();
    if(current->price.toFloat()){
        float newPrice = roundf(current->price.toFloat() * 100) / 100;
        current->price = QString::number(newPrice);
        messageBox.setText("Price changed to $" + current->price);
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
        this->close();
    }
    else{
        messageBox.setText("Invalid input.  Please enter a decimal value.");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
    }
}
