#include "shortesttrip.h"
#include "ui_shortesttrip.h"

ShortestTrip::ShortestTrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShortestTrip)
{
    ui->setupUi(this);
    setComboBox();
    totalDistanceTraveled = 0;
    count = 0;
}

void ShortestTrip::calculateShortest(winery startWinery,
                                     QVector<winery>& tour,   // empty list where the planned route for the tour will be stored
                                     QVector<winery>& places, // user's selection of tour locations (the front of the list being the starting point)
                                     float& totalDistance,
                                     int numberOfVisits)
{
    QVector<winery>::iterator closest; // the closest destination from last destination in the tour
    QVector<winery>::iterator cursor;  // traverses the places list to find the closest destination
    QVector<winery>::iterator lastDestination; // last destination in the tour

    tour.clear();
    tour.push_back(startWinery);
    int startNum = startWinery.number.toInt();
    places.remove(startNum - 1);
    totalDistance = 0;
    float closestDistance;
    float cursorDistance;

    for(int x = 0; x < numberOfVisits; x++)
    {
        closest = places.begin();
        cursor  = places.begin();
        lastDestination = tour.end();
        lastDestination--;
        while(cursor != places.end())
        {
            // if the distance from the last tour destination to the cursor's destination
            // is less than the distance from the last tour destination to the closest known
            // destination, then the closest destination is the cursor destination
            cursorDistance = lastDestination->distanceFrom[cursor->number.toInt()-1].toFloat();
            closestDistance = lastDestination->distanceFrom[closest->number.toInt()-1].toFloat();
            if(cursorDistance < closestDistance)
            {
                closest = cursor;
            }
            cursor++;
        }
        closestDistance = lastDestination->distanceFrom[closest->number.toInt()-1].toFloat();
        totalDistance += closestDistance;
        tour.push_back(*closest);
        places.erase(closest);
    }
}
void ShortestTrip::setComboBox()
{
    QString addString;
    int num;
    wine tempWine;
    winery tempWinery;

    QFile file("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\WineryList.txt");
    //QFile file("//Users//austinrosario//Desktop//QT workspace//cs1dQTRepository//WineryList.txt");
   // QFile file("E:\\WineryProject_CS1D\\WineryList.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString nWineries = in.readLine();
    wineriesToVist = nWineries.toInt();
    ui->comboBox->addItem("Select Starting Winery");
    for(int i = 0 ; i < wineriesToVist; i ++)
    {

        tempWinery.name = in.readLine();
        tempWinery.number = in.readLine();
        for(int i = 0; i < wineriesToVist; i ++)
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
        addString = QString::number(i);
        ui->comboBox_2->addItem(addString);
    }

}
void ShortestTrip::readIn()
{
    int num;
    wine tempWine;
    winery tempWinery;

    QFile file("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\WineryList.txt");
    //QFile file("//Users//austinrosario//Desktop//QT workspace//cs1dQTRepository//WineryList.txt");
    //QFile file("E:\\WineryProject_CS1D\\WineryList.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString nWineries = in.readLine();
    wineriesToVist = nWineries.toInt();
    for(int i = 0 ; i < wineriesToVist; i ++)
    {

        tempWinery.name = in.readLine();
        tempWinery.number = in.readLine();
        for(int i = 0; i < wineriesToVist; i ++)
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

ShortestTrip::~ShortestTrip()
{
    delete ui;
}

void ShortestTrip::on_pushButton_clicked()
{
    bool validNumber = ui->comboBox_2->currentText() != "0";
    int index;
    if(!validNumber)
    {
        QMessageBox::warning(this, tr("Error"), tr("You Must Select At Least ONE Additional Winery To Visit"));
    }
    else if(count > 0)
    {
        QMessageBox::warning(this, tr("Error"), tr("Please Clear Trip To Continute"));
    }
    else
    {

        int num = ui->comboBox_2->currentText().toInt();

        for(index = 0 ; index < currentWinery.size(); index ++)
        {
            if(ui->comboBox->currentText() == currentWinery[index].name)
            {
                break;
            }
        }
        calculateShortest(currentWinery[index], empty, currentWinery, totalDistanceTraveled, num);
        for(int i = 0; i < empty.size(); i ++)
        {
            ui->listWidget->addItem(empty[i].name);
        }
        QString tDistance = QString::number(totalDistanceTraveled);
        ui->listWidget->addItem("Total Distance Traveled: " + tDistance);
        count ++;
    }

    empty.clear();
    currentWinery.clear();
    readIn();



}

void ShortestTrip::on_pushButton_2_clicked()
{
    Warning exit;
    exit.setModal(true);
    exit.exec();
    exitReturn = exit.getExit();
    if(exitReturn)
    {
        ui->listWidget->clear();
        count --;
        shoppingOrder.clear();
    }

}

void ShortestTrip::setOrder(QVector<wine> orderSet)
{
    for(int i =0; i < orderSet.size(); i ++)
    {
        shoppingOrder.push_back(orderSet[i]);
    }
}

void ShortestTrip::on_purchaseWine_clicked()
{
    bool selected = false;

    for(int i = 0; i < ui->listWidget->count() - 1; i ++)
    {
        if(ui->listWidget->item(i)->isSelected())
        {
            selected = true;
        }
    }

    if(!selected)
    {
       QMessageBox::warning(this, tr("Error"), tr("Please Select a Winery to Purchase Wine"));
    }

    else
    {
        winery temp;
        for(int i = 0; i < currentWinery.size(); i ++)
        {
            if(ui->listWidget->currentItem()->text() == currentWinery[i].name)
            {
                temp = currentWinery[i];
            }
        }
        PurchaseWine pWine;
        pWine.setModal(true);
        pWine.setList(temp, shoppingOrder);
        pWine.exec();
        setOrder(pWine.cart);
    }
}

void ShortestTrip::setExitWarning(bool set)
{
    exitReturn = set;
}

void ShortestTrip::on_back_clicked()
{
   Warning exit;
   exit.setModal(true);
   exit.exec();
   exitReturn = exit.getExit();
   if(exitReturn)
   {
       this->close();
   }
}
