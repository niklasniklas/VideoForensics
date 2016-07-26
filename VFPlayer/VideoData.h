#pragma once
#include "opencv2\opencv.hpp"

namespace sim
{
	class VideoData
	{
	public:
		VideoData();
		~VideoData();

		bool loadVideo(std::string name);
		void nextFrame();
		void prevFrame();
		void jumpFrames(int amount);

		void saveCurrentFrame(std::string str);
		int  getVideolength();
		int  getCurrentFrameNumber();
		void setCurrentFrameNumber(int no);

		std::string getCurrentTime();
		cv::Mat		getCurrentFrame();

	private:
		cv::VideoCapture	video;
		std::string			filepath;
		cv::Mat				currentFrame;


	};

}