#pragma once
#include "opencv2\opencv.hpp"

namespace sim
{
	class VideoModel
	{
	public:
		VideoModel();
		~VideoModel();

		void loadVideo();

	private:
		cv::VideoCapture video;

	};

}