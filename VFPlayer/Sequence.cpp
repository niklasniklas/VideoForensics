#include "Sequence.h"

namespace sim {

	Sequence::Sequence()
	{
	}


	Sequence::~Sequence()
	{
	}


	// returns next frame in sequence
	cv::Mat Sequence::nextFrame()
	{
		return cv::Mat();
	}



	// returns true if sequence is at end
	bool Sequence::atEnd()
	{
		return false;
	}

}