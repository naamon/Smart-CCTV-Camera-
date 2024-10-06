#include "pch.h"
#include "CalcAvarage.h"
#include "Logger.h" 
#include <ctime> 

using namespace std;
using namespace cv;

void calcAverageColor(const cv::Mat& image, double& avgR, double& avgG, double& avgB)
{
	cv::Scalar avgColor = mean(image);
	avgR = avgColor[2]; // Red channel
	avgG = avgColor[1]; // Green channel
	avgB = avgColor[0]; // Blue channel
}
void calcSaveDetectoins(cv::Mat currentFrame, std::vector<Detection> detections)
{
	logger->info("save detections and calc average color");

	for (const Detection& detection : detections) {
		double avgRectR, avgRectG, avgRectB;
		Mat detectionROI = currentFrame(Rect(
			(detection.box.x < 0) ? 0 : detection.box.x,
			(detection.box.y < 0) ? 0 : detection.box.y,
			(detection.box.x + detection.box.width > currentFrame.size().width) ? currentFrame.size().width - detection.box.x : detection.box.width,
			(detection.box.y + detection.box.height > currentFrame.size().height) ? currentFrame.size().height - detection.box.y : detection.box.height)); // get the small image of the detection area only
		calcAverageColor(detectionROI, avgRectR, avgRectG, avgRectB);
		saveToDB(detection, avgRectR, avgRectG, avgRectB);
	}
}