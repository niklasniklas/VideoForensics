#pragma once
#include "opencv2\opencv.hpp"
#include "VideoData.h"

namespace sim
{
	// Interface class for VideoData and ImageSequence
	class ImageStream
	{
	public:
		ImageStream();
		~ImageStream();

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
		double		getFrameRate();

	private:
		sim::VideoData	data;




	};
}

