#include "viewcustomtrip.h"
#include "ui_viewcustomtrip.h"
#include <QDebug>

ViewCustomTrip::ViewCustomTrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewCustomTrip)
{
    totalDist = 0;
    ui->setupUi(this);
}

void ViewCustomTrip::setNumWineries(int num)
{
    numWineries = num;
}
void ViewCustomTrip::readIn()
{

}

void ViewCustomTrip::setTrip(QVector<winery> custom, winery starting)
{
    for(int i = 0; i < custom.size(); i ++)
    {
        cTrip.push_back(custom[i]);
    }
    cTrip.push_front(starting);
    calculateTourRoute(emptyVec, cTrip, totalDist);
    addToList();
}

void ViewCustomTrip::addToList()
{
    QString str = QString::number(totalDist);

    ui->label_2->setText(emptyVec[0].name);
    for(int i = 1; i < emptyVec.size(); i ++)
    {
        ui->listWidget->addItem(emptyVec[i].name);
    }
    ui->listWidget->addItem("Total Distance Traveled: " + str + "miles" );
}

ViewCustomTrip::~ViewCustomTrip()
{
    delete ui;
}

void ViewCustomTrip::on_pushButton_clicked()
{
    Warning exit;
    exit.setModal(true);
    exit.exec();
    exitRet = exit.getExit();
    if(exitRet)
    {
        this->close();
        cTrip.clear();
    }
}
void  ViewCustomTrip::calculateTourRoute(QVector<winery>& tour,   // empty list where the planned route for the tour will be stored
                        QVector<winery>& places, // user's selection of tour locations (the front of the list being the starting point)
                        float& totalDistance)  // total distance for the tour
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
    totalDist = totalDistance;
}

void ViewCustomTrip::setOrder(QVector<wine> orderSet)
{
    for(int i =0; i < orderSet.size(); i ++)
    {
        shoppingOrder.push_back(orderSet[i]);
    }
}
void ViewCustomTrip::on_pushButton_2_clicked()
{
    bool selected = false;
    int i;

    qDebug() << emptyVec.size();
    for(i = 0; i < emptyVec.size(); i ++)
    {
        if(ui->listWidget->item(i)->isSelected())
        {
            selected = true;

        }

    }
    if(!selected || ui->listWidget->item(i-1)->isSelected())
    {
        QMessageBox::warning(this, tr("Error"), tr("Please Select a Winery to Purchase Wine"));
    }
    else
    {
        winery temp;
        for(int i = 0; i < emptyVec.size(); i ++)
        {
            if(ui->listWidget->currentItem()->text() == emptyVec[i].name)
            {
                temp = emptyVec[i];
            }
        }
        PurchaseWine pWine;
        pWine.setModal(true);
        pWine.setList(temp, shoppingOrder);
        pWine.exec();
        setOrder(pWine.cart);
    }
}
