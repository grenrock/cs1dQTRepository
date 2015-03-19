#include "editwineries.h"
#include "ui_editwineries.h"
#include "addwinewineryselector.h"
#include "addnewwineries.h"
#include <QDebug>

EditWineries::EditWineries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWineries)
{
    ui->setupUi(this);
}

EditWineries::~EditWineries()
{
    delete ui;
}

void EditWineries::on_add_new_winery_clicked(){
    AddNewWineries newWine;
    newWine.setModal(true);
    newWine.exec();
}

void EditWineries::on_edit_winery_clicked(){
    AddWineWinerySelector select;
    select.setModal(true);
    select.exec();
}


void EditWineries::on_close_edit_wineries_clicked(){
    this->close();
}
