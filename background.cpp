#include "background.h"
#include "ui_background.h"
#include <QPixmap>

Background::Background(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Background)
{
    ui->setupUi(this);

    QPixmap pix("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\title.jpg");

    ui->label->setPixmap(pix);


}

Background::~Background()
{
    delete ui;
}
