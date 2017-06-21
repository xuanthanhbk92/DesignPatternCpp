QT += core
QT -= gui

CONFIG += c++11

TARGET = DesignPatern
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Creation/singleton.cpp \
    Creation/abtractfactory.cpp \
    Creation/builder.cpp \
    Creation/objectpool.cpp \
    Creation/prototype.cpp \
    Creation/factorymethod.cpp \
    Behavior/command.cpp

HEADERS += \
    Creation/singleton.h \
    Creation/abtractfactory.h \
    Creation/builder.h \
    Creation/objectpool.h \
    Creation/prototype.h \
    Creation/factorymethod.h \
    Behavior/command.h

DISTFILES += \
    Creation/ReadMe.md \
    README \
    Structure/README.md \
    Behavior/README.md
