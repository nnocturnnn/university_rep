QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autor.cpp \
    dialog.cpp \
    exer.cpp \
    info.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    autor.h \
    dialog.h \
    exer.h \
    info.h \
    mainwindow.h

FORMS += \
    autor.ui \
    dialog.ui \
    exer.ui \
    info.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    10lab.pro \
    8lab.pro \
    9lab.pro

DISTFILES += \
    10lab.pro.user \
    11lab.pro.user \
    8lab.pro.user \
    9lab.pro.user \
    zast.jpg
