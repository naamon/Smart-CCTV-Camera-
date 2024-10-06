#include "program.h"
#include "Backend.h"
//#include "Camera.h"
#include "Logger.h"
#include <iostream>
#include <thread>

using namespace std;

int cctv()
{
    initLogger();
    // Create threads for camera and backend

    /*thread camera_thread(readVideo);
    thread backend_thread(detectCars);*/

    // Wait for user input to stop the program
    cout << "Press Enter to stop the program...";
    cin.ignore();

    // Set the stop flag to true to stop the threads
    stop_flag = true;

    // Wait for the camera and backend threads to finish

    /*camera_thread.join();
    backend_thread.join();*/

    return 0;
}