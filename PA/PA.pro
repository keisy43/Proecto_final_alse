#-------------------------------------------------
#
# Project created by QtCreator 2020-05-05T20:18:01
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PA
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


SOURCES += \
        main.cpp \
        usuario.cpp \
    regu.cpp \
    regpc.cpp \
    menu.cpp \
    prueba.cpp \
    tiempod.cpp \
    aciertos.cpp \
    db_local.cpp \
    paciente.cpp

HEADERS += \
        usuario.h \
    regu.h \
    regpc.h \
    menu.h \
    prueba.h \
    tiempod.h \
    aciertos.h \
    db_local.h \
    paciente.h

FORMS += \
        usuario.ui \
    regu.ui \
    regpc.ui \
    menu.ui \
    prueba.ui \
    tiempod.ui \
    aciertos.ui \
    paciente.ui

RESOURCES += \
    resources.qrc

LIBS += \
        -lsqlite3
