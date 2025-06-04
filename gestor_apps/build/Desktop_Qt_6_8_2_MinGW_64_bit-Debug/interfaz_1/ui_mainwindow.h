/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *usuario_nombre;
    QPushButton *cerrar_sesion;
    QLabel *label_3;
    QLineEdit *barra_busqueda;
    QLabel *label_filtro;
    QPushButton *favoritos;
    QPushButton *descargados;
    QPushButton *no_descargados;
    QListView *lista_apps;
    QListWidget *lista_filtro;
    QLabel *label;
    QPushButton *favorito_app;
    QPushButton *descargar_app;
    QPushButton *no_descargados_2;
    QProgressBar *barraProgreso;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1307, 1246);
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
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/imagenes trabajo/usuario.png")));
        label_2->setScaledContents(true);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        usuario_nombre = new QLabel(centralwidget);
        usuario_nombre->setObjectName("usuario_nombre");
        QFont font;
        font.setPointSize(14);
        usuario_nombre->setFont(font);
        usuario_nombre->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(usuario_nombre, 0, 1, 1, 6);

        cerrar_sesion = new QPushButton(centralwidget);
        cerrar_sesion->setObjectName("cerrar_sesion");

        gridLayout->addWidget(cerrar_sesion, 0, 7, 1, 2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/imagenes trabajo/busqueda-de-lupa.png")));
        label_3->setScaledContents(true);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        barra_busqueda = new QLineEdit(centralwidget);
        barra_busqueda->setObjectName("barra_busqueda");
        QPalette palette1;
        QBrush brush5(QColor(0, 85, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        barra_busqueda->setPalette(palette1);

        gridLayout->addWidget(barra_busqueda, 1, 1, 1, 4);

        label_filtro = new QLabel(centralwidget);
        label_filtro->setObjectName("label_filtro");
        label_filtro->setPixmap(QPixmap(QString::fromUtf8(":/imagenes trabajo/filtrar.png")));
        label_filtro->setScaledContents(true);

        gridLayout->addWidget(label_filtro, 1, 5, 1, 1);

        favoritos = new QPushButton(centralwidget);
        favoritos->setObjectName("favoritos");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes trabajo/me-gusta.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        favoritos->setIcon(icon1);
        favoritos->setIconSize(QSize(20, 20));

        gridLayout->addWidget(favoritos, 1, 6, 1, 1);

        descargados = new QPushButton(centralwidget);
        descargados->setObjectName("descargados");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes trabajo/descargas.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        descargados->setIcon(icon2);
        descargados->setIconSize(QSize(20, 20));

        gridLayout->addWidget(descargados, 1, 7, 1, 1);

        no_descargados = new QPushButton(centralwidget);
        no_descargados->setObjectName("no_descargados");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes trabajo/no.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        no_descargados->setIcon(icon3);
        no_descargados->setIconSize(QSize(20, 20));

        gridLayout->addWidget(no_descargados, 1, 8, 1, 1);

        lista_apps = new QListView(centralwidget);
        lista_apps->setObjectName("lista_apps");
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        lista_apps->setPalette(palette2);

        gridLayout->addWidget(lista_apps, 2, 0, 1, 5);

        lista_filtro = new QListWidget(centralwidget);
        lista_filtro->setObjectName("lista_filtro");

        gridLayout->addWidget(lista_filtro, 2, 5, 1, 4);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        label->setPalette(palette3);
        label->setWordWrap(true);

        gridLayout->addWidget(label, 3, 0, 2, 2);

        favorito_app = new QPushButton(centralwidget);
        favorito_app->setObjectName("favorito_app");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagenes trabajo/mano arriba.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        favorito_app->setIcon(icon4);
        favorito_app->setIconSize(QSize(20, 20));

        gridLayout->addWidget(favorito_app, 3, 2, 1, 1);

        descargar_app = new QPushButton(centralwidget);
        descargar_app->setObjectName("descargar_app");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagenes trabajo/instalar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        descargar_app->setIcon(icon5);
        descargar_app->setIconSize(QSize(20, 20));

        gridLayout->addWidget(descargar_app, 3, 3, 1, 1);

        no_descargados_2 = new QPushButton(centralwidget);
        no_descargados_2->setObjectName("no_descargados_2");
        no_descargados_2->setIcon(icon3);
        no_descargados_2->setIconSize(QSize(20, 20));

        gridLayout->addWidget(no_descargados_2, 3, 4, 1, 1);

        barraProgreso = new QProgressBar(centralwidget);
        barraProgreso->setObjectName("barraProgreso");
        QFont font1;
        font1.setPointSize(16);
        barraProgreso->setFont(font1);
        barraProgreso->setValue(0);
        barraProgreso->setTextVisible(false);

        gridLayout->addWidget(barraProgreso, 4, 2, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1307, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QString());
        usuario_nombre->setText(QCoreApplication::translate("MainWindow", "usuario", nullptr));
        cerrar_sesion->setText(QCoreApplication::translate("MainWindow", "cerrar sesi\303\263n", nullptr));
        label_3->setText(QString());
        label_filtro->setText(QString());
        favoritos->setText(QString());
        descargados->setText(QString());
        no_descargados->setText(QString());
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
