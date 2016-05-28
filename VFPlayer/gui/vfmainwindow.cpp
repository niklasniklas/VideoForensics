#include "vfmainwindow.h"
#include "opencv2\opencv.hpp"
#include "VideoController.h"

namespace gui {
	VFMainWindow::VFMainWindow(QWidget *parent)
		: QMainWindow(parent)
	{
		setupUi(this);

		//cv::Mat img = cv::imread("D:\\6.Testdata\\Bilder\\fruits.jpg");
		//imshow("Lena2", img);

	}

	VFMainWindow::~VFMainWindow()
	{

	}

	void VFMainWindow::initWindow(VideoController *pCtrl)
	{
		pController = pCtrl;
	}

	void VFMainWindow::updateView(cv::Mat img)
	{
//		cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\boldt.jpg");
		widget_video->showImage(img);
	}

	void VFMainWindow::on_pushButton_clicked()
	{
		for (int i = 0; i < 100; i++)
		{
			pController->playPressed();
		}
//		cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\fruits.jpg");
//		widget_video->showImage(img);
		//imshow("Lena", img);
	}

	void VFMainWindow::on_pushButton_play_clicked()
	{
		pController->playPressed();

		//VideoController ctrl;

	}


} // namespace