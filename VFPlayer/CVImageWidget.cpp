#include "CVImageWidget.h"
#include <QMouseEvent>

//
//CVImageWidget::CVImageWidget(void)
//{
//}
//
//
//CVImageWidget::~CVImageWidget(void)
//{
//}

void CVImageWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->type() == QMouseEvent::MouseButtonPress)
	{
		int a = 0;
//		int b = (_parent)->images->count();
	}
}


void CVImageWidget::showManipImage(const cv::Mat& image) //HÄR
{
	cv::Mat img = manip.resize(image);
	showImage(img);
}