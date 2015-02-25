#include "account.h"
#include "ui_account.h"
#include "mainwindow.h"
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
Account::Account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Account)
{
    ui->setupUi(this);
}

Account::~Account()
{
    delete ui;
}


#include "account.h"


void Account::CreateUser()
{
    bool validUsername = false;

    //catch classes
    class invalidPasswordLength{};
    class invalidUsernameLength{};
    class passwordConfirmationFail{};
    class usernameAlreadyTaken{};
    class invalidGeneralLength{};

    QString username;
    QString password;
    QString passwordConfirm;

//    ui->textEdit->text();
//    ui->textEdit_2->text();
//    ui->textEdit_3->text();

//    Qdebug() << textEdit;
}

void Account::Login()
{
    QMessageBox messageBox;
    ReadFile();
    Account z;
    MainWindow w;

    unsigned int i = 0;
    int count = 0;

    bool login = false;

    QString username;
    QString password;


    //Takes in login input from user
    username = ui->lineEdit_2->text();
    password = ui->lineEdit->text();

    login = loginOk(username, password, i, count);

    if (login)
    {

    }
    else if (!login)
    {
        messageBox.setText("INCORRECT LOGIN!");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
        z.setModal(true);
        z.exec();
    }
    else
    {

    }
}

void Account::ReadFile()
{
    QTextStream stream(stdin);

    AccountInfo nextAccount;

    QString user;
    QString pw;
    QString n;
    QString as;
    QString sp;


    QFile file("C:\\Users\\Dori\\QTworkspace\\Login\\LoginInfo.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);

    in.setCodec("UTF-8");

    while(!in.atEnd())
    {

        totalAccounts++;

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

bool Account::loginOk(QString username, QString password, unsigned int i, int &count)
{
    bool loginOk = false;

    while (i < accounts.size() && !loginOk)
    {
        if(accounts[i].userName == username && accounts[i].password == password)
        {
            loginOk = true;
        }
        else
        {
            i++;
        }
    }


    count = i;

    return loginOk;
}
