#include "ImageStream.h"

namespace sim {

	ImageStream::ImageStream()
	{
	}


	ImageStream::~ImageStream()
	{
	}


	bool ImageStream::loadVideo(std::string name)
	{
		bool load_ok = data.loadVideo(name);
		return load_ok;
	}

	void ImageStream::nextFrame()
	{
		data.nextFrame();
	}

	void ImageStream::prevFrame()
	{
		data.prevFrame();
	}

	void ImageStream::jumpFrames(int amount)
	{
		data.jumpFrames(amount);
	}

	void ImageStream::saveCurrentFrame(std::string str)
	{
		data.saveCurrentFrame(str);
	}

	int  ImageStream::getVideolength()
	{
		int len = data.getVideolength();
		return len;
	}

	int  ImageStream::getCurrentFrameNumber()
	{
		int no = data.getCurrentFrameNumber();
		return no;
	}

	void ImageStream::setCurrentFrameNumber(int no)
	{
		data.setCurrentFrameNumber(no);
	}

	std::string ImageStream::getCurrentTime()
	{
		std::string time = data.getCurrentTime();
		return time;
	}

	cv::Mat	ImageStream::getCurrentFrame()
	{
		cv::Mat img = data.getCurrentFrame();
		return img;
	}

	double ImageStream::getFrameRate()
	{
		double rate = data.getFrameRate();
		return rate;
	}

}