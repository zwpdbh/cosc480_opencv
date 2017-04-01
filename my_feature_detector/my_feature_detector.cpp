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

RNG rng(12345);

const char* myShiTomasi_window = "My Shi Tomasi corner detector";

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

    myMat_dst = Mat::zeros(src_gray.size(), CV_32FC(6));


    return 0;

}
