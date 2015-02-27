//#include "register.h"
//#include "account.h"
//#include "ui_account.h"
//#include "mainwindow.h"
//#include "adminmain.h"
//#include <QDebug>
//#include <QTextStream>
//#include <QFile>
//#include <QMessageBox>

//using namespace std;

//Register::Register(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::Register)
//{
//    ui->setupUi(this);
//}

//Register::~Register()
//{
//    delete ui;
//}

//void Resiter::registerInfo(QString name, QString username, QString password){
//    info.name     = name;
//    info.username = username;
//    info.password = password;
//    info.adminStatus = "no";
//    info.space = "\n";
//}

//void Register::checkUsernameAvailability(const vector<AccountInfo> &account){
//    QMessageBox messageBox;
//    bool available = true;
//    int i = 0;

//    while(available && i < account.size()){
//        if(account[i].username == info.username){
//            available = false;
//        }
//        i++;
//    }

//    if(!available){
//        messageBox.setText("Username already taken. Please enter a new username, sweetie.");
//        messageBox.setFixedSize(500, 200);
//        messageBox.exec();
//    }
//    else{
//        addAccount(vector<AccountInfo> &account);
//    }
//}

//void Register::addAccount(vector<AccountInfo> &account){
//    account.push_back(info);
//}

//void Register::on_submit_clicked(){

//}

//void Register::on_cancel_clicked(){
//    this->close();
//}
