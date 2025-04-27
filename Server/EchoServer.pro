QT += core network
QT -= gui
QT += sql

TARGET = EchoServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    database.cpp \
    mytcpserver.cpp \
    serverfunction.cpp

HEADERS += \
    database.h \
    mytcpserver.h \
    serverfunction.h

