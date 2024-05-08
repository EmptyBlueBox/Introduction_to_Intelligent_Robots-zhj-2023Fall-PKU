#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T14:59:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


PROJNAME = testApp
INSTTYPE = APP
include(RobotSDK_Main.pri)
