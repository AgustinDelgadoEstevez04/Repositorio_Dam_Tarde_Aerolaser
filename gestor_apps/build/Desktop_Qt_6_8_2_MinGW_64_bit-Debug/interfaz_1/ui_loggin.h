/********************************************************************************
** Form generated from reading UI file 'loggin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
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
        loggin->resize(309, 278);
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
        iniciar->setGeometry(QRect(150, 170, 75, 24));
        registrar = new QPushButton(centralwidget);
        registrar->setObjectName("registrar");
        registrar->setGeometry(QRect(70, 170, 75, 24));
        usuario = new QLineEdit(centralwidget);
        usuario->setObjectName("usuario");
        usuario->setGeometry(QRect(90, 90, 141, 21));
        contrasena = new QLineEdit(centralwidget);
        contrasena->setObjectName("contrasena");
        contrasena->setGeometry(QRect(90, 130, 141, 21));
        contrasena->setEchoMode(QLineEdit::EchoMode::Password);
        imagen = new QLabel(centralwidget);
        imagen->setObjectName("imagen");
        imagen->setGeometry(QRect(30, 91, 51, 20));
        imagen->setPixmap(QPixmap(QString::fromUtf8(":/img/imagenes/OIP.jpg")));
        imagen->setScaledContents(true);
        imagen1 = new QLabel(centralwidget);
        imagen1->setObjectName("imagen1");
        imagen1->setGeometry(QRect(30, 130, 51, 21));
        imagen1->setPixmap(QPixmap(QString::fromUtf8(":/img/imagenes/OIP (2).jpg")));
        imagen1->setScaledContents(true);
        titulo = new QLabel(centralwidget);
        titulo->setObjectName("titulo");
        titulo->setGeometry(QRect(100, 0, 121, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tahoma")});
        font.setPointSize(12);
        font.setBold(true);
        titulo->setFont(font);
        titulo->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        eliminar = new QPushButton(centralwidget);
        eliminar->setObjectName("eliminar");
        eliminar->setGeometry(QRect(110, 200, 75, 24));
        loggin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(loggin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 309, 22));
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
        eliminar->setText(QCoreApplication::translate("loggin", "del usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loggin: public Ui_loggin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGIN_H
