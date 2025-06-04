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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loggin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *registrar;
    QPushButton *iniciar;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *imagen;
    QLineEdit *usuario;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *imagen1;
    QLineEdit *contrasena;
    QLabel *titulo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *loggin)
    {
        if (loggin->objectName().isEmpty())
            loggin->setObjectName("loggin");
        loggin->resize(1225, 814);
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
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(400, 200, 400, 200);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(75, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        registrar = new QPushButton(centralwidget);
        registrar->setObjectName("registrar");
        registrar->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(registrar);

        iniciar = new QPushButton(centralwidget);
        iniciar->setObjectName("iniciar");
        iniciar->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(iniciar);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        verticalLayout_3->addWidget(label);

        imagen = new QLabel(centralwidget);
        imagen->setObjectName("imagen");
        imagen->setMaximumSize(QSize(70, 70));
        imagen->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/usuario.png")));
        imagen->setScaledContents(true);

        verticalLayout_3->addWidget(imagen);


        horizontalLayout_3->addLayout(verticalLayout_3);

        usuario = new QLineEdit(centralwidget);
        usuario->setObjectName("usuario");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(usuario->sizePolicy().hasHeightForWidth());
        usuario->setSizePolicy(sizePolicy);
        usuario->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(usuario);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(13);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        imagen1 = new QLabel(centralwidget);
        imagen1->setObjectName("imagen1");
        imagen1->setEnabled(true);
        imagen1->setMaximumSize(QSize(70, 70));
        QFont font2;
        font2.setUnderline(false);
        font2.setKerning(true);
        imagen1->setFont(font2);
        imagen1->setAutoFillBackground(false);
        imagen1->setStyleSheet(QString::fromUtf8(""));
        imagen1->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/password.png")));
        imagen1->setScaledContents(true);
        imagen1->setWordWrap(false);

        verticalLayout->addWidget(imagen1);


        horizontalLayout_2->addLayout(verticalLayout);

        contrasena = new QLineEdit(centralwidget);
        contrasena->setObjectName("contrasena");
        contrasena->setMinimumSize(QSize(50, 30));
        contrasena->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_2->addWidget(contrasena);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        titulo = new QLabel(centralwidget);
        titulo->setObjectName("titulo");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(26);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setUnderline(false);
        titulo->setFont(font3);
        titulo->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        titulo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(titulo, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        loggin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(loggin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1225, 22));
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
        registrar->setText(QCoreApplication::translate("loggin", "registrar", nullptr));
        iniciar->setText(QCoreApplication::translate("loggin", "iniciar sesi\303\263n", nullptr));
        label->setText(QCoreApplication::translate("loggin", "User", nullptr));
        imagen->setText(QString());
        label_2->setText(QCoreApplication::translate("loggin", "Password", nullptr));
        imagen1->setText(QString());
        contrasena->setText(QString());
        titulo->setText(QCoreApplication::translate("loggin", "LOGGIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loggin: public Ui_loggin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGIN_H
