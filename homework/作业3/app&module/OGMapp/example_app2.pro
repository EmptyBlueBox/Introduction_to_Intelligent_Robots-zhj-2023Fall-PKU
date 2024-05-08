#-------------------------------------------------
#
# Project created by QtCreator 2016-11-13T14:22:32
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = example_app2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

PROJNAME = example_app2
INSTTYPE = APP
include(RobotSDK_Main.pri)
