#include "viewcustomtrip.h"
#include "ui_viewcustomtrip.h"
#include <QDebug>

ViewCustomTrip::ViewCustomTrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewCustomTrip)
{

    ui->setupUi(this);
}

void ViewCustomTrip::setNumWineries(int num)
{
    numWineries = num;
}

void ViewCustomTrip::setTrip(QVector<winery> custom)
{
    for(int i = 0; i < custom.size(); i ++)
    {
        cTrip.push_back(custom[i]);
    }
    addToList();
}

void ViewCustomTrip::addToList()
{
    for(int i = 0; i < cTrip.size(); i ++)
    {
        ui->listWidget->addItem(cTrip[i].name);
    }
}

ViewCustomTrip::~ViewCustomTrip()
{
    delete ui;
}
