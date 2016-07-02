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
	bool loadVideo(std::string filename);

private slots:
//	void togglePlayPause();
	void setVideoFrame(int no);

signals:
	void updateView(cv::Mat img);
	void updateSlider(int no);
	void updateButtons(bool playing);

protected:
	void timerEvent(QTimerEvent *event);
	void updateViews();

private:
	sim::VideoData	data;
	bool			stillPlay;
	QBasicTimer		timer;
	cv::Mat			currentFrame;

	
};

