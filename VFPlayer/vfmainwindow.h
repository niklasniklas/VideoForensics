#ifndef VFMAINWINDOW_H
#define VFMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_vfmainwindow.h"

class VFMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	VFMainWindow(QWidget *parent = 0);
	~VFMainWindow();

private:
	Ui::VFMainWindowClass ui;
};

#endif // VFMAINWINDOW_H
