#-------------------------------------------------
#
# Project created by QtCreator 2016-04-27T14:25:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Banksey
TEMPLATE = app


SOURCES += main.cpp\
        atm.cpp \
    bankaccount.cpp

HEADERS  += atm.h \
    bankaccount.h

FORMS    += atm.ui
