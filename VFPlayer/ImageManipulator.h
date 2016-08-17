#pragma once
#include "opencv2\opencv.hpp"

class ImageManipulator
{
public:
	ImageManipulator();
	~ImageManipulator();

	cv::Mat resize(cv::Mat);

private:
	cv::Mat img;

};

