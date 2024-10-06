//#pragma once
//#include "opencv2/opencv.hpp"
//#include <condition_variable>
//#include <mutex>
//#include <queue>
//
//using namespace std;
//using namespace cv;
//
//template<typename T>
//class SafeQueue {
//private:
//    queue<T> queue_;
//    mutex mutex_;
//    //condition variable for signaling
//    condition_variable condVar_;
//public:
//    void push(T item);
//    T front();
//    T pop();
//    bool empty();
//    T back();
//    int size();
//};
//extern SafeQueue<Mat> qFrames;
//extern bool stop_flag;


#pragma once
#include "opencv2/opencv.hpp"
#include <condition_variable>
#include <mutex>
#include <queue>


template<typename T>
class SafeQueue {
private:
    std::queue<T> queue_;
    std::mutex mutex_;
    //condition variable for signaling
    std::condition_variable condVar_;
public:
    void push(T item);
    T front();
    T pop();
    bool empty();
    T back();
    int size();
};
extern SafeQueue<cv::Mat> qFrames;
extern bool stop_flag;
