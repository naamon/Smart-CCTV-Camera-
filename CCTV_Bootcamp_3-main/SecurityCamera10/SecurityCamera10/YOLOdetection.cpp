﻿#include "pch.h"
#include "YOLOdetection.h"
using namespace std;
using namespace cv;


std::vector<std::string> load_class_list()
{
	vector <string> class_list;
	ifstream ifs(YOLOCLASS);
	string line;
	while (getline(ifs, line))
	{
		class_list.push_back(line);
	}
	return class_list;
}

//1 לייבוא ​​המודל 
void load_net(cv::dnn::Net& net)
{
	net = cv::dnn::readNet(YOLOPATH);
}

//2
cv::Mat format_yolov5(const cv::Mat& source)
{
	int col = source.cols;
	int row = source.rows;
	int _max = MAX(col, row);
	cv::Mat result = cv::Mat::zeros(_max, _max, CV_8UC3);
	source.copyTo(result(cv::Rect(0, 0, col, row)));
	return result;
}
//3  ביטול גלישת הפלט -ביטול זהוי כפול
void detect(cv::Mat& image, cv::dnn::Net& net, std::vector<Detection>& output, const std::vector<std::string>& className)
{
	cv::Mat blob;
	auto input_image = format_yolov5(image);
	cv::dnn::blobFromImage(input_image, blob, 1. / 255., cv::Size(INPUT_WIDTH, INPUT_HEIGHT), cv::Scalar(), true, false);
	net.setInput(blob);
	vector<cv::Mat> outputs;
	net.forward(outputs, net.getUnconnectedOutLayersNames());
	float x_factor = input_image.cols / INPUT_WIDTH;
	float y_factor = input_image.rows / INPUT_HEIGHT;
	float* data = (float*)outputs[0].data;
	const int dimensions = 85;
	const int rows = 25200;
	vector<int> class_ids;
	vector<float> confidences;
	vector<cv::Rect> boxes;

	for (int i = 0; i < rows; ++i) {
		float confidence = data[4];
		if (confidence >= CONFIDENCE_THRESHOLD) {
			float* classes_scores = data + 5;
			cv::Mat scores(1, className.size(), CV_32FC1, classes_scores);
			cv::Point class_id;
			double max_class_score;
			minMaxLoc(scores, 0, &max_class_score, 0, &class_id);
			if (max_class_score > SCORE_THRESHOLD) {
				confidences.push_back(confidence);
				class_ids.push_back(class_id.x);
				float x = data[0];
				float y = data[1];
				float w = data[2];
				float h = data[3];
				int left = int((x - 0.5 * w) * x_factor);
				int top = int((y - 0.5 * h) * y_factor);
				int width = int(w * x_factor);
				int height = int(h * y_factor);
				boxes.push_back(cv::Rect(left, top, width, height));
			}
		}
		data += 85;
	}

	std::vector<int> nms_result;
	//כדי להסיר זיהויים חופפים/כפולים
	cv::dnn::NMSBoxes(boxes, confidences, SCORE_THRESHOLD, NMS_THRESHOLD, nms_result);
	for (int i = 0; i < nms_result.size(); i++) {
		int idx = nms_result[i];
		Detection result;
		result.class_id = class_ids[idx];
		result.confidence = confidences[idx];
		result.box = boxes[idx];
		output.push_back(result);
	}
}

void loadYOLO()
{
	vector <string> class_list = load_class_list();
	cv::dnn::Net net;
	load_net(net);
}
//4 הדפסת התמונה המתקבלת
// check why we need to know the frame rate
std::vector<Detection> detectOne(cv::Mat frame, std::vector<std::string> class_list, cv::dnn::Net net, std::chrono::steady_clock::time_point start, int frame_count, float fps, int total_frames)
{
	vector<Detection> output;

	if (frame.empty())
	{
		cout << "End of stream\n";
		return output;
	}

	detect(frame, net, output, class_list);

	frame_count++;
	total_frames++;
	int detections = output.size();

	// it draws the rectangles arount the objects
	for (int i = 0; i < detections; ++i)
	{
		auto detection = output[i];
		auto box = detection.box;
		auto classId = detection.class_id;
		const auto color = colors[classId % colors.size()];
		cv::rectangle(frame, box, color, 3);
		cv::rectangle(frame, cv::Point(box.x, box.y - 20), cv::Point(box.x + box.width, box.y), color, cv::FILLED);
		cv::putText(frame, class_list[classId].c_str(), cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
	}

	if (frame_count >= 30)
	{
		auto end = std::chrono::steady_clock::now();
		fps = frame_count * 1000.0 / std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		frame_count = 0;
		start = std::chrono::steady_clock::now();
	}

	if (fps > 0)
	{
		std::ostringstream fps_label;
		fps_label << std::fixed << std::setprecision(2);
		fps_label << "FPS: " << fps;
		string fps_label_str = fps_label.str();
		cv::putText(frame, fps_label_str.c_str(), cv::Point(10, 25), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 2);
	}
	cv::imshow("output", frame);

	return output;
}
