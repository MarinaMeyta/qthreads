QT       += core

QT       -= gui

TARGET = qthreads
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    worker.cpp \
    controller.cpp

HEADERS += \
    worker.h \
    controller.h
