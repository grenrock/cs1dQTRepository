#include "deleteuser.h"
#include "ui_deleteuser.h"
#include <QDebug>

deleteUser::deleteUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteUser)
{
    ui->setupUi(this);
}

deleteUser::~deleteUser()
{
    delete ui;
}

void deleteUser::DeleteUser()
{

}

void deleteUser::on_Cancel_clicked()
{
    this->close();
}

void deleteUser::on_DeleteButton_clicked()
{
    qDebug() << "Delete User";
}
