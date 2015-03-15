#include "addwinewineryselector.h"
#include "ui_addwinewineryselector.h"

AddWineWinerySelector::AddWineWinerySelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWineWinerySelector)
{
    ui->setupUi(this);
}

AddWineWinerySelector::~AddWineWinerySelector()
{
    delete ui;
}
