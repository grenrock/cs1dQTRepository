#ifndef EDITADMINSTATUS_H
#define EDITADMINSTATUS_H
#include "account.h"
#include <QDialog>

namespace Ui {
class editAdminStatus;
}

class editAdminStatus : public QDialog
{
    Q_OBJECT

public:
    explicit editAdminStatus(QWidget *parent = 0);
    ~editAdminStatus();

    void adminStatus();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::editAdminStatus *ui;
};

#endif // EDITADMINSTATUS_H
