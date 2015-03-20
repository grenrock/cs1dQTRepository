#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "account.h"
#include "register.h"
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
}

void MainWindow::on_pushButton_2_clicked()
{
    Register regg;
    regg.ReadFile();
    regg.setModal(true);
    regg.exec();
}
