#-------------------------------------------------
#
# Project created by QtCreator 2015-02-12T19:56:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cs1dQT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    account.cpp \
    adminmain.cpp \
    edituser.cpp \
    editadminstatus.cpp \
    register.cpp \
    winewindow.cpp \
    customtrip.cpp \
    displaywinery.cpp \
    trip.cpp \
    viewcustomtrip.cpp \
    winerylist.cpp \
    editwineries.cpp \
    deleteuser.cpp \
    addwinewineryselector.cpp \
    addwine.cpp \
    wineselector.cpp \
    changeprice.cpp

HEADERS  += mainwindow.h \
    account.h \
    adminmain.h \
    edituser.h \
    editadminstatus.h \
    register.h \
    winewindow.h \
    winery.h \
    customtrip.h \
    displaywinery.h \
    trip.h \
    viewcustomtrip.h \
    winerylist.h \
    editwineries.h \
    deleteuser.h \
    addwinewineryselector.h \
    addwine.h \
    wineselector.h \
    changeprice.h

FORMS    += mainwindow.ui \
    account.ui \
    adminmain.ui \
    edituser.ui \
    editadminstatus.ui \
    register.ui \
    winewindow.ui \
    customtrip.ui \
    displaywinery.ui \
    trip.ui \
    viewcustomtrip.ui \
    winerylist.ui \
    editwineries.ui \
    deleteuser.ui \
    addwinewineryselector.ui \
    addwine.ui \
    wineselector.ui \
    changeprice.ui

DISTFILES += \
    WineryList.txt \
    LoginInfo.txt
