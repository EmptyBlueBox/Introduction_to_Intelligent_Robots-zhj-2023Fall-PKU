#-------------------------------------------------
#
# Project created by QtCreator 2016-11-27T15:05:13
#
#-------------------------------------------------

QT       += widgets

QT       -= gui

TARGET = OGMexample_module
TEMPLATE = lib

DEFINES += OGMEXAMPLE_MODULE_LIBRARY

SOURCES += ogmexample_module.cpp \
    Algor/Mapping/ProcessorMulti/Edit/Bresenham.cpp

HEADERS += ogmexample_module.h\
        ogmexample_module_global.h \
    Algor/Mapping/ProcessorMulti/Edit/Bresenham.h
LIBS +=-L /usr/local/lib/ \
-lopencv_core \
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_ml \
-lopencv_video \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_contrib \
-lopencv_legacy \
-lopencv_flann
unix {
    target.path = /usr/lib
    INSTALLS += target
}

PROJNAME = OGMexample_module
INSTTYPE = MOD
include(RobotSDK_Main.pri)
