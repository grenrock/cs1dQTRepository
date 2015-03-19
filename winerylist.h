#ifndef WINERYLIST_H
#define WINERYLIST_H

#include <QDialog>
#include "displaywinery.h"
#include "winery.h"

namespace Ui {
class WineryList;
}

class WineryList : public QDialog
{
    Q_OBJECT

public:

        explicit WineryList(QWidget *parent = 0);
        void ReadIn();
        ~WineryList();

private slots:
        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

private:

        Ui::WineryList *ui;
        QVector<winery> currentWinery;
        int numWineries;
};

#endif // WINERYLIST_H
