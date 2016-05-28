#ifndef VFMAINWINDOW_H
#define VFMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_vfmainwindow.h"
//#include "VideoController.h"
class VideoController;

namespace gui {
	class VFMainWindow : public QMainWindow, private Ui::VFMainWindowClass
	{
		Q_OBJECT

	public:
		VFMainWindow(QWidget *parent = 0);
		~VFMainWindow();

		void initWindow(VideoController* pCtrl);

	private slots:
		void on_pushButton_clicked();
		void on_pushButton_play_clicked();
		void updateView(cv::Mat img);

	private:
		//	Ui::VFMainWindowClass ui;
		VideoController *pController;
	};
}
#endif // VFMAINWINDOW_H
