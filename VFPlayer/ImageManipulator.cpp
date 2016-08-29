#include "ImageManipulator.h"


ImageManipulator::ImageManipulator()
{
}


ImageManipulator::~ImageManipulator()
{
}


cv::Mat ImageManipulator::resize(cv::Mat img)
{
	cv::Mat img2 = img.clone();
	img2 = img2 + img2;
	return img2;
}