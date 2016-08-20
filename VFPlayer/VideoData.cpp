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

	void VideoData::prevFrame()
	{
		int no = int(video.get(CV_CAP_PROP_POS_FRAMES))-1;
		// Error check beginning of video
		if (no < 1) no = 1;
		video.set(CV_CAP_PROP_POS_FRAMES, no);
		video.retrieve(currentFrame);
	}

	void VideoData::jumpFrames(int amount)
	{
		int no = getCurrentFrameNumber();
		no += amount;
		setCurrentFrameNumber(no);

	}


	void VideoData::saveCurrentFrame(std::string path, std::string filename)
	{
		std::string filepath;

		if (filename == "")
			filename = makeStillImageFilename();

		filepath = path + filename;

		//cv::imwrite(str,)
		cv::imwrite(filepath, currentFrame);//HÄR
		cv::imwrite("C:\\Temp\\img02.tif", currentFrame);//HÄR

	}

	std::string	VideoData::makeStillImageFilename()
	{
		std::string name;

		filepath.		//skära ut video-filnamnet från hela strängen...

		return name;
	}


	int VideoData::getVideolength()
	{
		double d = video.get(CV_CAP_PROP_FRAME_COUNT);
		return int(d);
	}

	int VideoData::getCurrentFrameNumber()
	{
		double d = video.get(CV_CAP_PROP_POS_FRAMES);
		return int(d);
	}

	void VideoData::setCurrentFrameNumber(int no)
	{
		int min = 1;
		int max = int(video.get(CV_CAP_PROP_FRAME_COUNT));

		if (no < min) no = min;
		if (no > max) no = max;

		video.set(CV_CAP_PROP_POS_FRAMES, no);
		video.retrieve(currentFrame);
	}

	std::string VideoData::getCurrentTime()
	{

		//int x = int(video.get(cv::CAP_PROP_FPS));
		int t = int(video.get(CV_CAP_PROP_POS_MSEC));
		int d, h, m, s;
		char dd[2], hh[2], mm[2], ss[2];
		
		h = int(t / 3600000);	t = t % 3600000;
		m = int(t / 60000);		t = t % 60000;
		s = int(t / 1000);

		(h < 10) ? sprintf(hh, "0%d", h) : sprintf(hh, "%d", h);
		(m < 10) ? sprintf(mm, "0%d", m) : sprintf(mm, "%d", m);
		(s < 10) ? sprintf(ss, "0%d", s) : sprintf(ss, "%d", s);

		char tt[9];
		sprintf(tt,"%s:%s:%s",hh,mm,ss);


		std::string time(tt);
		return time;


	}
	/*
cv::CAP_PROP_POS_MSEC Current position of the video file in milliseconds.
cv::CAP_PROP_POS_FRAMES 0-based index of the frame to be decoded/captured next.
cv::CAP_PROP_POS_AVI_RATIO Relative position of the video file: 0=start of the film, 1=end of the film.
cv::CAP_PROP_FRAME_WIDTH Width of the frames in the video stream.
cv::CAP_PROP_FRAME_HEIGHT Height of the frames in the video stream.
cv::CAP_PROP_FPS Frame rate.

	*/

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