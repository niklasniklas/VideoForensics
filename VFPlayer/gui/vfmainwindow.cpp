#include "vfmainwindow.h"
#include "opencv2\opencv.hpp"
#include "VideoController.h"

namespace gui {
	VFMainWindow::VFMainWindow(QWidget *parent)
		: QMainWindow(parent)
	{
		setupUi(this);
		horizontalSlider_timeline->setRange(0, 200);


	}

	VFMainWindow::~VFMainWindow()
	{

	}

	void VFMainWindow::initWindow(VideoController *pCtrl)
	{
		pController = pCtrl;
//		connect(this, SIGNAL(playPausebutton()), pController, SLOT(togglePlayPause()));
		initSlider();
	}

	void VFMainWindow::initSlider()
	{
		int sliderlength = pController->getVideoLength();
		horizontalSlider_timeline->setRange(0, sliderlength);
		pushButton_play->setText("Xxxx");
	}

	void VFMainWindow::updateView(cv::Mat img)
	{
		widget_video->showImage(img);
	}

	void VFMainWindow::on_pushButton_clicked()
	{
		pController->nextFrame();
	}

	void VFMainWindow::on_pushButton_play_clicked()
	{
		pController->togglePlayPause();
		pushButton_play->setText("Pause");

		//		emit playPausebutton();

	}

	void VFMainWindow::on_pushButton_exportStillImage_clicked()
	{
		pController->exportStill();
		CVImageWidget *wg = new CVImageWidget();
		wg->resize(200, 300);
		wg->show();
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
