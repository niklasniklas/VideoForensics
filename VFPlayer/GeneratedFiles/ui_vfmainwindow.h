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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VFMainWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_play;
    QLabel *label_exportPath;
    QPushButton *pushButton_loadVideo;
    QLabel *label_framecount;
    QPushButton *pushButton;
    QSlider *horizontalSlider_timeline;
    QCheckBox *checkBox_resizeVideo;
    QPushButton *pushButton_showVideo;
    QWidget *widget_video;
    QPushButton *pushButton_exportStillImage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VFMainWindowClass)
    {
        if (VFMainWindowClass->objectName().isEmpty())
            VFMainWindowClass->setObjectName(QStringLiteral("VFMainWindowClass"));
        VFMainWindowClass->resize(996, 773);
        centralWidget = new QWidget(VFMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_play = new QPushButton(centralWidget);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));
        pushButton_play->setGeometry(QRect(120, 480, 75, 31));
        label_exportPath = new QLabel(centralWidget);
        label_exportPath->setObjectName(QStringLiteral("label_exportPath"));
        label_exportPath->setGeometry(QRect(730, 310, 101, 16));
        pushButton_loadVideo = new QPushButton(centralWidget);
        pushButton_loadVideo->setObjectName(QStringLiteral("pushButton_loadVideo"));
        pushButton_loadVideo->setGeometry(QRect(710, 10, 111, 23));
        label_framecount = new QLabel(centralWidget);
        label_framecount->setObjectName(QStringLiteral("label_framecount"));
        label_framecount->setGeometry(QRect(720, 520, 181, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 450, 121, 51));
        horizontalSlider_timeline = new QSlider(centralWidget);
        horizontalSlider_timeline->setObjectName(QStringLiteral("horizontalSlider_timeline"));
        horizontalSlider_timeline->setGeometry(QRect(70, 530, 581, 19));
        horizontalSlider_timeline->setMaximum(200);
        horizontalSlider_timeline->setOrientation(Qt::Horizontal);
        checkBox_resizeVideo = new QCheckBox(centralWidget);
        checkBox_resizeVideo->setObjectName(QStringLiteral("checkBox_resizeVideo"));
        checkBox_resizeVideo->setGeometry(QRect(720, 70, 171, 31));
        pushButton_showVideo = new QPushButton(centralWidget);
        pushButton_showVideo->setObjectName(QStringLiteral("pushButton_showVideo"));
        pushButton_showVideo->setGeometry(QRect(710, 200, 151, 31));
        widget_video = new QWidget(centralWidget);
        widget_video->setObjectName(QStringLiteral("widget_video"));
        widget_video->setGeometry(QRect(10, 0, 681, 441));
        pushButton_exportStillImage = new QPushButton(centralWidget);
        pushButton_exportStillImage->setObjectName(QStringLiteral("pushButton_exportStillImage"));
        pushButton_exportStillImage->setGeometry(QRect(720, 260, 121, 41));
        VFMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VFMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 996, 21));
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
        pushButton_play->setText(QApplication::translate("VFMainWindowClass", "Play", 0));
        label_exportPath->setText(QApplication::translate("VFMainWindowClass", "export path", 0));
        pushButton_loadVideo->setText(QApplication::translate("VFMainWindowClass", "Load video...", 0));
        label_framecount->setText(QApplication::translate("VFMainWindowClass", "sign/slot w slider", 0));
        pushButton->setText(QApplication::translate("VFMainWindowClass", "PushButton", 0));
        checkBox_resizeVideo->setText(QApplication::translate("VFMainWindowClass", "Fit to widget", 0));
        pushButton_showVideo->setText(QApplication::translate("VFMainWindowClass", "show large Video ", 0));
        pushButton_exportStillImage->setText(QApplication::translate("VFMainWindowClass", "Export Image", 0));
    } // retranslateUi

};

namespace Ui {
    class VFMainWindowClass: public Ui_VFMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VFMAINWINDOW_H
