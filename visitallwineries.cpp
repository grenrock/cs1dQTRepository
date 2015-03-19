#include "visitallwineries.h"
#include "ui_visitallwineries.h"

visitallwineries::visitallwineries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visitallwineries)
{
    ui->setupUi(this);

    initializeListing();  // initialize winery listing from file
    initializeComboBox(); // initialize comboBox from winery listing
}

visitallwineries::~visitallwineries()
{
    delete ui;
}

void visitallwineries::initializeListing()
{
    int numWineries;

    listing.clear();

    QFile file("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\WineryList.txt");
    //QFile file("D:\\WineryProject_CS1D\\WineryList.txt");
   //QFile file("E:\\WineryProject_CS1D\\WineryList.txt");
   //QFile file("//Users//austinrosario//Desktop//QT workspace//cs1dQTRepository//WineryList.txt");

   file.open(QIODevice::ReadOnly | QIODevice::Text);

   QTextStream in(&file);
   QString nWineries = in.readLine();
   numWineries = nWineries.toInt();
   qDebug() << numWineries;
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
       listing.push_back(tempWinery);
   }
}

void visitallwineries::initializeComboBox()
{
    ui->comboBox->clear();
    ui->comboBox->addItem("Select Winery");
    for(int i = 0; i < listing.size(); i ++)
    {
        ui->comboBox->addItem(listing[i].name);
    }
}

void visitallwineries::calculateTourRoute(QVector<winery>& tour,   // empty list where the planned route for the tour will be stored
                                          QVector<winery>& places, // user's selection of tour locations (the front of the list being the starting point)
                                          float& totalDistance)    // total distance for the tour
{
    QVector<winery>::iterator closest; // the closest destination from last destination in the tour
    QVector<winery>::iterator cursor;  // traverses the places list to find the closest destination
    QVector<winery>::iterator lastDestination; // last destination in the tour

    tour.clear();
    tour.push_back(places.front());
    places.erase(places.begin());
    totalDistance = 0;
    float closestDistance;
    float cursorDistance;

    while(!places.empty())
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
        totalDistance += closestDistance;
        tour.push_back(*closest);
        places.erase(closest);
    }
}

void visitallwineries::on_pushButton_clicked()
{
    exitStatus = true;
    if(!tWine.empty())
    {
        Warning exit;
        exit.setModal(true);
        exit.exec();
        exitStatus = exit.getExit();
    }
    if(!exitStatus)
    {

    }
    else
    {
        tWine.clear();
        // if a winery is selected in the combo box when this button is clicked then calculate tour
        if(ui->comboBox->currentIndex()-1 != -1)
        {
            QVector<winery> start;  // container temporarly storing the starting location of the tour
            QVector<winery>::iterator index = listing.begin(); // iterator to find the starting location of the tour in listing

            start.push_front(listing.at(ui->comboBox->currentIndex()-1));
            for(int x = 0; x < ui->comboBox->currentIndex()-1; x++)
            { index++; }

            listing.erase(index);
            listing.push_front(start.first());

            calculateTourRoute(fullTour, listing, totalDistance);
            initializeListing();  // reinitialize listing after it was changed in calculateTourRoute
            initializeComboBox(); // reinitialize the combo box after listing was changed

            ui->listWidget->clear();
            for(int x = 0; x < fullTour.size(); x++)
            { ui->listWidget->addItem(fullTour[x].name);}
        }
    }
}
void visitallwineries::setOrder(QVector<wine> orderSet)
{
    for(int i =0; i < orderSet.size(); i ++)
    {
        tWine.push_back(orderSet[i]);
    }
}
void visitallwineries::on_purchaseWine_clicked()
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
        for(int i = 0; i < fullTour.size(); i ++)
        {
            if(ui->listWidget->currentItem()->text() == fullTour[i].name)
            {
                temp = fullTour[i];
            }
        }
        PurchaseWine pWine;
        pWine.setModal(true);
        pWine.setList(temp, tWine);
        pWine.exec();
        setOrder(pWine.cart);
    }
}

void visitallwineries::on_back_clicked()
{
    Warning exit;
    exit.setModal(true);
    exit.exec();
    exitStatus = exit.getExit();
    if(exitStatus)
    {
        this->close();
    }
}
