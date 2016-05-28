#pragma once

#include <QObject>
#include "opencv2\opencv.hpp"
#include "gui\vfmainwindow.h"
#include "VideoData.h"

class VideoController : public QObject
{
	Q_OBJECT

public:
	VideoController();
	~VideoController();

	void playPressed();

	gui::VFMainWindow mainWnd;
signals:
	void updateView(cv::Mat img);

private:
	sim::VideoData data;
};

