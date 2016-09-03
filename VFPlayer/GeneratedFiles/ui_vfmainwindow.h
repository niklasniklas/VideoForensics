/********************************************************************************
** Form generated from reading UI file 'vfmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VFMAINWINDOW_H
#define UI_VFMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "cvimagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_VFMainWindowClass
{
public:
    QWidget *centralWidget;
    QLabel *label_exportPath;
    QPushButton *pushButton_loadVideo;
    QLabel *label_framecount;
    QSlider *horizontalSlider_timeline;
    QCheckBox *checkBox_resizeVideo;
    QPushButton *pushButton_showVideo;
    CVImageWidget *widget_video;
    QPushButton *pushButton_exportStillImage;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_prevFrame;
    QPushButton *pushButton_play;
    QPushButton *pushButton_nextFrame;
    QLineEdit *lineEdit_Start;
    QLineEdit *lineEdit_Stop;
    QPushButton *pushButton_exportStills;
    QLabel *label_currenttime;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VFMainWindowClass)
    {
        if (VFMainWindowClass->objectName().isEmpty())
            VFMainWindowClass->setObjectName(QStringLiteral("VFMainWindowClass"));
        VFMainWindowClass->resize(1111, 858);
        centralWidget = new QWidget(VFMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_exportPath = new QLabel(centralWidget);
        label_exportPath->setObjectName(QStringLiteral("label_exportPath"));
        label_exportPath->setGeometry(QRect(920, 740, 101, 16));
        pushButton_loadVideo = new QPushButton(centralWidget);
        pushButton_loadVideo->setObjectName(QStringLiteral("pushButton_loadVideo"));
        pushButton_loadVideo->setGeometry(QRect(50, 620, 111, 23));
        label_framecount = new QLabel(centralWidget);
        label_framecount->setObjectName(QStringLiteral("label_framecount"));
        label_framecount->setGeometry(QRect(640, 730, 181, 31));
        horizontalSlider_timeline = new QSlider(centralWidget);
        horizontalSlider_timeline->setObjectName(QStringLiteral("horizontalSlider_timeline"));
        horizontalSlider_timeline->setGeometry(QRect(30, 740, 581, 19));
        horizontalSlider_timeline->setMaximum(200);
        horizontalSlider_timeline->setOrientation(Qt::Horizontal);
        checkBox_resizeVideo = new QCheckBox(centralWidget);
        checkBox_resizeVideo->setObjectName(QStringLiteral("checkBox_resizeVideo"));
        checkBox_resizeVideo->setGeometry(QRect(440, 630, 111, 31));
        pushButton_showVideo = new QPushButton(centralWidget);
        pushButton_showVideo->setObjectName(QStringLiteral("pushButton_showVideo"));
        pushButton_showVideo->setGeometry(QRect(620, 630, 151, 31));
        widget_video = new CVImageWidget(centralWidget);
        widget_video->setObjectName(QStringLiteral("widget_video"));
        widget_video->setGeometry(QRect(10, 0, 681, 441));
        pushButton_exportStillImage = new QPushButton(centralWidget);
        pushButton_exportStillImage->setObjectName(QStringLiteral("pushButton_exportStillImage"));
        pushButton_exportStillImage->setGeometry(QRect(910, 690, 121, 41));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 690, 295, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_prevFrame = new QPushButton(layoutWidget);
        pushButton_prevFrame->setObjectName(QStringLiteral("pushButton_prevFrame"));

        horizontalLayout->addWidget(pushButton_prevFrame);

        pushButton_play = new QPushButton(layoutWidget);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));

        horizontalLayout->addWidget(pushButton_play);

        pushButton_nextFrame = new QPushButton(layoutWidget);
        pushButton_nextFrame->setObjectName(QStringLiteral("pushButton_nextFrame"));

        horizontalLayout->addWidget(pushButton_nextFrame);

        lineEdit_Start = new QLineEdit(centralWidget);
        lineEdit_Start->setObjectName(QStringLiteral("lineEdit_Start"));
        lineEdit_Start->setGeometry(QRect(810, 540, 41, 22));
        lineEdit_Stop = new QLineEdit(centralWidget);
        lineEdit_Stop->setObjectName(QStringLiteral("lineEdit_Stop"));
        lineEdit_Stop->setGeometry(QRect(860, 540, 41, 21));
        pushButton_exportStills = new QPushButton(centralWidget);
        pushButton_exportStills->setObjectName(QStringLiteral("pushButton_exportStills"));
        pushButton_exportStills->setGeometry(QRect(920, 540, 93, 28));
        label_currenttime = new QLabel(centralWidget);
        label_currenttime->setObjectName(QStringLiteral("label_currenttime"));
        label_currenttime->setGeometry(QRect(640, 770, 111, 16));
        VFMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VFMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1111, 26));
        VFMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VFMainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VFMainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VFMainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VFMainWindowClass->setStatusBar(statusBar);

        retranslateUi(VFMainWindowClass);
        QObject::connect(horizontalSlider_timeline, SIGNAL(valueChanged(int)), label_framecount, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(VFMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *VFMainWindowClass)
    {
        VFMainWindowClass->setWindowTitle(QApplication::translate("VFMainWindowClass", "VFMainWindow", 0));
        label_exportPath->setText(QApplication::translate("VFMainWindowClass", "export path", 0));
        pushButton_loadVideo->setText(QApplication::translate("VFMainWindowClass", "Load video...", 0));
        label_framecount->setText(QApplication::translate("VFMainWindowClass", "sign/slot w slider", 0));
        checkBox_resizeVideo->setText(QApplication::translate("VFMainWindowClass", "Fit to widget", 0));
        pushButton_showVideo->setText(QApplication::translate("VFMainWindowClass", "show large Video ", 0));
        pushButton_exportStillImage->setText(QApplication::translate("VFMainWindowClass", "Export Image", 0));
        pushButton_prevFrame->setText(QApplication::translate("VFMainWindowClass", "Prev", 0));
        pushButton_play->setText(QApplication::translate("VFMainWindowClass", "Play", 0));
        pushButton_nextFrame->setText(QApplication::translate("VFMainWindowClass", "Next", 0));
        pushButton_exportStills->setText(QApplication::translate("VFMainWindowClass", "Export Stills", 0));
        label_currenttime->setText(QApplication::translate("VFMainWindowClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class VFMainWindowClass: public Ui_VFMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VFMAINWINDOW_H
