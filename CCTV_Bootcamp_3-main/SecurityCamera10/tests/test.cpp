#include <catch2/catch_test_macros.hpp>
#include "opencv2/opencv.hpp"
#include "../SecurityCamera10/CalcAvarage.h"
#include "../SecurityCamera10/Camera.h"
#include "../SecurityCamera10/program.h"

using namespace std;
using namespace cv;

TEST_CASE("main") { 
    cctv();
    REQUIRE(true);
}

TEST_CASE("avgCannelsOfMat") {
    uint8_t data[] = { 2,3,1,2,2,2,3,3,3,
                        4,4,4,5,5,5,6,6,6
                        ,7,7,7,8,8,8,9,9,9 };
    Mat* img = new Mat(3, 3, CV_8UC3, data);
    double avgB;
    double avgG;
    double avgR;
    float realAvgB, realAvgG, realAvgR;
    realAvgB = 46 / 9.0;
    realAvgG = 47 / 9.0;
    realAvgR = 5;
    calcAverageColor(*img, avgB, avgG, avgR);
    REQUIRE(avgB == realAvgB);
    REQUIRE(avgG == realAvgG);
    REQUIRE(avgR == realAvgR);
}

TEST_CASE("isSimilarImages") {
    uint8_t data[] = { 2,3,1,2,2,2,3,3,3,2,
                               4,4,4,5,5,5,6,6,6,
                               7,7,7,8,8,8,9,9,9 };
    Mat* img = new Mat(3, 3, CV_8UC3, data);

    uint8_t data1[] = { 2,3,1,2,2,2,3,3,3,2,
                      4,4,4,5,5,5,6,6,6,
                      7,7,7,8,8,8,9,9,9 };
    Mat* img1 = new Mat(3, 3, CV_8UC3, data1);
    REQUIRE(AreTheSameFrames(*img, *img1));
}
