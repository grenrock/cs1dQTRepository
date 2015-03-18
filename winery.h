#ifndef WINERY_H
#define WINERY_H
#include <iostream>
#include <qstring>
#include <QVector>
struct wine
{
    QString name;
    QString year;
    QString price;
};

struct winery
{
    QString name;
    QString number;
    QString distanceFrom[30];
    QString milesFrom;
    QString numWines;
    QVector<wine> winesOffered;
};
#endif // WINERY_H

