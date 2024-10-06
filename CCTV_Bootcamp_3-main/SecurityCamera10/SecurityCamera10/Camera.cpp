#include "pch.h"
#include "Camera.h"
#include "Logger.h"
#include <grpcpp/grpcpp.h>
#include "cameraToBackend.grpc.pb.h"
#include "../SecurityCamera10/CameraClient.h"
#include "config.h"
#include "SafeQueue.h"


using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
//using namespace ProtoImage;
using namespace std;
using namespace cv;



bool AreTheSameFrames(Mat prev, Mat current) {
    int countChangePix = 100;
    for (int row = 0; row < prev.rows; row++) {
        for (int col = 0; col < prev.cols; col++) {
            Vec3b pixel1 = prev.at<Vec3b>(row, col);
            Vec3b pixel2 = current.at<Vec3b>(row, col);
            if (pixel1 != pixel2 && countChangePix > 0) {
                countChangePix--;
            }
            else if (countChangePix == 0)
                return false;
        }
    }
    return true;
}

void readVideo()

{

    //create chanel for sending
    std::shared_ptr<Channel> channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    CameraClient client(channel);

    VideoCapture video(INPUTVIDEOPATH);
    if (!video.isOpened()) {
        logger->error("Failed to open video file:", fmt::format("{}", INPUTVIDEOPATH));
        return;
    }
    logger->info("open video file: {}", INPUTVIDEOPATH);
    Mat frame, prevFrame;

    while (!stop_flag){

        bool readSuccess = video.read(frame);
        if (!readSuccess)
            break;


        if (!AreTheSameFrames(prevFrame, frame)) {
            //rames.push(frame.clone());

            //sendiing by grpc
            bool result = client.SendImage(frame);
            if (result) {
                logger->info("Image successfully send to server.");
            }
            else {
                logger->info("Failed to send image.");
            }
        }
        prevFrame = frame.clone();
        this_thread::sleep_for(chrono::seconds(1));
    }
    video.release();
}
