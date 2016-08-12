#include "vfmainwindow.h"
#include "opencv2\opencv.hpp"
#include "VideoController.h"
#include <QFileDialog>
#include <QStringList>

namespace gui {
	VFMainWindow::VFMainWindow(QWidget *parent)
		: QMainWindow(parent)
	{
		setupUi(this);
//		horizontalSlider_timeline->setRange(0, 200);
		wg = NULL;

	}

	VFMainWindow::~VFMainWindow()
	{
		// HÄR: anropa detta i "OnExit för VMAinWIndow"
//		wg->close();
		//delete wg;
	}

	void VFMainWindow::initWindow(VideoController *pCtrl)
	{
		pController = pCtrl;
//		connect(horizontalSlider_timeline, SIGNAL(valueChanged(int)), label_exportPath, SLOT(setNum(int)));
		connect(horizontalSlider_timeline, SIGNAL(valueChanged(int)), pController, SLOT(setVideoFrame(int)));
		connect(this, SIGNAL(requestUpdate()), pController, SLOT(requestedUpdate()));
//		connect(this, SIGNAL(playPausebutton()), pController, SLOT(togglePlayPause()));
//		initSlider();
	}

	void VFMainWindow::fromModel(int NN)
	{
		QString tmp = QString::number(NN);
		label_exportPath->setText(tmp);
	}

	void VFMainWindow::setCurrentTime(std::string str)
	{
		label_currenttime->setText(QString::fromStdString(str));
	}

	void VFMainWindow::initSlider()
	{
		int sliderlength = pController->getVideoLength();
		horizontalSlider_timeline->setRange(1, sliderlength);

		int b, a = 5000;
		b = a / 3600;

	}


	void VFMainWindow::updateView(cv::Mat img)
	{
		widget_video->showImage(img);
		if (wg!=NULL)
			wg->showImage(img);
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


	void VFMainWindow::on_pushButton_nextFrame_clicked()
	{
		pController->nextFrame();
	}

	void VFMainWindow::on_pushButton_prevFrame_clicked()
	{
		pController->prevFrame();
	}

	void VFMainWindow::on_pushButton_play_clicked()
	{
		pController->togglePlayPause();
		//		emit playPausebutton();

	}


	void VFMainWindow::on_pushButton_exportStills_clicked()
	{
		pController->exportStills("C:\\Temp\\", 10, 40); //HÄR 12/7
	}


	void VFMainWindow::on_pushButton_exportStillImage_clicked()
	{
		pController->exportStill();
		wg = new CVImageWidget();
		wg->resize(200, 300);
		wg->show();
		wg->resize(200, 300);

	}


	void VFMainWindow::on_pushButton_loadVideo_clicked()
	{
		QStringList fileNames;
		fileNames.empty();

		QFileDialog dlg(this);
		dlg.setViewMode(QFileDialog::Detail);
		fileNames = QFileDialog::getOpenFileNames(this, tr("Select Left Image File"), "E:\\6.Testdata", tr("FFMpeg (*.*)"));

		if (fileNames.isEmpty())
			return;

		QString str;
		str = fileNames.first();

//		bool ok = pController->loadVideo("C:\\2.Testdata\\Video\\frex\\2013-04-06 192000.avi");
		bool ok = pController->loadVideo("E:\\6.Testdata\\SL\\FHP-P112.avi");
//		bool ok = pController->loadVideo(str.toStdString());

		if (ok)
			initSlider();
	}


	void  VFMainWindow::on_horizontalSlider_timeline_sliderReleased()
	{
		emit requestUpdate();
	}
} // namespace gui


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
