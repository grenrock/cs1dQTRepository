#include "adminmain.h"
#include "ui_adminmain.h"
#include "edituser.h"
#include "editwineries.h"
#include <QDebug>

adminmain::adminmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminmain)
{
    ui->setupUi(this);
}

adminmain::~adminmain()
{
    delete ui;
}

void adminmain::on_EditUsersButton_clicked()
{
    editUser window;

    window.setModal(true);
    window.exec();

}

void adminmain::on_EditWineriesButton_clicked()
{
    qDebug() << "Edit Wineries";
    EditWineries window;
    window.setModal(true);
    window.exec();

}


