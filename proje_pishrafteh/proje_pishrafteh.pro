#-------------------------------------------------
#
# Project created by QtCreator 2023-04-15T00:03:59
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proje_pishrafteh
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

CONFIG += c++11

SOURCES += \
        faze2.cpp \
        main.cpp \
        pishvas.cpp \
        sabtenamvavorood.cpp \
        safhe_taeid.cpp

HEADERS += \
        codetaeid.h \
        faze2.h \
        pishvas.h \
        sabtenamvavorood.h \
        safhe_taeid.h

FORMS += \
        faze2.ui \
        pishvas.ui \
        sabtenamvavorood.ui \
        safhe_taeid.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    capchas.qrc \
    hide_show_eye_button_pass.qrc \
    regenarete_capcha.qrc \
    show_hide_eye_small_button_pass.qrc \
    welcome.qrc

DISTFILES += \
    hide_eye_small.jpg \
    show_eye_small.jpg
