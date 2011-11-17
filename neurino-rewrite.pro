#-------------------------------------------------
#
# Project created by QtCreator 2011-11-16T18:13:23
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = neurino-rewrite
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    functions/function.cpp \
    functions/elliottfunction.cpp \
    functions/elliottsymmfunction.cpp \
    functions/linearfunction.cpp \
    functions/sigmoidfunction.cpp \
    functions/tanhfunction.cpp \
    functions/thresholdfunction.cpp \
    data/networkdata.cpp \
    data/sample.cpp \
    data/networkdataarray.cpp \
    data/networkdatacsv.cpp

HEADERS += \
    functions/function.h \
    functions/elliottfunction.h \
    config.h \
    functions/elliottsymmfunction.h \
    functions/linearfunction.h \
    functions/sigmoidfunction.h \
    functions/tanhfunction.h \
    functions/thresholdfunction.h \
    data/networkdata.h \
    data/sample.h \
    data/networkdataarray.h \
    data/networkdatacsv.h























