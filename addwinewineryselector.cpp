#include "addwinewineryselector.h"
#include "ui_addwinewineryselector.h"
#include "addwine.h"
#include "wineselector.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include "mainwindow.h"

AddWineWinerySelector::AddWineWinerySelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWineWinerySelector)
{
    ui->setupUi(this);
    ReadIn();
}

void AddWineWinerySelector::ReadIn()
{
    // **** JOSH ****
    //QFile file("D:\\WineryProject_CS1D\\WineryList.txt");
    //QFile file("E:\\WineryProject_CS1D\\WineryList.txt");

    // **** STEVEN ****
    QFile file("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\WineryList.txt");

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

AddWineWinerySelector::~AddWineWinerySelector()
{
    delete ui;
}


void AddWineWinerySelector::on_add_wine_clicked()
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
                 AddWine adder;
                 adder.setCurrentWinery(&currentWinery[i]);
                 adder.setModal(true);
                 adder.exec();
                 PrintToFile();
                 this->close();
                 break;
            }
        }
    }
}

void AddWineWinerySelector::on_change_prices_clicked()
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
                 WineSelector selector;
                 selector.SetCurrentWinery(&currentWinery[i]);
                 selector.setModal(true);
                 selector.exec();
                 PrintToFile();
                 this->close();
                 break;
            }
        }
    }
}

void AddWineWinerySelector::PrintToFile(){
    //QFile file("//Users//austinrosario//Desktop//QT workspace//cs1dQTRepository//LoginInfo.txt");

  //  remove("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\LoginInfo.txt");
 //   QFile file("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\LoginInfo.txt");

    remove("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\WineryList.txt");
    QFile file("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\WineryList.txt");

    file.open(QIODevice::WriteOnly|QIODevice::Text);

    QTextStream out(&file);

    unsigned int i = 0;

    out << numWineries << endl;
    for(int i = 0; i < numWineries; i++){
        out << currentWinery[i].name << endl;
        out << i + 1 << endl;
        for(int j = 0; j < numWineries; j++){
            out << currentWinery[i].distanceFrom[j] << endl;

        }
        out << currentWinery[i].milesFrom << endl;
        out << currentWinery[i].winesOffered.size() << endl;
        for(unsigned int k = 0; k < currentWinery[i].winesOffered.size(); k++){
            out << currentWinery[i].winesOffered[k].name << endl;
            out << currentWinery[i].winesOffered[k].year << endl;
            out << currentWinery[i].winesOffered[k].price << endl;
        }
    }

//    while (i < accounts.size())
//    {
//        out << accounts[i].userName << endl;
//        out << accounts[i].password << endl;
//        out << accounts[i].name << endl;
//        out << accounts[i].adminStatus << endl;
//        out << " " << endl;
//        qDebug () << "here";
//        i++;
//    }

    file.close();
    qDebug() << "Output to file complete!";
}

