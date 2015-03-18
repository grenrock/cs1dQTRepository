#include "addwine.h"
#include "ui_addwine.h"
#include <math.h>
#include <QMessageBox>

AddWine::AddWine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWine)
{
    ui->setupUi(this);
    current = 0;
}

AddWine::~AddWine()
{
    delete ui;
}

void AddWine::on_submit_clicked(){
    info.name = ui->add_wine_name->text();
    info.price = ui->add_wine_price->text();
    info.year = ui->add_wine_year->text();
    if(!info.price.toFloat()){
        QMessageBox messageBox;
        messageBox.setText("Invalid input.  Please enter an decimal value for the price.");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
    }
    if(!info.year.toInt()){
        QMessageBox messageBox;
        messageBox.setText("Invalid input.  Please enter an integer value for the year.");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
    }
    else if(info.year.toInt() > 2015 || info.year.toInt() < 1799){
        QMessageBox messageBox;
        messageBox.setText("Invalid input.  Please enter a year value between 1799 and 2015.");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
    }
    else{
        QMessageBox messageBox;
        messageBox.setText(info.name + " has been added to the list.");
        float newPrice = info.price.toFloat();
        newPrice = roundf(newPrice * 100) / 100;
        info.price = QString::number(newPrice);
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
        addWineToList();
        this->close();
    }
}

void AddWine::addWineToList(){
    current->winesOffered.push_back(info);
    int num = current->numWines.toInt();
    num++;
    current->numWines = QString(num);
}

void AddWine::setCurrentWinery(winery* c){
    current = c;
}

