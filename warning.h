#ifndef WARNING_H
#define WARNING_H

#include <QDialog>

namespace Ui {
class Warning;
}

class Warning : public QDialog
{
    Q_OBJECT

public:
    explicit Warning(QWidget *parent = 0);
    bool getExit();
    ~Warning();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Warning *ui;
    bool exitWarning;
};

#endif // WARNING_H
