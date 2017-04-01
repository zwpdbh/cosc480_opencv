//
// Created by zwpdbh on 25/03/2017.
//

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int maxCorners = 23;
int maxTrackBar = 100;
Mat src, src_gray;

const char* source_window = "image";
RNG rng(12345);

void goodFeaturesToTrack_Demo(int, void*) {
    if (maxCorners < 1) {
        maxCorners = 1;
    }

    vector<Point2f> corners;
    double qualityLevel = 0.01;
    double minDistance = 10;
    int blockSize = 3;
    bool userHarrisDetector = false;
    double k = 0.04;

    Mat copy;
    copy = src.clone();

    goodFeaturesToTrack(src_gray,
                        corners,
                        maxCorners,
                        qualityLevel,
                        minDistance,
                        Mat(),
                        blockSize,
                        userHarrisDetector,
                        k
    );
    cout << "** Number of corners detected: " << corners.size() << endl;
    int r = 4;
    for (size_t i = 0; i < corners.size(); i++) {
        circle(copy, corners[i], r, Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), -1, 8, 0);
    }

    namedWindow(source_window, WINDOW_AUTOSIZE);
    imshow(source_window, copy);
}

int main(int, char** argv) {
    string imgName = "../data/building.jpg";
    src = imread(imgName, IMREAD_COLOR);
    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    namedWindow(source_window, WINDOW_AUTOSIZE);
    createTrackbar("Max corners: ", source_window, &maxCorners, maxTrackBar, goodFeaturesToTrack_Demo);
    imshow(source_window, src);
    goodFeaturesToTrack_Demo(0, 0);

    waitKey(0);

    return 0;
}