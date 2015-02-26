#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include<iostream>
#include<iomanip>
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
    void Print();
    int totalAccounts;
    bool checkAdmin(int count);
    bool loginOk(QString username, QString password, unsigned int i, int &count);
    void ReadFile();


private:
    vector <AccountInfo> accounts;
    Ui::Account *ui;
};

#endif // ACCOUNT_H
