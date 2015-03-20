#include "addnewwineries.h"
#include "ui_addnewwineries.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

AddNewWineries::AddNewWineries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewWineries)
{
    ui->setupUi(this);
    //ui->add_winery_file_name->setText("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\new wineries.txt");
    ui->add_winery_file_name->setText("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\newwineries.txt");
    ReadIn();
}

AddNewWineries::~AddNewWineries()
{
    delete ui;
}

void AddNewWineries::ReadIn(){
    // **** JOSH ****
    //QFile file("D:\\WineryProject_CS1D\\WineryList.txt");
    //QFile file("E:\\WineryProject_CS1D\\WineryList.txt");

    // **** STEVEN ****
    //QFile file("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\WineryList.txt");

    // **** Dori ****
    QFile file("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\WineryList.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString nWineries = in.readLine();
    numWineries = nWineries.toInt();
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
    }
}


void AddNewWineries::PrintToFile(){
    //   QFile file("//Users//austinrosario//Desktop//QT workspace//cs1dQTRepository//WineryList.txt");

      remove("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\WineryList.txt");
      QFile file("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\WineryList.txt");

    //remove("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\WineryList.txt");
    //QFile file("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\WineryList.txt");

    file.open(QIODevice::WriteOnly|QIODevice::Text);

    QTextStream out(&file);

    unsigned int i = 0;

    numWineries = currentWinery.size();
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

}

void AddNewWineries::UpdateDistances(const winery& n){
    int num = currentWinery.size();
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            currentWinery[i].distanceFrom[num - 1] = n.distanceFrom[i];
        }
    }
}

void AddNewWineries::on_add_winery_submit_clicked(){

    QFile file(ui->add_winery_file_name->text());
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString nWineries = in.readLine();
    numWineries = nWineries.toInt();
    qDebug() << numWineries;
    int startSize = currentWinery.size();
    for(int i = 0 ; i < numWineries; i ++)
    {

        int num;
        wine tempWine;
        winery tempWinery;

        tempWinery.name = in.readLine();
        tempWinery.number = in.readLine();
        qDebug() << "pre for loop";
        for(int j = 0; j < numWineries + startSize; j ++)
        {
            tempWinery.distanceFrom[j] = in.readLine();
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
        UpdateDistances(tempWinery);
    }
    PrintToFile();
    this->close();
}

