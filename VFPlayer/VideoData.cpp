#include "VideoData.h"

namespace sim
{
	VideoData::VideoData()
	{
//		filename = "C:\\2.Testdata\\Video\\frex\\2013-04-06 192000.avi";
	}


	VideoData::~VideoData()
	{
	}

	bool VideoData::loadVideo(std::string name)
	{
		filepath = name;
		bool result = video.open(name);
		nextFrame();
		return result;
		//cv::VideoCapture cap(filename); // open videofile
		
	}

	void VideoData::nextFrame()
	{
		video >> currentFrame;
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

	int VideoData::getFrameNumber()
	{
		double d = video.get(CV_CAP_PROP_POS_FRAMES);
		return int(d);
	}

	void VideoData::setFrameNumber(int no)
	{
		video.set(CV_CAP_PROP_POS_FRAMES, no);
		video.retrieve(currentFrame);
	}


	cv::Mat VideoData::getCurrentFrame()
	{
		return currentFrame;
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