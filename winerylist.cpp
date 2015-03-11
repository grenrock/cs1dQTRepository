#include "winerylist.h"
#include "ui_winerylist.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include "mainwindow.h"

WineryList::WineryList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WineryList)
{
    ui->setupUi(this);
    ReadIn();
}

void WineryList::ReadIn()
{
     QFile file("D:\\WineryProject_CS1D\\WineryList.txt");
    //QFile file("E:\\WineryProject_CS1D\\WineryList.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString nWineries = in.readLine();
    numWineries = nWineries.toInt();
    qDebug() << numWineries;
    ui->comboBox->addItem("Select Winery");
    for(int i = 0 ; i < numWineries; i ++)
    {

        int num;
        wine tempWine;
        winery tempWinery;

        tempWinery.name = in.readLine();
        tempWinery.number = in.readLine();
        for(int i = 0; i < numWineries; i ++)
        {
            tempWinery.distanceFrom[i] = in.readLine();
        }
        tempWinery.milesFrom = in.readLine();
        tempWinery.numWines = in.readLine();
        num = tempWinery.numWines.toInt();

        for(int i = 0; i < num; i ++)
        {
            tempWine.name = in.readLine();
            tempWine.year = in.readLine();
            tempWine.price = in.readLine();
            tempWinery.winesOffered.push_back(tempWine);
        }
        currentWinery.push_back(tempWinery);
        ui->comboBox->addItem(tempWinery.name);
    }
}

WineryList::~WineryList()
{
    delete ui;
}


void WineryList::on_pushButton_clicked()
{
    if(ui->comboBox->currentText() == "Select Winery")
    {
        QMessageBox::warning(this, tr("Error Message"), tr("Please Select a Winery"));
    }
    else
    {
        for(int i = 0; i < currentWinery.size(); i ++)
        {
            if(ui->comboBox->currentText() == currentWinery[i].name)
            {
                DisplayWinery showWineryInfo;
                int numberWines = currentWinery[i].numWines.toInt();
                showWineryInfo.setModal(true);
                showWineryInfo.setWinery(currentWinery, i, numberWines);
                showWineryInfo.exec();
                break;

            }
        }
    }
}
