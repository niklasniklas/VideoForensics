#include "VideoController.h"


VideoController::VideoController()
{
//	data.loadVideo();
	mainWnd.initWindow(this);
	mainWnd.show();

	connect(this, SIGNAL(updateView(cv::Mat)), &mainWnd, SLOT(updateView(cv::Mat)));
	connect(this, SIGNAL(updateSlider(int)), &mainWnd, SLOT(updateSlider(int)));
	connect(this, SIGNAL(updateButtons(bool)), &mainWnd, SLOT(updateButtons(bool)));

	connect(this, SIGNAL(sendToGUI(int)), &mainWnd, SLOT(fromModel(int)));//HÄR

	stillPlay = false;
	NN = 0; //HÄR

}


VideoController::~VideoController()
{
}
void VideoController::updateViews()
{
	emit updateView(data.getCurrentFrame());
	emit updateSlider(data.getFrameNumber());
	emit updateButtons(stillPlay);
}

void VideoController::nextFrame()
{
	data.nextFrame();
	updateViews();
}

void VideoController::timerEvent(QTimerEvent *event)
{
	if(stillPlay)
	{
		data.nextFrame();
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
	updateViews();

	return result;
}

void VideoController::setVideoFrame(int no)
{
	emit sendToGUI(no);//HÄR
	data.setFrameNumber(no);
	updateViews();
}

void VideoController::requestedUpdate()
{
	int i = 0;
}
