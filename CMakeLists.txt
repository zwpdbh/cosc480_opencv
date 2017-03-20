cmake_minimum_required(VERSION 3.6)
project(tutorial_opencv)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-I/usr/local/Cellar/opencv3/3.2.0/include/opencv -I/usr/local/Cellar/opencv3/3.2.0/include -L/usr/local/Cellar/opencv3/3.2.0/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core")
set(SOURCE_FILES main.cpp )

# tutorial 01
add_executable(tutorial_01 tutorial_01/tutorial_01.cpp)


add_executable(tutorial_opencv ${SOURCE_FILES})