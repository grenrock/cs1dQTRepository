#ifndef ADMINMAIN_H
#define ADMINMAIN_H

#include "account.h"

#include <QDialog>

namespace Ui {
class adminmain;
}

class adminmain : public QDialog
{
    Q_OBJECT

public:
    explicit adminmain(QWidget *parent = 0);
    ~adminmain();

    //User edits;
    void AddUser();
    void DeleteUser();

    void print();
    void search();

    //Winery Edits
    void AddWinery();
    void DeleteWinery();

private slots:
    void on_EditUsersButton_clicked();

    void on_EditWineriesButton_clicked();

private:
    Ui::adminmain *ui;
};

#endif // ADMINMAIN_H
