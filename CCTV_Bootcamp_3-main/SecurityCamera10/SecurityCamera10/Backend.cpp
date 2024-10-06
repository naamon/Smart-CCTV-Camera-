#include "Backend.h"
#include "Logger.h" 

using namespace std;
using namespace cv;


void detectCars(const cv::Mat& img)
{
	logger->info("detecting cars");

	//int totalFrames=qFrames.size();
	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	int frame_count = 1;
	Mat currentFrame = img;
	vector<string> class_list = { "car" };
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	float fps = frame_count * 1000.0 / std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	vector<Detection> Detections = detectOne(currentFrame, class_list, dnn::readNet(YOLOPATH), start, frame_count, fps, 1);
	calcSaveDetectoins(currentFrame, Detections);


	//while (!stop_flag) 
 // {
	//	if (!qFrames.empty())
	//	{
	//	  //qFrames.pop();
	//  }
 // }
}	
