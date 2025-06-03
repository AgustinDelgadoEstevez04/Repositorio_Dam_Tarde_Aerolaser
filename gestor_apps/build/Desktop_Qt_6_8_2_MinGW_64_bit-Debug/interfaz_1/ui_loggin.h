/********************************************************************************
** Form generated from reading UI file 'loggin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGIN_H
#define UI_LOGGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loggin
{
public:
    QWidget *centralwidget;
    QPushButton *iniciar;
    QPushButton *registrar;
    QLineEdit *usuario;
    QLineEdit *contrasena;
    QLabel *imagen;
    QLabel *imagen1;
    QLabel *titulo;
    QPushButton *eliminar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *loggin)
    {
        if (loggin->objectName().isEmpty())
            loggin->setObjectName("loggin");
        loggin->resize(301, 296);
        QPalette palette;
        QBrush brush(QColor(85, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        loggin->setPalette(palette);
        centralwidget = new QWidget(loggin);
        centralwidget->setObjectName("centralwidget");
        iniciar = new QPushButton(centralwidget);
        iniciar->setObjectName("iniciar");
        iniciar->setGeometry(QRect(160, 160, 81, 31));
        registrar = new QPushButton(centralwidget);
        registrar->setObjectName("registrar");
        registrar->setGeometry(QRect(60, 160, 91, 31));
        usuario = new QLineEdit(centralwidget);
        usuario->setObjectName("usuario");
        usuario->setGeometry(QRect(100, 60, 141, 31));
        contrasena = new QLineEdit(centralwidget);
        contrasena->setObjectName("contrasena");
        contrasena->setGeometry(QRect(100, 120, 141, 31));
        contrasena->setEchoMode(QLineEdit::EchoMode::Password);
        imagen = new QLabel(centralwidget);
        imagen->setObjectName("imagen");
        imagen->setGeometry(QRect(40, 60, 51, 31));
        imagen->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/OIP.jpg")));
        imagen->setScaledContents(true);
        imagen1 = new QLabel(centralwidget);
        imagen1->setObjectName("imagen1");
        imagen1->setGeometry(QRect(40, 120, 51, 31));
        imagen1->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/OIP (2).jpg")));
        imagen1->setScaledContents(true);
        titulo = new QLabel(centralwidget);
        titulo->setObjectName("titulo");
        titulo->setGeometry(QRect(90, 0, 121, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tahoma")});
        font.setPointSize(12);
        font.setBold(true);
        titulo->setFont(font);
        titulo->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        titulo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        eliminar = new QPushButton(centralwidget);
        eliminar->setObjectName("eliminar");
        eliminar->setGeometry(QRect(110, 200, 91, 24));
        loggin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(loggin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 301, 22));
        loggin->setMenuBar(menubar);
        statusbar = new QStatusBar(loggin);
        statusbar->setObjectName("statusbar");
        loggin->setStatusBar(statusbar);

        retranslateUi(loggin);

        QMetaObject::connectSlotsByName(loggin);
    } // setupUi

    void retranslateUi(QMainWindow *loggin)
    {
        loggin->setWindowTitle(QCoreApplication::translate("loggin", "loggin", nullptr));
        iniciar->setText(QCoreApplication::translate("loggin", "iniciar sesion", nullptr));
        registrar->setText(QCoreApplication::translate("loggin", "registrar", nullptr));
        contrasena->setText(QString());
        imagen->setText(QString());
        imagen1->setText(QString());
        titulo->setText(QCoreApplication::translate("loggin", "LOGGIN", nullptr));
        eliminar->setText(QCoreApplication::translate("loggin", "eliminar usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loggin: public Ui_loggin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGIN_H
