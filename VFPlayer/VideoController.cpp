#include "VideoController.h"


VideoController::VideoController()
{
//	data.loadVideo();
	mainWnd.initWindow(this);
	mainWnd.show();

	connect(this, SIGNAL(updateView(cv::Mat)), &mainWnd, SLOT(updateView(cv::Mat)));
	connect(this, SIGNAL(updateSlider(int)), &mainWnd, SLOT(updateSlider(int)));
	connect(this, SIGNAL(updateButtons(bool)), &mainWnd, SLOT(updateButtons(bool)));

	stillPlay = false;

}


VideoController::~VideoController()
{
}
void VideoController::updateViews()
{
	emit updateView(currentFrame);
	emit updateSlider(data.getFrameNumber());

}

void VideoController::nextFrame()
{
	currentFrame = data.nextFrame();
	updateViews();
}

void VideoController::timerEvent(QTimerEvent *event)
{
	if(stillPlay)
	{
		currentFrame = data.nextFrame();
	}
	updateViews();
}


void VideoController::togglePlayPause()
{
	stillPlay = !stillPlay;
	if (stillPlay)
		timer.start(0, this);
	else
		timer.stop();

	emit updateButtons(stillPlay);
}

void VideoController::exportStill()
{
	cv::imwrite("C:\\Temp\\img01.tif", currentFrame);
	//data.saveCurrent("C:\\Temp\\img01.tif");

}

int VideoController::getVideoLength()
{
	return data.getVideolength();
}

bool VideoController::loadVideo(std::string filename)
{
	return data.loadVideo(filename);
}

void VideoController::setVideoFrame(int no)
{
	data.setFrameNumber(no);
	updateViews();
}
