#pragma once
#include "opencv2\opencv.hpp"

namespace sim
{
	class VideoData
	{
	public:
		VideoData();
		~VideoData();

		void loadVideo();
		cv::Mat nextFrame();

	private:
		cv::VideoCapture video;
		std::string filename;

	};

}