#include "warning.h"
#include "ui_warning.h"

Warning::Warning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warning)
{
    ui->setupUi(this);
}

Warning::~Warning()
{
    delete ui;
}
bool Warning::getExit()
{
    return exitWarning;
}

void Warning::on_pushButton_clicked()
{
    exitWarning = true;
    this->close();
}

void Warning::on_pushButton_2_clicked()
{
     exitWarning = false;
     this->close();
}
