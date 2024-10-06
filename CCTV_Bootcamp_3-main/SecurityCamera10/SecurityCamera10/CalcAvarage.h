#pragma once
#include "pch.h"
#include "opencv2/opencv.hpp"
#include "SafeQueue.h"
#include "Detection.h"
#include "Sqlite.h"
#include <fstream>

#ifdef _DEBUG
#pragma comment(lib,"opencv_world480d.lib")
#else
#pragma comment(lib,"opencv_world480.lib")
#endif // DEBUG

void calcAverageColor(const cv::Mat& image, double& avgR, double& avgG, double& avgB);
void calcSaveDetectoins(cv::Mat currentFrame, std::vector<Detection> detections);