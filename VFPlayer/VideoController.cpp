#include "VideoController.h"


VideoController::VideoController()
{
	data.loadVideo();
	mainWnd.initWindow(this);
	mainWnd.show();

	connect(this, SIGNAL(updateView(cv::Mat)), &mainWnd, SLOT(updateView(cv::Mat)));

	stillPlay = false;


}


VideoController::~VideoController()
{
}


void VideoController::nextFrame()
{
	currentFrame = data.nextFrame();
	emit updateView(currentFrame);

}

void VideoController::timerEvent(QTimerEvent *event)
{
	if(stillPlay)
	{
		currentFrame = data.nextFrame();
		emit updateView(currentFrame);
	}
}


void VideoController::togglePlayPause()
{
	stillPlay = !stillPlay;
	if (stillPlay)
		timer.start(0, this);
	else
		timer.stop();
}

void VideoController::exportStill()
{
	cv::imwrite("C:\\Temp\\img01.tif", currentFrame);
	//data.saveCurrent("C:\\Temp\\img01.tif");

}

int VideoController::getVideoLength()
{
	return data.getVideolength();
	//return 100;
}