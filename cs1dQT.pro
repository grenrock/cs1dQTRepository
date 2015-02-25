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
    account.cpp

HEADERS  += mainwindow.h \
    account.h

FORMS    += mainwindow.ui \
    account.ui

DISTFILES += \
    LoginInfo.txt
