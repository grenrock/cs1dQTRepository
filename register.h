#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QDialog>
#include<iostream>
#include<iomanip>
#include "Account.h"
using namespace std;

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

    //REGISTRATION OPTIONS
    void ReadFile();
    void checkUsernameAvailability();
    void addAccount();
    void printToFile();

private:
    Ui::Register *ui;
    AccountInfo info;
    vector<AccountInfo> accounts;

private slots:
    void on_submit_clicked();
    void on_cancel_clicked();
};


#endif // REGISTER_H
