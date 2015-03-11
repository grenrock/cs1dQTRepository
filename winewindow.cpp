#include "winewindow.h"
#include "ui_winewindow.h"
#include "winerylist.h"
#include "trip.h"

WineWindow::WineWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WineWindow)
{
    ui->setupUi(this);
}

WineWindow::~WineWindow()
{
    delete ui;
}


void WineWindow::on_pushButton_clicked()
{
    WineryList wList;
    wList.setModal(true);
    wList.exec();
}

void WineWindow::on_pushButton_2_clicked()
{
    Trip t;
    t.setModal(true);
    t.exec();
}
