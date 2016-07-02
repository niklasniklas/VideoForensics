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
		cv::Mat nextFrame();

		void saveCurrent(std::string str);
		int  getVideolength();
		int  getFrameNumber();
		void setFrameNumber(int no);

	private:
		cv::VideoCapture video;
		std::string filepath;

	};

}