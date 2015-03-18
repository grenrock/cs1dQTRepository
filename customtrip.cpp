#include "customtrip.h"
#include "ui_customtrip.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include "viewcustomtrip.h"

CustomTrip::CustomTrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomTrip)
{
    ui->setupUi(this);
    ReadIn();
}

CustomTrip::~CustomTrip()
{
    delete ui;
}
void CustomTrip::ReadIn()
{
    //QFile file("D:\\WineryProject_CS1D\\WineryList.txt");
    //QFile file("E:\\WineryProject_CS1D\\WineryList.txt");

    // **** STEVEN ****
    QFile file("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\WineryList.txt");

    // **** DORI ****
    //QFile file("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\WineryList.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString nWineries = in.readLine();
    numWineries = nWineries.toInt();

    ui->startingWinery->addItem("Select Starting Winery");
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
        ui->startingWinery->addItem(tempWinery.name);
    }

}

void CustomTrip::on_startingWinery_activated(const QString &arg1)
{
    ui->listWidget->clear();
    for(int i = 0; i < numWineries; i ++)
    {
        if(arg1 != currentWinery[i].name)
        ui->listWidget->addItem(currentWinery[i].name);
    }
}


void CustomTrip::on_add_clicked()
{
    ui->addTrip->addItem(ui->listWidget->takeItem(ui->listWidget->currentRow()));
}

void CustomTrip::on_add_2_clicked()
{
     ui->listWidget->addItem(ui->addTrip->takeItem(ui->addTrip->currentRow()));
}

void CustomTrip::on_createTrip_clicked()
{
    if(ui->addTrip->count() == 0)
    {
        QMessageBox::warning(this, tr("Empty List Widget"), tr("You haven't selected any wineries"));
    }
    else
    {

        for(int j = 0; j < ui->addTrip->count(); j ++)
        {
            QString str = ui->addTrip->item(j)->text();

            for(int i = 0; i < currentWinery.size(); i ++)
            {
                if(str == currentWinery[i].name)
                {
                    trip.push_back(currentWinery[i]);

                }
            }
        }
        ViewCustomTrip displayTrip;
        displayTrip.setModal(true);
        displayTrip.setTrip(trip);
        displayTrip.exec();


    }
}
