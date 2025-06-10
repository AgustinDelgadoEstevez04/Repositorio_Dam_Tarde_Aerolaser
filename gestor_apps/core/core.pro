QT += sql
QT -= gui
TEMPLATE = lib
DEFINES += CORE_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aplicacion.cpp \
    aplicaciondao.cpp \
    aplicacionmodel.cpp \
    aplicacionusuario.cpp \
    aplicacionusuariodao.cpp \
    aplicacionusuariomodel.cpp \
    databasemanager.cpp \
    usuario.cpp \
    usuariodao.cpp \
    usuariomodel.cpp

HEADERS += \
    aplicacion.h \
    aplicaciondao.h \
    aplicacionmodel.h \
    aplicacionusuario.h \
    aplicacionusuariodao.h \
    aplicacionusuariomodel.h \
    core_global.h \
    databasemanager.h \
    usuario.h \
    usuariodao.h \
    usuariomodel.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
