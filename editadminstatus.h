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

private:
    Ui::editAdminStatus *ui;
};

#endif // EDITADMINSTATUS_H
