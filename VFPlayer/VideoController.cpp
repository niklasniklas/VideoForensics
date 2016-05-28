#include "VideoController.h"


VideoController::VideoController()
{
	data.loadVideo();
	mainWnd.initWindow(this);
	mainWnd.show();

	connect(this, SIGNAL(updateView(cv::Mat)), &mainWnd, SLOT(updateView(cv::Mat)));

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


}

//VideoController::VideoController(int i){
//	pMainWnd = new gui::VFMainWindow(this, NULL);
//	pMainWnd->show();
//
//}



VideoController::~VideoController()
{
}


void VideoController::playPressed()
{
	cv::Mat frame = data.nextFrame();
	emit updateView(frame);

}