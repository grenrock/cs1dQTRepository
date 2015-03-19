#ifndef VISITALLWINERIES_H
#define VISITALLWINERIES_H

//#include <QWidget>
#include <QDialog>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include "winery.h"
#include "purchasewine.h"
#include "warning.h"

namespace Ui {
class visitallwineries;
}

class visitallwineries : public QDialog
{
    Q_OBJECT

public:
    explicit visitallwineries(QWidget *parent = 0);
    ~visitallwineries();

protected:
    // initializes the listing of all wineries from file
    void initializeListing();

    // fills the combo box with wineries from listing
    void initializeComboBox();

    // calculates the shortest tour from a unique starting point
    void calculateTourRoute(QVector<winery>& tour,   // empty list where the planned route for the tour will be stored
                            QVector<winery>& places, // user's selection of tour locations (the front of the list being the starting point)
                            float& totalDistance);   // total distance of the tour
    void setOrder(QVector<wine> orderSet);
private slots:
    // calculates a tour from the starting point selected in the comboBox
    void on_pushButton_clicked();

    void on_purchaseWine_clicked();

    void on_back_clicked();

private:
    Ui::visitallwineries *ui;
    QVector<winery> listing;  // container of all wineries
    QVector<winery> fullTour; // shortest tour of all wineries
    float totalDistance;      // total distance of the tour
    QVector<wine> tWine;
    bool exitStatus;
};

#endif // VISITALLWINERIES_H

