#pragma once

#include <opencv2\opencv.hpp>

namespace sim
{
	class Sequence
	{
	public:
		Sequence();
		~Sequence();
		// returns next frame in sequence
		cv::Mat nextFrame();
		// returns true if sequence is at end
		bool atEnd();
	};
}
