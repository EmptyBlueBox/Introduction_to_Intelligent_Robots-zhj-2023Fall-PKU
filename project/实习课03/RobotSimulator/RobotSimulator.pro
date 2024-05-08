#-------------------------------------------------
#
# Project created by QtCreator 2016-12-25T17:31:16
#
#-------------------------------------------------

QT       += core gui

CONFIG +=c++11 c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RobotSimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

PROJNAME = RobotSimulator
INSTTYPE = APP
include(RobotSDK_Main.pri)
