﻿#pragma once
#include "pch.h"
#include "opencv2/opencv.hpp"
#include "SafeQueue.h"
#include "Detection.h"
#include "config.h"
#include <vector>
#include <fstream>

#ifdef _DEBUG
#pragma comment(lib,"opencv_world480d.lib")
#else
#pragma comment(lib,"opencv_world480.lib")
#endif // DEBUG


const float INPUT_WIDTH = 640.0;
const float INPUT_HEIGHT = 640.0;
const float SCORE_THRESHOLD = 0.2;
const float NMS_THRESHOLD = 0.4;
const float CONFIDENCE_THRESHOLD = 0.4;

const std::vector<cv::Scalar> colors = { cv::Scalar(255, 255, 0), cv::Scalar(0, 255, 0), cv::Scalar(0, 255, 255), cv::Scalar(255, 0, 0) };

std::vector<std::string> load_class_list();

void load_net(cv::dnn::Net& net);

cv::Mat format_yolov5(const cv::Mat& source);

void detect(cv::Mat& image, cv::dnn::Net& net, std::vector<Detection>& output, const std::vector<std::string>& className);

void loadYOLO();

std::vector<Detection> detectOne(cv::Mat frame, std::vector<std::string> class_list, cv::dnn::Net net, std::chrono::steady_clock::time_point start, int frame_count, float fps, int total_frames);
