cmake_minimum_required(VERSION 3.6)
project(tutorial_opencv)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-I/usr/local/Cellar/opencv3/3.2.0/include/opencv -I/usr/local/Cellar/opencv3/3.2.0/include -L/usr/local/Cellar/opencv3/3.2.0/lib -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dpm -lopencv_fuzzy -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_saliency -lopencv_sfm -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_rgbd -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_face -lopencv_plot -lopencv_dnn -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_flann -lopencv_xobjdetect -lopencv_objdetect -lopencv_ml -lopencv_xphoto -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_photo -lopencv_imgproc -lopencv_core")
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