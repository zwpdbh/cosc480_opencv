#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat src, src_gray;


Mat myShiTomasi_dst;
Mat myShiTomasi_copy;
int myShiTomasi_qualityLevel = 50;


int max_qualityLevel = 100;


double myShiTomasi_minVal;
double myShiTomasi_maxVal;

RNG rng(12345);


const char *myShiTomasi_window = "My Shi Tomasi corner detector";


void myShiTomasi_function(int, void *) {
    myShiTomasi_copy = src.clone();
    if (myShiTomasi_qualityLevel < 1) { myShiTomasi_qualityLevel = 1; }
    for (int j = 0; j < src_gray.rows; j++) {
        for (int i = 0; i < src_gray.cols; i++) {
            if (myShiTomasi_dst.at<float>(j, i) > myShiTomasi_minVal +
                                                  (myShiTomasi_maxVal - myShiTomasi_minVal) * myShiTomasi_qualityLevel /
                                                  max_qualityLevel) { circle(myShiTomasi_copy, Point(i, j), 4,
                                                                             Scalar(rng.uniform(0, 255),
                                                                                    rng.uniform(0, 255),
                                                                                    rng.uniform(0, 255)), -1, 8, 0);
            }
        }
    }
    imshow(myShiTomasi_window, myShiTomasi_copy);
}


int main(int, char **argv) {
    string input = "../data/building.jpg";
    src = imread(input, IMREAD_COLOR);
    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    int blockSize = 3;
    int apertureSize = 3;

    myShiTomasi_dst = Mat::zeros(src_gray.size(), CV_32FC1);

    cornerMinEigenVal(src_gray, myShiTomasi_dst, blockSize, apertureSize, BORDER_DEFAULT);

    minMaxLoc(myShiTomasi_dst, &myShiTomasi_minVal, &myShiTomasi_maxVal, 0, 0, Mat());

    namedWindow(myShiTomasi_window, WINDOW_AUTOSIZE);
    createTrackbar(" Quality Level:", myShiTomasi_window, &myShiTomasi_qualityLevel, max_qualityLevel,
                   myShiTomasi_function);
    myShiTomasi_function(0, 0);
    waitKey(0);
    return (0);
}



