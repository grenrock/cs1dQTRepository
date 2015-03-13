#include "editadminstatus.h"
#include "ui_editadminstatus.h"
#include <QDebug>
#include <QMessageBox>

editAdminStatus::editAdminStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editAdminStatus)
{
    ui->setupUi(this);
    Account h;
    h.ReadFile();

    int size;

    size = h.accounts.size();


    vector<AccountInfo> newAccount;
    newAccount =h.accounts;
    for(int j = 0; j < size ; j ++)
    {
      QString str =  newAccount[j].userName;
      QString as  =  newAccount[j].adminStatus;
      ui->listWidget->addItem("User Name: "    + str);
      ui->listWidget->addItem("Admin Status: " + as  + '\n' + "---------------------------");
    }
}

editAdminStatus::~editAdminStatus()
{
    delete ui;
}

void editAdminStatus::adminStatus()
{

}

void editAdminStatus::on_pushButton_2_clicked()
{
    this->close();
}

void editAdminStatus::on_pushButton_clicked()
{
    QMessageBox messageBox;
    QString username;
    QString messageString;
    unsigned int i = 0;
    bool found = false;

    username = ui->inputUsername->text();

    Account h;

    vector <AccountInfo> newAccount;


    found = h.checkUsername(username, i);




    if (found)
    {
        newAccount = h.accounts;
        if(newAccount[i].adminStatus == "yes")
        {
            newAccount[i].adminStatus = "no";
            messageBox.setText("User admin status has changed to regular user!");
            messageBox.setFixedSize(500, 200);
            messageBox.exec();
            this->close();

            h.accounts = newAccount;

            h.CloseAccount();
        }
        else
        {
            newAccount[i].adminStatus = "yes";
            messageBox.setText("User admin status has changed to admin!");
            messageBox.setFixedSize(500, 200);
            messageBox.exec();
            this->close();

            h.accounts = newAccount;
            h.CloseAccount();
        }

    }
    else
    {
        messageBox.setText("User not found!");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
        this->close();
    }
}
