#include "cameraClient.h"
#include "cameraToBackend.grpc.pb.h"
#include "opencv2/opencv.hpp"
#include "Logger.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using namespace ProtoImage;

bool CameraClient::SendImage(const cv::Mat& img) {

    // Serialize cv::Mat to bytes
    std::vector<uchar> img_data;
    cv::imencode(".jpg", img, img_data);

    // Create gRPC request
    ProtoImage::ImageRequest request;
    request.set_data(img_data.data(), img_data.size());

    ProtoImage::ImageResponse response;
    ClientContext context;

    // Make the gRPC call
    Status status = stub_->SendImage(&context, request, &response);

    if (status.ok()) {
        return response.sucsses();
    }
    else {
        logger->error("RPC failed" + status.error_message());
        return false;
    }
}


