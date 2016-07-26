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

	signals: 
//		void playPausebutton();
		void requestUpdate();

	private slots:
		void on_pushButton_nextFrame_clicked();
		void on_pushButton_prevFrame_clicked();
		void on_pushButton_play_clicked();
		void on_pushButton_exportStills_clicked();
		void on_pushButton_exportStillImage_clicked();
		void on_pushButton_loadVideo_clicked();
		void on_horizontalSlider_timeline_sliderReleased();
		//my slots
		void updateView(cv::Mat img);
		void updateSlider(int frameNo);
		void updateButtons(bool playing);
		void fromModel(int NN);
		void setCurrentTime(std::string);

	private:
		//	Ui::VFMainWindowClass ui;
		VideoController *pController;
		void initSlider();

		CVImageWidget *wg;
	};
}
#endif // VFMAINWINDOW_H
