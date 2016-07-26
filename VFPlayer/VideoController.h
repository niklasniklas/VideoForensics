#pragma once

#include <QObject>
#include "opencv2\opencv.hpp"
#include "gui\vfmainwindow.h"
#include "VideoData.h"
#include <QBasicTimer>

class VideoController : public QObject
{
	Q_OBJECT

public:
	VideoController();
	~VideoController();

	gui::VFMainWindow mainWnd;

	void togglePlayPause();
	void nextFrame();
	void prevFrame();
	void exportStill();
	void exportStills(std::string, int startFrame, int endFrame){}; //HÄR 12/7
	int getVideoLength();
	bool loadVideo(std::string filename);

private slots:
//	void togglePlayPause();
	void setVideoFrame(int no);
	void requestedUpdate();

signals:
	void updateView(cv::Mat img);
	void updateSlider(int no);
	void updateButtons(bool playing);
	void sendToGUI(int);					//HÄR1
	void updateCurrentTime(std::string);

protected:
	void timerEvent(QTimerEvent *event);
	void updateGUI();

private:
	sim::VideoData	data;
	bool			stillPlay;
	QBasicTimer		timer;


	int NN;
	
};

