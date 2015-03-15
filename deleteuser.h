#ifndef DELETEUSER_H
#define DELETEUSER_H
#include "account.h"
#include <QDialog>

namespace Ui {
class deleteUser;
}

class deleteUser : public QDialog
{
    Q_OBJECT

public:
    explicit deleteUser(QWidget *parent = 0);
    ~deleteUser();

    void DeleteUser();

private slots:
    void on_Cancel_clicked();

    void on_DeleteButton_clicked();

private:
    Ui::deleteUser *ui;
};

#endif // DELETEUSER_H
