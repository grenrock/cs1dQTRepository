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
