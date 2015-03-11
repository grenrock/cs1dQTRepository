#ifndef WINEWINDOW_H
#define WINEWINDOW_H

#include <QDialog>

namespace Ui {
class WineWindow;
}

class WineWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WineWindow(QWidget *parent = 0);
    ~WineWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WineWindow *ui;
};

#endif // WINEWINDOW_H
