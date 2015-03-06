#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include<iostream>
#include<iomanip>
#include "account.h"
using namespace std;

//Struct holds all information for user
struct AccountInfo
{
    QString name;                        //Users name
    QString adminStatus;                    //The users admin status
    QString userName;                    //Users username
    QString password;                    //Users password
    QString space;
};

//Account class
namespace Ui {
class Account;
}

class Account : public QDialog
{
    Q_OBJECT

public:
    explicit Account(QWidget *parent = 0);
    ~Account();

    //ACCOUNT OPTIONS
    void CreateUser();
    bool Login();
    void CloseAccount();
    int totalAccounts;
    void checkAdmin(int count);
    bool checkUsername(QString username, unsigned int &i);
    void adminStatus();
    bool loginOk(QString username, QString password, unsigned int i, int &count);
    void ReadFile();
    vector <AccountInfo> accounts;

private:
    Ui::Account *ui;

private slots:
    void on_ok_clicked();
    void on_cancel_clicked();
};

#endif // ACCOUNT_H
