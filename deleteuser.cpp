#include "deleteuser.h"
#include "ui_deleteuser.h"
#include <QDebug>
#include <QMessageBox>

deleteUser::deleteUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteUser)
{
    ui->setupUi(this);
    Account h;
    h.ReadFile();

    int size;

    size = h.accounts.size();


    vector<AccountInfo> newAccount;

    newAccount = h.accounts;

    for(int j = 0; j < size ; j ++)
    {
        if(newAccount[j].adminStatus == "no")
        {
          QString str =  newAccount[j].userName;
          QString as  =  newAccount[j].adminStatus;
          QString name = newAccount[j].name;
          ui->listWidget->addItem("User Name: "    + str);
          ui->listWidget->addItem("Name: " + name);
          ui->listWidget->addItem("Admin Status: " + as  + '\n' + "---------------------------");
        }
    }
}

deleteUser::~deleteUser()
{
    delete ui;
}

void deleteUser::DeleteUser()
{

}

void deleteUser::on_Cancel_clicked()
{
    this->close();
}

void deleteUser::on_DeleteButton_clicked()
{
    QMessageBox messageBox;
    QString username;
    QString messageString;
    unsigned int i = 0;
    bool found = false;
    int size;

    username = ui->inputBox->text();

    Account h;

    vector <AccountInfo> newAccount;

    found = h.checkUsername(username, i);

    newAccount = h.accounts;

    if (found)
    {
        size = i;

        newAccount.erase(newAccount.begin() + size);
        messageBox.setText("User has been deleted!");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();

        h.accounts = newAccount;
        h.CloseAccount();
        this->close();
    }
    else
    {
        messageBox.setText("User was NOT found!");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();

        h.accounts = newAccount;
        h.CloseAccount();
    }
}
