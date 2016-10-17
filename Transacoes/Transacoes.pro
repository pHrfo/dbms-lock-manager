QT += core
QT -= gui

CONFIG += c++11

TARGET = Transacoes
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    state.cpp \
    transaction.cpp \
    controller.cpp \
    lockmanager.cpp \
    locktable.cpp \
    item.cpp \
    lock.cpp \
    waitq.cpp

HEADERS += \
    general.h \
    state.h \
    transaction.h \
    controller.h \
    lockmanager.h \
    locktable.h \
    item.h \
    lock.h \
    waitq.h
