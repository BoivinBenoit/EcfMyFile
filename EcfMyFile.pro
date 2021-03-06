#-------------------------------------------------
#
# Project created by QtCreator 2015-06-04T13:37:12
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = EcfMyFile
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app

SOURCES += main.cpp \
    filepool.cpp \
    writer.cpp \
    zippedbuffer.cpp \
    zippedbufferpool.cpp \
    epsifilecompressor.cpp \
    zipper.cpp

HEADERS += \
    filepool.h \
    writer.h \
    zippedbuffer.h \
    zippedbufferpool.h \
    epsifilecompressor.h \
    zipper.h

OTHER_FILES +=
