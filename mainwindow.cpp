#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "account.h"
#include "adminmain.h"
//#include "register.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//LOGIN BUTTON
void MainWindow::on_pushButton_clicked()
{
    Account login;
    login.ReadFile();
    adminmain admin;
    bool adminStatus = false;
    login.setModal(true);
    login.exec();


//    //Calls login function
//    adminStatus = login.Login();

//    if(adminStatus)
//    {
//        admin.setModal(true);
//        admin.exec();
//    }
//    else
//    {
//        //USER WINDOW
//        qDebug() << "user";
//    }

}

void MainWindow::on_pushButton_2_clicked()
{
//   Register regg;
//   regg.setModal(true);
//   regg.exec();
}
