QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = antgraph
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp\
        mainwindow.cpp \
    nodeitem.cpp \
    mgraph.cpp \
    mnode.cpp \
    medge.cpp \
    mgscena.cpp \
    mant.cpp \
    edgeitem.cpp

HEADERS  += mainwindow.h \
    nodeitem.h \
    mgraph.h \
    mnode.h \
    medge.h \
    mgscena.h \
    mant.h \
    edgeitem.h

FORMS    += mainwindow.ui
