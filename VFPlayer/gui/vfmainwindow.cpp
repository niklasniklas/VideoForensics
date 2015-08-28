#include "vfmainwindow.h"
#include "opencv2\opencv.hpp"

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

	void VFMainWindow::on_pushButton_clicked()
	{
		cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\fruits.jpg");
		imshow("Lena", img);
	}

	void VFMainWindow::on_pushButton_play_clicked()
	{
		cv::Mat img = cv::imread("D:\\6.Testdata\\Bilder\\fruits.jpg");
		imshow("Lena2", img);
		// 
	}


} // namespace