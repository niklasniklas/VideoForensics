#include "ImageManipulator.h"


ImageManipulator::ImageManipulator()
{
}


ImageManipulator::~ImageManipulator()
{
}


cv::Mat ImageManipulator::resize(cv::Mat img)
{
	img = img + img;
	return img;
}