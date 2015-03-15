#ifndef ADDUSER_H
#define ADDUSER_H
#include "account.h"

#include <QDialog>

namespace Ui {
class addUser;
}

class addUser : public QDialog
{
    Q_OBJECT

public:
    explicit addUser(QWidget *parent = 0);
    ~addUser();

    //REGISTRATION OPTIONS
    void ReadFile();
    void checkUsernameAvailability();
    void addAccount();
    void printToFile();
    void add();

private:
    Ui::addUser *ui;
    AccountInfo info;
    vector<AccountInfo> accounts;

private slots:
    void on_submit_clicked();
    void on_cancel_clicked();
};

#endif // ADDUSER_H
