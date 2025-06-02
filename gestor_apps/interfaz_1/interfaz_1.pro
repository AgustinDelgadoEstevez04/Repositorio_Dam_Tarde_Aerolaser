QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = interfaz_1
TEMPLATE = app
CONFIG += c++17


SOURCES += \
    loggin.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    loggin.h \
    mainwindow.h

FORMS += \
    loggin.ui \
    mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core/release/ -lcore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core/debug/ -lcore
else:unix: LIBS += -L$$OUT_PWD/../core/ -lcore

INCLUDEPATH += $$PWD/../core
DEPENDPATH += $$PWD/../core

RESOURCES += \
    resources.qrc

DISTFILES += \
    imagenes/OIP (1).jpg
