#include "SafeQueue.h"
#include "Configuration.h"
#include "opencv2/opencv.hpp"

#define BACKEND_QUEUE_SIZE configFile::getInstance()->data.queueSize
using namespace std;
using namespace cv;



template<typename T>
bool SafeQueue<T>::empty()
{
	return queue_.empty();
}
template<typename T>
T SafeQueue<T>::front()
{
	return queue_.front();
}
//Push until it reaches a certain size
template<typename T>
void SafeQueue<T>::push(T item)
{
	unique_lock<mutex> lock(mutex_);
	if (queue_.size() >= BACKEND_QUEUE_SIZE)
		queue_.pop();
	queue_.push(item);
	lock.unlock();
	condVar_.notify_one();
}
template<typename T>
T SafeQueue<T>::pop()
{
	unique_lock<mutex> lock(mutex_);
	while (queue_.empty())
	{
		condVar_.wait(lock);
	}
	T item = queue_.front();
	queue_.pop();
	return item;
}
template<typename T>
T SafeQueue<T>::back()
{
	return queue_.back();
}
template<typename T>
int SafeQueue<T>::size()
{
	return queue_.size();
}
template class SafeQueue<Mat>;
template class SafeQueue<int>;

SafeQueue<Mat> qFrames;
bool stop_flag = false;
