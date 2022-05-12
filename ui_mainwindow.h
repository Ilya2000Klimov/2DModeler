/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "canvas.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInfo;
    QAction *actionLogin;
    QAction *actionAdd_Line;
    QAction *actionAdd_Polyline;
    QAction *actionAdd_Ellipse;
    QAction *actionAdd_Circle;
    QAction *actionAdd_Rectangle;
    QAction *actionAdd_Square;
    QAction *actionAdd_Polygon;
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionExit;
    QWidget *centralwidget;
    Canvas *canvas;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QMenu *menuAdd_Shapes;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(891, 661);
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionAdd_Line = new QAction(MainWindow);
        actionAdd_Line->setObjectName(QString::fromUtf8("actionAdd_Line"));
        actionAdd_Polyline = new QAction(MainWindow);
        actionAdd_Polyline->setObjectName(QString::fromUtf8("actionAdd_Polyline"));
        actionAdd_Ellipse = new QAction(MainWindow);
        actionAdd_Ellipse->setObjectName(QString::fromUtf8("actionAdd_Ellipse"));
        actionAdd_Circle = new QAction(MainWindow);
        actionAdd_Circle->setObjectName(QString::fromUtf8("actionAdd_Circle"));
        actionAdd_Rectangle = new QAction(MainWindow);
        actionAdd_Rectangle->setObjectName(QString::fromUtf8("actionAdd_Rectangle"));
        actionAdd_Square = new QAction(MainWindow);
        actionAdd_Square->setObjectName(QString::fromUtf8("actionAdd_Square"));
        actionAdd_Polygon = new QAction(MainWindow);
        actionAdd_Polygon->setObjectName(QString::fromUtf8("actionAdd_Polygon"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        canvas = new Canvas(centralwidget);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        canvas->setGeometry(QRect(29, -1, 861, 641));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 891, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuAdd_Shapes = new QMenu(menubar);
        menuAdd_Shapes->setObjectName(QString::fromUtf8("menuAdd_Shapes"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menubar->addAction(menuAdd_Shapes->menuAction());
        menuFile->addAction(actionLogin);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionExit);
        menuAbout->addAction(actionInfo);
        menuAdd_Shapes->addAction(actionAdd_Line);
        menuAdd_Shapes->addAction(actionAdd_Polyline);
        menuAdd_Shapes->addAction(actionAdd_Ellipse);
        menuAdd_Shapes->addAction(actionAdd_Circle);
        menuAdd_Shapes->addAction(actionAdd_Rectangle);
        menuAdd_Shapes->addAction(actionAdd_Square);
        menuAdd_Shapes->addAction(actionAdd_Polygon);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionInfo->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        actionAdd_Line->setText(QCoreApplication::translate("MainWindow", "Add Line", nullptr));
        actionAdd_Polyline->setText(QCoreApplication::translate("MainWindow", "Add Polyline", nullptr));
        actionAdd_Ellipse->setText(QCoreApplication::translate("MainWindow", "Add Ellipse", nullptr));
        actionAdd_Circle->setText(QCoreApplication::translate("MainWindow", "Add Circle", nullptr));
        actionAdd_Rectangle->setText(QCoreApplication::translate("MainWindow", "Add Rectangle", nullptr));
        actionAdd_Square->setText(QCoreApplication::translate("MainWindow", "Add Square", nullptr));
        actionAdd_Polygon->setText(QCoreApplication::translate("MainWindow", "Add Polygon", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuAdd_Shapes->setTitle(QCoreApplication::translate("MainWindow", "Add Shapes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
