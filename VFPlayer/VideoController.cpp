#include "VideoController.h"


VideoController::VideoController()
{
//	data.loadVideo();
	mainWnd.initWindow(this);
	mainWnd.show();

	connect(this, SIGNAL(updateView(cv::Mat)), &mainWnd, SLOT(updateView(cv::Mat)));
	connect(this, SIGNAL(updateSlider(int)), &mainWnd, SLOT(updateSlider(int)));
	connect(this, SIGNAL(updateButtons(bool)), &mainWnd, SLOT(updateButtons(bool)));

	connect(this, SIGNAL(sendToGUI(int)), &mainWnd, SLOT(fromModel(int)));//H�R1
	connect(this, SIGNAL(updateCurrentTime(std::string)), &mainWnd, SLOT(setCurrentTime(std::string)));

	stillPlay = false;
	NN = 0; //H�R

}


VideoController::~VideoController()
{
}
void VideoController::updateGUI()
{
	emit updateView(stream.getCurrentFrame());
	emit updateSlider(stream.getCurrentFrameNumber());
	emit updateCurrentTime(stream.getCurrentTime());
	emit updateButtons(stillPlay);
}

void VideoController::nextFrame()
{
	stream.nextFrame();
	updateGUI();
}

void VideoController::prevFrame()
{
	stream.prevFrame();
	updateGUI();
}

void VideoController::timerEvent(QTimerEvent *event)
{
	if(stillPlay)
	{
		stream.nextFrame();
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
	cv::imwrite("C:\\Temp\\img01.tif", stream.getCurrentFrame());//H�R
	//data.saveCurrent("C:\\Temp\\img01.tif");

}

int VideoController::getVideoLength()
{
	return stream.getVideolength();
}

bool VideoController::loadVideo(std::string filename)
{
	bool result = stream.loadVideo(filename);
	updateGUI();

	return result;
}

void VideoController::setVideoFrame(int no)
{
	emit sendToGUI(no);//H�R
	stream.setCurrentFrameNumber(no);
	updateGUI();
}

void VideoController::requestedUpdate()
{
	updateGUI();
}

// H�R
// F�rvirrandde med Updateview o UpdateviewS. 
// D�pa om updateViewS till updateGUI() ?
