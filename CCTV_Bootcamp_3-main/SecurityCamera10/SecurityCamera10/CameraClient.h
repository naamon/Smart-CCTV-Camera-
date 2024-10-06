#pragma once
#include <grpcpp/grpcpp.h>
//#include <../ProtoLib/cameraToBackend.pb.h>
#include "opencv2/opencv.hpp"
#include "cameraToBackend.grpc.pb.h"


class CameraClient
{
public:
	CameraClient(std::shared_ptr<grpc::Channel> channel) : stub_(ProtoImage::ImageTransfer::NewStub(channel)) {};
	
	bool SendImage(const cv::Mat& img);
	
private:
	std::unique_ptr<ProtoImage::ImageTransfer::Stub> stub_;
};
