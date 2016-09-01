#include "VideoController.h"


VideoController::VideoController()
{
//	data.loadVideo();
	mainWnd.initWindow(this);
	mainWnd.show();

	connect(this, SIGNAL(updateView(cv::Mat)), &mainWnd, SLOT(updateView(cv::Mat)));
	connect(this, SIGNAL(updateSlider(int)), &mainWnd, SLOT(updateSlider(int)));
	connect(this, SIGNAL(updateButtons(bool)), &mainWnd, SLOT(updateButtons(bool)));

	connect(this, SIGNAL(sendToGUI(int)), &mainWnd, SLOT(fromModel(int)));//HÄR1
	connect(this, SIGNAL(updateCurrentTime(std::string)), &mainWnd, SLOT(setCurrentTime(std::string)));

	stillPlay = false;
	NN = 0; //HÄR

}


VideoController::~VideoController()
{
}
void VideoController::updateGUI()
{
	emit updateView(data.getCurrentFrame());
	emit updateSlider(data.getCurrentFrameNumber());
	emit updateCurrentTime(data.getCurrentTime());
	emit updateButtons(stillPlay);
}

void VideoController::nextFrame()
{
	data.nextFrame();
	updateGUI();
}

void VideoController::prevFrame()
{
	data.prevFrame();
	updateGUI();
}

void VideoController::timerEvent(QTimerEvent *event)
{
	if(stillPlay)
	{
		data.nextFrame();
	}
	updateGUI();
}


void VideoController::togglePlayPause()
{
//	int delay = int(1000.0 / data.getFrameRate());
	stillPlay = !stillPlay;
	if (stillPlay) {
//		timer.start(delay, this);
		timer.start(0, this);
	}
	else
		timer.stop();

	emit updateButtons(stillPlay);
}

void VideoController::exportStill()
{
	cv::imwrite("C:\\Temp\\img01.tif", data.getCurrentFrame());//HÄR
	//data.saveCurrent("C:\\Temp\\img01.tif");

}

int VideoController::getVideoLength()
{
	return data.getVideolength();
}

bool VideoController::loadVideo(std::string filename)
{
	bool result = data.loadVideo(filename);
	updateGUI();

	return result;
}

void VideoController::setVideoFrame(int no)
{
	emit sendToGUI(no);//HÄR
	data.setCurrentFrameNumber(no);
	updateGUI();
}

void VideoController::requestedUpdate()
{
	updateGUI();
}

// HÄR
// Förvirrandde med Updateview o UpdateviewS. 
// Döpa om updateViewS till updateGUI() ?
