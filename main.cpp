

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    string imageName("../data/HappyFish.jpg");
    if (argc > 1) {
        imageName = argv[1];
    }

    Mat image = imread(imageName.c_str(), IMREAD_COLOR);
    namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("Display window", image);
    waitKey(0);
    destroyWindow("Display window");
    return 0;
}