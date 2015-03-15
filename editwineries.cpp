#include "editwineries.h"
#include "ui_editwineries.h"
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
    qDebug() << "Add winery\n";
}

void EditWineries::on_add_new_wine_clicked(){
    qDebug() << "Add wine\n";
}

void EditWineries::on_change_prices_clicked(){
    qDebug() << "Change price\n";
}

void EditWineries::on_cancel_edit_wineries_clicked(){
    this->close();
}
