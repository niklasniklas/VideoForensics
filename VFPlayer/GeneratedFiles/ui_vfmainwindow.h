/********************************************************************************
** Form generated from reading UI file 'vfmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VFMAINWINDOW_H
#define UI_VFMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VFMainWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VFMainWindowClass)
    {
        if (VFMainWindowClass->objectName().isEmpty())
            VFMainWindowClass->setObjectName(QStringLiteral("VFMainWindowClass"));
        VFMainWindowClass->resize(600, 400);
        menuBar = new QMenuBar(VFMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        VFMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VFMainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VFMainWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(VFMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        VFMainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(VFMainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VFMainWindowClass->setStatusBar(statusBar);

        retranslateUi(VFMainWindowClass);

        QMetaObject::connectSlotsByName(VFMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *VFMainWindowClass)
    {
        VFMainWindowClass->setWindowTitle(QApplication::translate("VFMainWindowClass", "VFMainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class VFMainWindowClass: public Ui_VFMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VFMAINWINDOW_H
