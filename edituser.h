#ifndef EDITUSER_H
#define EDITUSER_H

#include <QDialog>

namespace Ui {
class editUser;
}

class editUser : public QDialog
{
    Q_OBJECT

public:
    explicit editUser(QWidget *parent = 0);
    ~editUser();

private slots:
    void on_addUserButton_clicked();

    void on_deleteUserButton_clicked();

    void on_editAdminStatusButton_clicked();

private:
    Ui::editUser *ui;
};

#endif // EDITUSER_H
