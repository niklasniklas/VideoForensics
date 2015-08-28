#ifndef VFMAINWINDOW_H
#define VFMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_vfmainwindow.h"

namespace gui {
	class VFMainWindow : public QMainWindow, private Ui::VFMainWindowClass
	{
		Q_OBJECT

	public:
		VFMainWindow(QWidget *parent = 0);
		~VFMainWindow();

	private slots:
		void on_pushButton_clicked();
		void on_pushButton_play_clicked();

	private:
		//	Ui::VFMainWindowClass ui;
	};
}
#endif // VFMAINWINDOW_H
