#include "trip.h"
#include "ui_trip.h"
#include "customtrip.h"

Trip::Trip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Trip)
{
    ui->setupUi(this);
}

Trip::~Trip()
{
    delete ui;
}


void Trip::on_pushButton_clicked()
{
    CustomTrip cTrip;
    cTrip.setModal(true);
    cTrip.exec();
}

void Trip::on_pushButton_4_clicked()
{
    this->close();
}

void Trip::on_pushButton_2_clicked()
{
    ShortestTrip sTrip;
    sTrip.setModal(true);
    sTrip.exec();
}


void Trip::on_pushButton_3_clicked()
{
    qDebug() << "a";
    visitallwineries fTrip;
    qDebug() << "b";
    fTrip.setModal(true);
    qDebug() << "c";
    fTrip.exec();
    qDebug() << "d";
}
