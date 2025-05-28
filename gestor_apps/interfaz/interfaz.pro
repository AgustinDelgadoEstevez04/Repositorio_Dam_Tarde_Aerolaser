# interfaz/interfaz.pro
QT += core gui widgets sql # Agrega 'sql' porque loggin.cpp ahora usa funcionalidades de base de datos a través de DatabaseManager
                          # 'widgets' para elementos de interfaz gráfica (QMessageBox, QLineEdit, etc.)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets # Asegura que se agregue 'widgets' para Qt5 y superior

CONFIG += c++17

# Puedes hacer que tu código falle al compilar si usa APIs obsoletas.
# Para ello, descomenta la siguiente línea.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000     # deshabilita todas las APIs obsoletas antes de Qt 6.0.0

SOURCES += \
    main.cpp \
    loggin.cpp

HEADERS += \
    loggin.h

# Importante: Incluir la ruta a los headers del proyecto 'core'
# $$PWD es la ruta del directorio de 'interfaz.pro'.
# ../core significa "sube un nivel (al directorio padre) y luego entra en la carpeta 'core'".
INCLUDEPATH += $$PWD/../core

# Importante: Enlazar con la librería generada por el proyecto 'core'
# -L$$OUT_PWD/../core: Indica al enlazador dónde buscar la librería 'core'.
#   $$OUT_PWD es el directorio de construcción del proyecto 'interfaz'.
#   Se asume que la librería 'core' se construye en un subdirectorio que es hermano del directorio de construcción de 'interfaz',
#   o directamente en la carpeta 'core' del código fuente (en algunos setups de Qt Creator).
#   Podría ser necesario ajustar esta ruta si tu estructura de directorios de compilación es diferente,
#   por ejemplo, si 'core' compila en una carpeta como 'build-core-Desktop_Qt_...-Debug'.
# -lcore: Le dice al enlazador que use la librería llamada 'core'.
LIBS += -L$$OUT_PWD/../core -lcore

FORMS += \
    loggin.ui

# Reglas por defecto para el despliegue.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imgn.qrc
