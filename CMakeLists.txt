cmake_minimum_required(VERSION 3.6)
project(tutorial_opencv)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-I/usr/local/Cellar/opencv3/3.2.0/include/opencv -I/usr/local/Cellar/opencv3/3.2.0/include -L/usr/local/Cellar/opencv3/3.2.0/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core")
set(SOURCE_FILES main.cpp)

# tutorial 01
add_executable(tutorial_01_Mat tutorial_01_Mat/tutorial_01_Mat.cpp)

# tutorial 02
add_executable(tutorial_02 tutorial_02/tutorial_02.cpp)

# playground
add_executable(playground playground/playground.cpp)

# Harris corner detector
add_executable(Harris_corner_detector Harris_corner_detector/harris_corner_detector.cpp)

# Shi-Tomasi corner detector
add_executable(Shi-Tomasi_corner_detector Shi-Tomasi_corner_detector/shi-Tomasi_corner_detector.cpp)

# my feature detector
add_executable(my_feature_detector my_feature_detector/my_feature_detector.cpp)

add_executable(tutorial_opencv ${SOURCE_FILES})