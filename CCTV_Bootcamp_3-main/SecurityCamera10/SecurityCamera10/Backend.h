#pragma once
#include "pch.h"
#include "opencv2/opencv.hpp"
#include "SafeQueue.h"
#include "CalcAvarage.h"
#include "YOLOdetection.h"

#ifdef _DEBUG
#pragma comment(lib,"opencv_world480d.lib")
#else
#pragma comment(lib,"opencv_world480.lib")
#endif // DEBUG

void detectCars(const cv::Mat& img);
