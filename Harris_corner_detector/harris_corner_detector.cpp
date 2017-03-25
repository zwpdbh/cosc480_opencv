//
// Created by zwpdbh on 25/03/2017.
//



#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

Mat src, src_gray;
int thresh = 200;
int max_thresh = 255;

const char* source_window = "source image";
const char* corners_window = "corners detected";




void cornerHarris_demo(int, void*) {
    Mat dst, dst_norm, dst_norm_scaled;

    dst = Mat::zeros(src.cols, src.rows, CV_32FC1);

    int blockSize = 2;
    int apertureSize = 3;
    double k = 0.04;

    cornerHarris(src_gray, dst, blockSize, apertureSize, k, BORDER_DEFAULT);
    normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
    convertScaleAbs(dst_norm, dst_norm_scaled);

    for (int j = 0; j < dst_norm.rows; j++) {
        for (int i = 0; i < dst_norm.cols; i++) {
            if ((int) dst_norm.at<float>(j, i) > thresh) {
                circle(dst_norm_scaled, Point(i, j), 5, Scalar(0), 2, 8, 0);
            }
        }
    }

    namedWindow(corners_window, WINDOW_AUTOSIZE);
    imshow(corners_window, dst_norm_scaled);
}


int main(int argc, const char * argv[]) {
    string imageName("/Users/zw/code/OpenCV/opencv_tutorials/data/building.jpg");

    src = imread(imageName, IMREAD_COLOR);
    if (src.empty()) {
        cout << "Could not find the image" << endl;
        return -1;
    }
    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    namedWindow(source_window, WINDOW_AUTOSIZE);
    cvCreateTrackbar2("Threadhold", source_window, &thresh, max_thresh, cornerHarris_demo);
    imshow(source_window, src);

    cornerHarris_demo(0, 0);

    waitKey(0);

    return 0;
}
