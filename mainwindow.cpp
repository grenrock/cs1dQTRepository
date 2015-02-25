#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "account.h"
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
    login.setModal(true);
    login.exec();


    //Calls login function
    login.Login();

}

void MainWindow::on_pushButton_2_clicked()
{
    // Austin test
    // this is more stuff and stuff to test this out
    // sajdflkjaskdf test  gay
    // new comment
    // this is a test
    // yet another fucking test sd
    // holy shit balls
    // test test testicle
    //Dori Test
    // Great job m8

}
