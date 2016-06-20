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
	void exportStill();
	int getVideoLength();

private slots:
//	void togglePlayPause();

signals:
	void updateView(cv::Mat img);

protected:
	void timerEvent(QTimerEvent *event);

private:
	sim::VideoData	data;
	bool			stillPlay;
	QBasicTimer		timer;
	cv::Mat			currentFrame;

	
};

