QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    carwindow.cpp \
    companionwindow.cpp \
    drivercompanionwindow.cpp \
    driverwindow.cpp \
    feetback.cpp \
    finishwindow.cpp \
    function_for_client.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    managerform.cpp \
    networkclient.cpp \
    profile.cpp \
    registrationwindow.cpp

HEADERS += \
    carwindow.h \
    companionwindow.h \
    drivercompanionwindow.h \
    driverwindow.h \
    feetback.h \
    finishwindow.h \
    function_for_client.h \
    loginwindow.h \
    mainwindow.h \
    managerform.h \
    networkclient.h \
    profile.h \
    registrationwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    carwindow.ui \
    companionwindow.ui \
    drivercompanionwindow.ui \
    driverwindow.ui \
    feetback.ui \
    finishwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    profile.ui \
    registrationwindow.ui
