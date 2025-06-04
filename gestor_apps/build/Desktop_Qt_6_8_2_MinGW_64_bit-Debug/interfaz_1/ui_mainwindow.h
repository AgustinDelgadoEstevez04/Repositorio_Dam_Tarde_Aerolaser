/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *favorito_app;
    QPushButton *descargar_app;
    QPushButton *no_descargados_2;
    QProgressBar *barraProgreso;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_filtro;
    QPushButton *favoritos;
    QPushButton *descargados;
    QPushButton *no_descargados;
    QListWidget *lista_filtro;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *barra_busqueda;
    QListView *lista_apps;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *usuario_nombre;
    QPushButton *cerrar_sesion;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuGestor_de_apps;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1078, 727);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush1(QColor(160, 160, 160, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush3(QColor(208, 228, 247, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush4);
        MainWindow->setPalette(palette);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(30, 30, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        label->setPalette(palette1);
        label->setWordWrap(true);

        horizontalLayout_5->addWidget(label);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        favorito_app = new QPushButton(centralwidget);
        favorito_app->setObjectName("favorito_app");
        favorito_app->setMinimumSize(QSize(40, 40));
        favorito_app->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes trabajo/mano arriba.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        favorito_app->setIcon(icon1);
        favorito_app->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(favorito_app);

        descargar_app = new QPushButton(centralwidget);
        descargar_app->setObjectName("descargar_app");
        descargar_app->setMinimumSize(QSize(40, 40));
        descargar_app->setMaximumSize(QSize(40, 40));
        descargar_app->setSizeIncrement(QSize(0, 0));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes trabajo/instalar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        descargar_app->setIcon(icon2);
        descargar_app->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(descargar_app);

        no_descargados_2 = new QPushButton(centralwidget);
        no_descargados_2->setObjectName("no_descargados_2");
        no_descargados_2->setMinimumSize(QSize(40, 40));
        no_descargados_2->setMaximumSize(QSize(30, 40));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes trabajo/no.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        no_descargados_2->setIcon(icon3);
        no_descargados_2->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(no_descargados_2);

        barraProgreso = new QProgressBar(centralwidget);
        barraProgreso->setObjectName("barraProgreso");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(barraProgreso->sizePolicy().hasHeightForWidth());
        barraProgreso->setSizePolicy(sizePolicy);
        barraProgreso->setMinimumSize(QSize(159, 30));
        barraProgreso->setMaximumSize(QSize(0, 30));
        barraProgreso->setSizeIncrement(QSize(0, 70));
        barraProgreso->setBaseSize(QSize(0, 70));
        QFont font;
        font.setPointSize(12);
        barraProgreso->setFont(font);
        barraProgreso->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        barraProgreso->setAutoFillBackground(false);
        barraProgreso->setLocale(QLocale(QLocale::Spanish, QLocale::Spain));
        barraProgreso->setValue(0);
        barraProgreso->setAlignment(Qt::AlignmentFlag::AlignCenter);
        barraProgreso->setTextVisible(false);

        horizontalLayout_4->addWidget(barraProgreso);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout_5, 3, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_filtro = new QLabel(centralwidget);
        label_filtro->setObjectName("label_filtro");
        label_filtro->setMaximumSize(QSize(30, 30));
        label_filtro->setPixmap(QPixmap(QString::fromUtf8(":/imagenes trabajo/filtrar.png")));
        label_filtro->setScaledContents(true);

        horizontalLayout_3->addWidget(label_filtro);

        favoritos = new QPushButton(centralwidget);
        favoritos->setObjectName("favoritos");
        favoritos->setMinimumSize(QSize(0, 40));
        favoritos->setMaximumSize(QSize(40, 40));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagenes trabajo/me-gusta.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        favoritos->setIcon(icon4);
        favoritos->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(favoritos);

        descargados = new QPushButton(centralwidget);
        descargados->setObjectName("descargados");
        descargados->setMinimumSize(QSize(0, 40));
        descargados->setMaximumSize(QSize(40, 40));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagenes trabajo/descargas.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        descargados->setIcon(icon5);
        descargados->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(descargados);

        no_descargados = new QPushButton(centralwidget);
        no_descargados->setObjectName("no_descargados");
        no_descargados->setMaximumSize(QSize(40, 40));
        no_descargados->setIcon(icon3);
        no_descargados->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(no_descargados);


        verticalLayout_2->addLayout(horizontalLayout_3);

        lista_filtro = new QListWidget(centralwidget);
        lista_filtro->setObjectName("lista_filtro");

        verticalLayout_2->addWidget(lista_filtro);


        gridLayout->addLayout(verticalLayout_2, 2, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, -1, 0, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(30, 30));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/imagenes trabajo/busqueda-de-lupa.png")));
        label_3->setScaledContents(true);

        horizontalLayout_2->addWidget(label_3);

        barra_busqueda = new QLineEdit(centralwidget);
        barra_busqueda->setObjectName("barra_busqueda");
        QPalette palette2;
        QBrush brush5(QColor(0, 85, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        barra_busqueda->setPalette(palette2);

        horizontalLayout_2->addWidget(barra_busqueda);


        verticalLayout->addLayout(horizontalLayout_2);

        lista_apps = new QListView(centralwidget);
        lista_apps->setObjectName("lista_apps");
        lista_apps->setMinimumSize(QSize(500, 0));
        lista_apps->setMaximumSize(QSize(1000, 16777215));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        lista_apps->setPalette(palette3);

        verticalLayout->addWidget(lista_apps);


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(50, 50));
        label_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/imagenes trabajo/usuario.png")));
        label_2->setScaledContents(true);

        horizontalLayout->addWidget(label_2);

        usuario_nombre = new QLabel(centralwidget);
        usuario_nombre->setObjectName("usuario_nombre");
        QFont font1;
        font1.setPointSize(14);
        usuario_nombre->setFont(font1);
        usuario_nombre->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(usuario_nombre);

        cerrar_sesion = new QPushButton(centralwidget);
        cerrar_sesion->setObjectName("cerrar_sesion");
        cerrar_sesion->setMinimumSize(QSize(0, 35));
        cerrar_sesion->setMaximumSize(QSize(90, 35));

        horizontalLayout->addWidget(cerrar_sesion);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 120, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(30, 120, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1078, 22));
        menuGestor_de_apps = new QMenu(menubar);
        menuGestor_de_apps->setObjectName("menuGestor_de_apps");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGestor_de_apps->menuAction());
        menuGestor_de_apps->addSeparator();
        menuGestor_de_apps->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        favorito_app->setText(QString());
        descargar_app->setText(QString());
        no_descargados_2->setText(QString());
        label_filtro->setText(QString());
        favoritos->setText(QString());
        descargados->setText(QString());
        no_descargados->setText(QString());
        label_3->setText(QString());
        label_2->setText(QString());
        usuario_nombre->setText(QCoreApplication::translate("MainWindow", "usuario", nullptr));
        cerrar_sesion->setText(QCoreApplication::translate("MainWindow", "cerrar sesi\303\263n", nullptr));
        menuGestor_de_apps->setTitle(QCoreApplication::translate("MainWindow", "Gestor de apps", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
