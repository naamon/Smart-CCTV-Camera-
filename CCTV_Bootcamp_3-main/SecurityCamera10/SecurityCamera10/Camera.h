#pragma once
#include "opencv2/opencv.hpp"
//#include "SafeQueue.h"
//#include "config.h"


bool AreTheSameFrames(cv::Mat prev, cv::Mat current);
void readVideo();
