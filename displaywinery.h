#ifndef DISPLAYWINERY_H
#define DISPLAYWINERY_H

#include <QDialog>
#include "winerylist.h"
#include "winery.h"
namespace Ui {
class DisplayWinery;
}

class DisplayWinery : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayWinery(QWidget *parent = 0);
    void setWinery(QVector<winery> inList, int index, int numWines);
    ~DisplayWinery();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::DisplayWinery *ui;
    winery displayWinery;
    QVector<winery> otherWineries;
};

#endif // DISPLAYWINERY_H
