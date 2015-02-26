#include "edituser.h"
#include "ui_edituser.h"
#include "editadminstatus.h"
#include "adminmain.h"
#include <QDebug>

editUser::editUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editUser)
{
    ui->setupUi(this);
}

editUser::~editUser()
{
    delete ui;
}

void editUser::on_addUserButton_clicked()
{
    qDebug() << "addUser";
}

void editUser::on_deleteUserButton_clicked()
{
    qDebug() << "deleteUser";
}

void editUser::on_editAdminStatusButton_clicked()
{
    editAdminStatus window;

    window.setModal(true);
    window.exec();

    window.adminStatus();

}
