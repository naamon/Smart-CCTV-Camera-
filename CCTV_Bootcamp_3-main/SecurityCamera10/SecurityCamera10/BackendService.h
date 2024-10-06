
#pragma once

#include <grpcpp/grpcpp.h>
#include "cameraToBackend.grpc.pb.h"

using grpc::ServerContext;
using grpc::Status;
using ProtoImage::ImageRequest;
using ProtoImage::ImageResponse;
using ProtoImage::ImageTransfer;

class BackendService final : public ImageTransfer::Service {
public:
    Status SendImage(ServerContext* context, const ImageRequest* request, ImageResponse* response) override;
};


