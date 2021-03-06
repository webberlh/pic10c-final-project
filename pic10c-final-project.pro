#-------------------------------------------------
#
# Project created by QtCreator 2018-05-14T14:12:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = pic10c-final-project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        differentialequationcalc.cpp \
        qcustomplot.cpp \
    pythonwrapper.cpp

HEADERS += \
        differentialequationcalc.h \
        qcustomplot.h \
    pythonwrapper.h

FORMS += \
        differentialequationcalc.ui

INCLUDEPATH += \
        /usr/include/python3.5m
        /usr/include/x86_64-linux-gnu/python3.5m

LIBS += \
        -lpython3.5m

DISTFILES += \
    diff_eq_solver.py
