#pragma once

#include <opencv2\opencv.hpp>

namespace sim
{
	class Sequence
	{
	public:
		Sequence();
		~Sequence();

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
		cv::VideoCapture	video;
		std::string			filepath;
		cv::Mat				currentFrame;

		std::vector<cv::Mat*> imgvect;
		int currentIndex;


		// returns true if sequence is at end
		bool atEnd();
	};
}
