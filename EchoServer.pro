QT += core network
QT -= gui

TARGET = EchoServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mytcpserver.cpp

HEADERS += \
    mytcpserver.h

