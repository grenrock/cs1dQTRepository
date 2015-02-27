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
    register.cpp

HEADERS  += mainwindow.h \
    account.h \
    adminmain.h \
    edituser.h \
    editadminstatus.h \
    register.h

FORMS    += mainwindow.ui \
    account.ui \
    adminmain.ui \
    edituser.ui \
    editadminstatus.ui \
    register.ui

DISTFILES += \
    LoginInfo.txt
