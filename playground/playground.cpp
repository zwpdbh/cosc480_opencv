//
//  main.cpp
//  SURF_feature_ descriptor
//
//  Created by zwpdbh on 02/04/2017.
//  Copyright © 2017 Otago. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;

/* @function main */
int main( int argc, char** argv )
{

    string imgname1 = "../data/box_in_scene.png";
    string imgname2 = "../data/box.png";

    Mat img_1 = imread( imgname1, IMREAD_GRAYSCALE );
    Mat img_2 = imread( imgname2, IMREAD_GRAYSCALE );

    if (img_1.empty()) {
        cout << "Input image1 not foud" << endl;
        return -1;
    }

    if (img_2.empty()) {
        cout << "Input image2 not foud" << endl;
        return -1;
    }

    //-- Step 1: Detect the keypoints using SURF Detector
    int minHessian = 400;
    Ptr<SURF> detector = SURF::create( minHessian );

    vector<KeyPoint> keypoints_1, keypoints_2;

    detector->detect( img_1, keypoints_1 );
    detector->detect( img_2, keypoints_2 );

    //-- Draw keypoints
    Mat img_keypoints_1 = img_1.clone();
    Mat img_keypoints_2 = img_2.clone();

    drawKeypoints(img_1, keypoints_1, img_keypoints_1);
    drawKeypoints(img_2, keypoints_2, img_keypoints_2);

//    drawKeypoints( img_1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
//    drawKeypoints( img_2, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    //-- Show detected (drawn) keypoints
    imshow("Keypoints 1", img_keypoints_1 );
    imshow("Keypoints 2", img_keypoints_2 );
    waitKey(0);
    return 0;
}