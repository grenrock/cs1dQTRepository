#include "purchasewine.h"
#include "ui_purchasewine.h"

PurchaseWine::PurchaseWine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PurchaseWine)
{
    index = 1;
    ui->setupUi(this);
}

void PurchaseWine::setList(winery inWinery, QVector<wine> inOrder)
{
     QFont font;
     font.setPointSize(22);
     ui->WineryName->setFont(font);
     ui->WineryName->setText(inWinery.name);
    int num = inWinery.numWines.toInt();
    for(int i = 0; i < num; i ++)
    {
        purchaseList.push_back(inWinery.winesOffered[i]);
    }
    for(int i = 0; i < inOrder.size(); i ++)
    {
        cart.push_back(inOrder[i]);
    }
    initiate();
}

void PurchaseWine::initiate()
{

    ui->wineName->addItem("Select Wine");
    for(int i = 0; i < purchaseList.size(); i ++)
    {
        ui->wineName->addItem(purchaseList[i].name);
    }
}

PurchaseWine::~PurchaseWine()
{

    delete ui;
}

void PurchaseWine::on_wineName_activated(const QString &arg1)
{
    ui->wineInfo->clear();
    for(int i = 0; i < purchaseList.size(); i ++)
    {
         if(ui->wineName->currentText() == purchaseList[i].name )
         {
             ui->wineInfo->addItem("Year: " + purchaseList[i].year);
             ui->wineInfo->addItem("Price: $" + purchaseList[i].price);
         }
    }

}

void PurchaseWine::on_addToCart_clicked()
{

    QMessageBox messageBox;
    if(ui->currentOrder->count() == 0)
    {
        messageBox.setText("Nothing to Add to Cart!");
        messageBox.exec();
    }
    else
    {
        messageBox.setText("Added to Cart!");
        messageBox.exec();
        for(int i = 0; i < order.size(); i ++)
        {
            cart.push_back(order[i]);
        }
    }
    order.clear();
}


void PurchaseWine::on_pushButton_clicked()
{
    wine temp;
    QString str;

    int numBottles = ui->purchaseNumber->text().toInt();

    if(ui->wineName->currentText() == "Select Wine" || ui->purchaseNumber->text() == "0")
    {
        if(!(ui->wineName->currentText() == "Select Wine") && ui->purchaseNumber->text() == "0")
            QMessageBox::warning(this, tr("Error"), tr("Number of bottles must be greater than 0"));
        else if(ui->wineName->currentText() == "Select Wine" && !(ui->purchaseNumber->text() == "0"))
            QMessageBox::warning(this, tr("Error"), tr("Please Select a Type of Wine"));
    }
    else
    {
        for(int i =0; i < numBottles; i ++)
        {
            str = QString::number(index);
            temp.name = ui->wineName->currentText();
            temp.year = ui->wineInfo->item(0)->text();
            temp.price = ui->wineInfo->item(1)->text();

            order.push_back(temp);

            ui->currentOrder->addItem(str + ":" +temp.name);
            ui->currentOrder->addItem("   " + temp.year);
            ui->currentOrder->addItem("   " + temp.price);

            index ++;
        }


    }

}

void PurchaseWine::on_view_clicked()
{
    Cart c;
    c.setModal(true);
    c.setCart(cart);
    c.exec();

    if(c.getPurchased())
    {
        cart.clear();
    }

}

void PurchaseWine::on_Back_clicked()
{
    this->close();
}
