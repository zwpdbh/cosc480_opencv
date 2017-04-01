//
//  main.cpp
//  Mat: the basic data container
//
//  Created by zwpdbh on 20/03/2017.
//  Copyright © 2017 Otago. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {

    Mat m1 = Mat(3, 2, CV_8UC3, Scalar(0,0,225));
    cout << "m1 = " << endl << "" << m1 << endl << endl;

    Mat m2 = Mat(3, 4, CV_8UC2, Scalar(1, 7));
    cout << "m2 = " << endl << "" << m2 << endl << endl;

    // http://docs.opencv.org/master/d6/d6d/tutorial_mat_the_basic_image_container.html
    //    int sz[3] = {3, 3, 3};
    //    Mat m3 = Mat(3, sz, CV_8UC(1), Scalar::all(0));
    //    cout << "m1 = " << endl << "" << m3 << endl << endl;

    Mat E = Mat::eye(4, 4, CV_64F);
    cout << "E = " << endl << " " << E << endl << endl;

    Mat O = Mat::ones(2, 2, CV_32F);
    cout << "O = " << endl << " " << O << endl << endl;

    Mat Z = Mat::zeros(3, 3, CV_8UC1);
    cout << "Z = " << endl << " " << Z << endl << endl;

    Mat C = Mat_<double>(3,3) << (0, -1, 0, -1, 5, -1, 0, -1, 0);
    cout << "C = " << endl << " " << format(C, Formatter::FMT_CSV) << endl << endl;

    Mat RowClone = C.row(1).clone();
    cout << "RowClone = " << endl << " " << RowClone << endl << endl;

    // 8 bit for unsign 0 ~ 256; for sign, is -125 ~ 125
    Mat R = Mat(3, 2, CV_8UC1);
    randu(R, Scalar::all(0), Scalar::all(500));
    cout << "R = " << endl << " " << format(R, Formatter::FMT_PYTHON) << endl << endl;


    Point2f P(5, 1);
    cout << "Point (2D) = " << P << endl << endl;

    Point3f P3f(2, 6, 7);
    cout << "Point (3D) = " << P3f << endl << endl;

    vector<float> v;
    v.push_back((float)CV_PI);
    v.push_back(2);
    v.push_back(3.01f);
    cout << "Vector of floats via Mat = " << Mat(v) << endl << endl;

    vector<Point2f> vPoints(20);
    for (size_t i = 0; i < vPoints.size(); i++) {
        vPoints[i] = Point2f((float)(i*5), (float)(i*7));
    }
    cout << "A vector of 2D points = " << vPoints << endl << endl;

    return 0;
}
