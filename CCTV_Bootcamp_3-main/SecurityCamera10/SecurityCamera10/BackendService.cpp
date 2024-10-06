#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "cameraToBackend.grpc.pb.h"
#include "BackendService.h"
#include "../../SecurityCamera10/Backend.h"
#include "opencv2/opencv.hpp"
#include <vector>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using ProtoImage::ImageTransfer;
using ProtoImage::ImageRequest;
using ProtoImage::ImageResponse;



Status BackendService::SendImage(ServerContext* context, const ImageRequest* request, ImageResponse* response)

{
    // Process the received image (request->data()) here
// Example: Assuming processing is successful

    const std::string& image_data_str = request->data();
    std::vector<uchar> image_data(image_data_str.begin(), image_data_str.end());

    // Decode the image data into a cv::Mat
    cv::Mat image = cv::imdecode(image_data, cv::IMREAD_COLOR);
    detectCars(image);


    response->set_sucsses(true);
    return Status::OK;

}
