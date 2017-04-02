//
// Created by zwpdbh on 01/04/2017.
//

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src, src_gray;
Mat myShiTomasi_dst, myShiTomasi_copy;
Mat mc;

RNG rng(12345);

const char* myShiTomasi_window = "My Shi Tomasi corner detector";

int myShiTomasi_qualityLevel = 50;
int myHarris_qualityLevel = 50;
int max_qualityLevel = 100;

double myHarris_minVal; double myHarris_maxVal;
double myShiTomasi_minVal; double myShiTomasi_maxVal;


void myShiTomasi_function( int, void* ) {
    myShiTomasi_copy = src.clone();
    if (myShiTomasi_qualityLevel < 1) {
        myShiTomasi_qualityLevel = 1;
    }

    for (int j = 0; j < src_gray.rows; ++j) {
        for (int i = 0; i < src_gray.cols; ++i) {
            if (myShiTomasi_dst.at(j, i) > myShiTomasi_minVal + (myShiTomasi_maxVal - myShiTomasi_minVal) * myShiTomasi_qualityLevel / max_qualityLevel) {
                circle(myShiTomasi_copy, Point(i, j), 4, Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), -1, 8, 0);
            }
        }
    }
    imshow(myShiTomasi_window, myShiTomasi_copy);

}

int main(int, char** argv){
    // 1. read image and get its gray associated one
    if (argv[1] == NULL) {
        string imgName = "../data/building.jpg";
        src = imread(imgName, IMREAD_COLOR);
    } else {
        src = imread(argv[1], IMREAD_COLOR);
    }

    if (src.empty()) {
        cout << "Can not find input image." << endl;
        return -1;
    }

    // 2.
    int blockSize = 3;
    int apertureSize = 3;

    myShiTomasi_dst = Mat::zeros(src_gray.size(), CV_32FC(6));
    mc = Mat::zeros(src_gray.size(), CV_32FC1);

    cornerEigenValsAndVecs(src_gray, myShiTomasi_dst, blockSize, apertureSize, BORDER_DEFAULT);

    // 3. calculate mc
    for (int j = 0; j < src_gray.rows; j++) {
        for (int i = 0; i < src_gray.cols; i++) {
            float lambda1 = myShiTomasi_dst.at<Vec6f>(j, i)[0];
            float lambda2 = myShiTomasi_dst.at(j, i)[1];
            mc.at(j, i) = lambda1 * lambda2 - 0.04f * pow((lambda1 + lambda2), 2);
        }
    }
    minMaxLoc(mc, &myShiTomasi_minVal, &myShiTomasi_maxVal, 0, 0, Mat());

    // 4. create window and track bar
    namedWindow(myShiTomasi_window, WINDOW_AUTOSIZE);
    createTrackbar("Quality level:", myShiTomasi_window, &myShiTomasi_qualityLevel, max_qualityLevel, myShiTomasi_function);
//    myShiTomasi_function(0, 0);

    waitKey(0);

    return 0;

}
