#include "vfmainwindow.h"
#include "opencv2\opencv.hpp"
#include "VideoController.h"

namespace gui {
	VFMainWindow::VFMainWindow(QWidget *parent)
		: QMainWindow(parent)
	{
		setupUi(this);
//		horizontalSlider_timeline->setRange(0, 200);


	}

	VFMainWindow::~VFMainWindow()
	{

	}

	void VFMainWindow::initWindow(VideoController *pCtrl)
	{
		pController = pCtrl;
//		connect(horizontalSlider_timeline, SIGNAL(valueChanged(int)), label_exportPath, SLOT(setNum(int)));
		connect(horizontalSlider_timeline, SIGNAL(valueChanged(int)), pController, SLOT(setVideoFrame(int)));
		connect(horizontalSlider_timeline, SIGNAL(requestUpdate()), pController, SLOT(requestedUpdate()));
//		connect(this, SIGNAL(playPausebutton()), pController, SLOT(togglePlayPause()));
//		initSlider();
	}

	void VFMainWindow::fromModel(int NN)
	{
		QString tmp = QString::number(NN);
		label_exportPath->setText(tmp);
	}

	void VFMainWindow::initSlider()
	{
		int sliderlength = pController->getVideoLength();
		horizontalSlider_timeline->setRange(0, sliderlength);
	}


	void VFMainWindow::updateView(cv::Mat img)
	{
		widget_video->showImage(img);
	}


	void VFMainWindow::updateSlider(int frameNo)
	{
		horizontalSlider_timeline->setValue(frameNo);
	}


	void VFMainWindow::updateButtons(bool playing)
	{
		if (playing)
			pushButton_play->setText("Pause");
		else
			pushButton_play->setText("Play");
	}


	void VFMainWindow::on_pushButton_clicked()
	{
		pController->nextFrame();
	}


	void VFMainWindow::on_pushButton_play_clicked()
	{
		pController->togglePlayPause();
		//		emit playPausebutton();

	}


	void VFMainWindow::on_pushButton_exportStillImage_clicked()
	{
		pController->exportStill();
		CVImageWidget *wg = new CVImageWidget();
		wg->resize(200, 300);
		wg->show();
	}


	void VFMainWindow::on_pushButton_loadVideo_clicked()
	{
		bool result = pController->loadVideo("C:\\2.Testdata\\Video\\frex\\2013-04-06 192000.avi");

		if (result)
			initSlider();

	}

	void  VFMainWindow::on_horizontalSlider_timeline_sliderReleased()
	{
		int i = 0;
		emit requestUpdate();
	}
} // namespace


/**SLASK**/

//cv::Mat img = cv::imread("D:\\6.Testdata\\Bilder\\fruits.jpg");
//imshow("Lena2", img);


/*
std::string filename = "C:\\2.Testdata\\Video\\frex\\2013-04-06 192000.avi";
//	cv::VideoCapture cap(filename); // open videofile
cv::VideoCapture cap; // open videofile
cap.open(filename);

if (!cap.isOpened()) // check if we succeeded
return;

for (;;)
{
cv::Mat frame;
cap >> frame;
imshow("movie-play-btn", frame);
if (cv::waitKey(30) >= 0)
break;
}
*/
