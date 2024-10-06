#include "../SecurityCamera10/Logger.h"
#include "../SecurityCamera10/Backend.h"
#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "cameraToBackend.grpc.pb.h"
#include "../SecurityCamera10/BackendService.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using ProtoImage::ImageTransfer;
using ProtoImage::ImageRequest;
using ProtoImage::ImageResponse;

using namespace std;
using namespace cv;


int main(int argc, char* argv[]) {
	initLogger();

	logger->info("start project in server process!", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);

    std::string server_address("0.0.0.0:50051"); // Replace with your desired server address

    BackendService service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    logger->info("Server listening on {}", server_address);
    server->Wait();


	return 0;
}
