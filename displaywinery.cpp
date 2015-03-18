#include "displaywinery.h"
#include "ui_displaywinery.h"
#include <QDebug>

DisplayWinery::DisplayWinery(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayWinery)
{
    ui->setupUi(this);

}

void DisplayWinery::setWinery(QVector<winery> inList, int index, int numWines)
{
    otherWineries = inList;
    displayWinery = inList[index];
    ui->numberOfWines->setText(inList[index].numWines);
    ui->wineryNameLabel->setText(inList[index].name);

    ui->comboBox->addItem("Select Winery");
    for(int i = 0; i < inList.size(); i ++)
    {
        if(i != index)
        ui->comboBox->addItem(inList[i].name);
    }


    for(int i = 0; i < numWines; i ++)
    {
        ui->listWidget->addItem("Name:   " + inList[index].winesOffered[i].name);
        ui->listWidget->addItem("Year:   " + inList[index].winesOffered[i].year);
        ui->listWidget->addItem("Price:  $" + inList[index].winesOffered[i].price + '\n');
    }
}


DisplayWinery::~DisplayWinery()
{
    delete ui;
}


void DisplayWinery::on_comboBox_activated(const QString &arg1)
{
    for(int index = 0; index < otherWineries.size(); index ++)
    {
        if(ui->comboBox->currentText() == otherWineries[index].name)
        {
            ui->distanceLabel->setText(displayWinery.distanceFrom[index] + " miles");
        }
    }
}

