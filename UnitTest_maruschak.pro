QT += testlib
QT += sql
QT += network
QT += widgets

QT -= gui

QT -= multimedia imageformats

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_regtest.cpp \
    ../TripLink2_0/TripLink/server/database.cpp \
    ../TripLink2_0/TripLink/server/mytcpserver.cpp \
    ../TripLink2_0/TripLink/server/serverfunction.cpp

HEADERS += \
    ../TripLink2_0/TripLink/server/database.h \
    ../TripLink2_0/TripLink/server/mytcpserver.h \
    ../TripLink2_0/TripLink/server/serverfunction.h
