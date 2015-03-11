#include "register.h"
#include "ui_register.h"
#include "account.h"
#include "ui_account.h"
#include "mainwindow.h"
#include "adminmain.h"
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::checkUsernameAvailability(){
    QMessageBox messageBox;
    bool available = true;
    int i = 0;

    while(available && i < accounts.size()){
        if(accounts[i].userName == info.userName){
            available = false;
        }
        i++;
    }

    if(!available){
        messageBox.setText("Username already taken. Please enter a new username, sweetie.");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
    }
    else{
        messageBox.setText("Account Added!  Hope you enjoy your wine.");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
        addAccount();
        this->close();
    }
}

void Register::addAccount(){
    accounts.push_back(info);
    printToFile();
}

void Register::on_submit_clicked(){
    info.name = ui->RegisterFullNameBox->text();
    info.userName = ui->RegisterUsernameBox->text();
    info.password = ui->RegisterPasswordBox->text();
    info.adminStatus = "no";
    info.space = "\n";
    checkUsernameAvailability();
}

void Register::ReadFile()
{
    QTextStream stream(stdin);



    QString user;
    QString pw;
    QString n;
    QString as;
    QString sp;

    //QFile file("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\LoginInfo.txt");
    QFile file("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\LoginInfo.txt");
    //QFile file("//Users//austinrosario//Desktop//QT workspace//cs1dQTRepository//LoginInfo.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);

    in.setCodec("UTF-8");

    while(!in.atEnd())
    {
        AccountInfo nextAccount;
        //totalAccounts++;

        user = in.readLine();
        pw = in.readLine();
        n = in.readLine();
        as = in.readLine();
        sp = in.readLine();

        nextAccount.userName = user;
        nextAccount.password = pw;
        nextAccount.name = n;
        nextAccount.adminStatus = as;
        nextAccount.space = sp;

        accounts.push_back(nextAccount);
    }
}

void Register::printToFile(){

    //QFile file("//Users//austinrosario//Desktop//QT workspace//cs1dQTRepository//LoginInfo.txt");

    remove("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\LoginInfo.txt");
    QFile file("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\LoginInfo.txt");

    //remove("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\LoginInfo.txt");
    //QFile file("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\LoginInfo.txt");

    file.open(QIODevice::WriteOnly|QIODevice::Text);

    QTextStream out(&file);

    unsigned int i = 0;

    while (i < accounts.size())
    {
        out << accounts[i].userName << endl;
        out << accounts[i].password << endl;
        out << accounts[i].name << endl;
        out << accounts[i].adminStatus << endl;
        out << " " << endl;
        qDebug () << "here";
        i++;
    }

    file.close();
    qDebug() << "Output to file complete!";
}

void Register::on_cancel_clicked(){
    this->close();
}
