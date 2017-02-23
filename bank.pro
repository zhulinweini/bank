#-------------------------------------------------
#
# Project created by QtCreator 2016-10-18T21:20:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bank
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    admin.cpp \
    user.cpp \
    slite3_function.c \
    sqlite3.c

HEADERS  += widget.h \
    admin.h \
    user.h \
    slite3_function.h \
    sqlite3.h

FORMS    += widget.ui \
    admin.ui \
    user.ui

OTHER_FILES += \
    ../build-bank-Desktop_Qt_5_2_0_MinGW_32bit-Debug/bank.db
