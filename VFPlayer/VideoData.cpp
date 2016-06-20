#include "VideoData.h"

namespace sim
{
	VideoData::VideoData()
	{
		filename = "C:\\2.Testdata\\Video\\frex\\2013-04-06 192000.avi";
	}


	VideoData::~VideoData()
	{
	}

	void VideoData::loadVideo()
	{
		video.open(filename);
		//cv::VideoCapture cap(filename); // open videofile
		
	}

	cv::Mat VideoData::nextFrame()
	{
		cv::Mat frame;
		video >> frame;
		return frame;
	}

	void VideoData::saveCurrent(std::string str)
	{
		//cv::imwrite(str,)
	}

	int VideoData::getVideolength()
	{
		double d = video.get(CV_CAP_PROP_FRAME_COUNT);
		return int(d);
	}


	//capture.get(CV_CAP_PROP_POS_FRAMES); // retrieves the current frame number
	//and also :

	//capture.get(CV_CAP_PROP_FRAME_COUNT); // retuns the number of total frames 




	//if (!cap.isOpened()) // check if we succeeded
	//	return;

	//for (;;)
	//{
	//	cv::Mat frame;
	//	cap >> frame;
	//	imshow("movie", frame);
	//	if (cv::waitKey(30) >= 0)
	//		break;
	//}

} // sim