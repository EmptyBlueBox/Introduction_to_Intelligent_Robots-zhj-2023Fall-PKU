#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T14:28:56
#
#-------------------------------------------------

QT       += widgets xml

TARGET = testLib
TEMPLATE = lib

DEFINES += TESTLIB_LIBRARY

SOURCES += testlib.cpp

HEADERS += testlib.h\
        testlib_global.h

LIBS += -lopencv_core -lopencv_highgui

unix {
    target.path = /usr/lib
    INSTALLS += target
}

PROJNAME = testLib
INSTTYPE = MOD
include(RobotSDK_Main.pri)
