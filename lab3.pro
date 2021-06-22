QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barchart.cpp \
    byfiletype_calculationstrategy.cpp \
    byfolder_calculationstrategy.cpp \
    calculationstrategy.cpp \
    entry.cpp \
    filesmodel.cpp \
    main.cpp \
    mainwindow.cpp \
    piechart.cpp

HEADERS += \
    barchart.h \
    byfiletype_calculationstrategy.h \
    byfolder_calculationstrategy.h \
    calculationstrategy.h \
    entry.h \
    filesmodel.h \
    mainwindow.h \
    piechart.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
