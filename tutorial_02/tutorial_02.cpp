//
// Created by zwpdbh on 20/03/2017.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    string imageName("../data/HappyFish.jpg");
    if (argc > 1) {
        imageName = argv[1];
    }

    Mat image;
    image = imread( imageName, 1 );

    Mat m(2, 2, CV_8SC3, Scalar(0, 0, 225));

    Mat gray_image;
    cvtColor( image, gray_image, COLOR_BGR2GRAY );
    imwrite( "/Users/zw/Downloads/tmp/Gray_Image.jpg", gray_image );
    namedWindow( imageName, WINDOW_AUTOSIZE );
    namedWindow( "Gray image", WINDOW_AUTOSIZE );
    imshow( imageName, image );
    imshow( "Gray image", gray_image );
    waitKey(0);
    return 0;
}
