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
#include <QtGui/QIcon>
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
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *loggin)
    {
        if (loggin->objectName().isEmpty())
            loggin->setObjectName("loggin");
        loggin->resize(315, 284);
        QPalette palette;
        QBrush brush(QColor(235, 252, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush1);
        loggin->setPalette(palette);
        loggin->setMouseTracking(false);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::UserAvailable));
        loggin->setWindowIcon(icon);
        centralwidget = new QWidget(loggin);
        centralwidget->setObjectName("centralwidget");
        iniciar = new QPushButton(centralwidget);
        iniciar->setObjectName("iniciar");
        iniciar->setGeometry(QRect(160, 190, 75, 24));
        registrar = new QPushButton(centralwidget);
        registrar->setObjectName("registrar");
        registrar->setGeometry(QRect(80, 190, 75, 24));
        usuario = new QLineEdit(centralwidget);
        usuario->setObjectName("usuario");
        usuario->setGeometry(QRect(90, 80, 141, 31));
        contrasena = new QLineEdit(centralwidget);
        contrasena->setObjectName("contrasena");
        contrasena->setGeometry(QRect(90, 140, 141, 31));
        contrasena->setEchoMode(QLineEdit::EchoMode::Password);
        imagen = new QLabel(centralwidget);
        imagen->setObjectName("imagen");
        imagen->setGeometry(QRect(40, 80, 41, 31));
        imagen->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/usuario.png")));
        imagen->setScaledContents(true);
        imagen1 = new QLabel(centralwidget);
        imagen1->setObjectName("imagen1");
        imagen1->setGeometry(QRect(40, 140, 41, 31));
        QFont font;
        font.setUnderline(false);
        font.setKerning(true);
        imagen1->setFont(font);
        imagen1->setAutoFillBackground(false);
        imagen1->setStyleSheet(QString::fromUtf8(""));
        imagen1->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/password.png")));
        imagen1->setScaledContents(true);
        imagen1->setWordWrap(false);
        titulo = new QLabel(centralwidget);
        titulo->setObjectName("titulo");
        titulo->setGeometry(QRect(90, 10, 121, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(false);
        titulo->setFont(font1);
        titulo->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        titulo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 60, 49, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 120, 71, 16));
        loggin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(loggin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 315, 22));
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
        iniciar->setText(QCoreApplication::translate("loggin", "iniciar sesi\303\263n", nullptr));
        registrar->setText(QCoreApplication::translate("loggin", "registrar", nullptr));
        contrasena->setText(QString());
        imagen->setText(QString());
        imagen1->setText(QString());
        titulo->setText(QCoreApplication::translate("loggin", "LOGGIN", nullptr));
        label->setText(QCoreApplication::translate("loggin", "User", nullptr));
        label_2->setText(QCoreApplication::translate("loggin", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loggin: public Ui_loggin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGIN_H
