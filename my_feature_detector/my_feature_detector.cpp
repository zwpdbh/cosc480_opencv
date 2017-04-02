#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int qualityLevel = 50;
int maxQuanlityLevel = 100;
double maximumEigenvalue;
double minimumEigenvalue;


Mat srcImg;
Mat graySrcImg;
Mat featureMatrix;

RNG rng = RNG(123456);
const char *windowName = "My Shi Tomasi corner detector";

void myShiTomasiFunction(int, void *) {
    Mat srcImg_copy = srcImg.clone();

    if (qualityLevel < 1) {
        qualityLevel = 1;
    }
    for (int j = 0; j < graySrcImg.rows; j++) {
        for (int i = 0; i < graySrcImg.cols; ++i) {
            if (featureMatrix.at<float>(j, i) > minimumEigenvalue + (maximumEigenvalue - minimumEigenvalue)
                                                                    * qualityLevel / maxQuanlityLevel) {
                Point p = Point(i, j);
                int radius = 4;
                Scalar scalar = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
                circle(srcImg_copy, p, radius, scalar, -1);
            }
        }
    }
    imshow(windowName, srcImg_copy);
}

int main(int, char **argv) {
    string inputImg = "../data/building.jpg";
    srcImg = imread(inputImg, IMREAD_COLOR);

    if (srcImg.empty()) {
        cout << "Input image not found." << endl;
        return -1;
    }

    cvtColor(srcImg, graySrcImg, COLOR_BGR2GRAY);

    featureMatrix = Mat::zeros(graySrcImg.size(), CV_32FC1);
    cornerMinEigenVal(graySrcImg, featureMatrix, 3, 3, BORDER_DEFAULT);
    minMaxLoc(featureMatrix, &minimumEigenvalue, &maximumEigenvalue);

    namedWindow(windowName);
    createTrackbar("Quality level: ", windowName, &qualityLevel, maxQuanlityLevel, myShiTomasiFunction);
    myShiTomasiFunction(0, 0);
    waitKey(0);

    return 0;
}
