cmake_minimum_required(VERSION 2.8)
project( Corner_Detection )
find_package( OpenCV REQUIRED )
add_executable( Corner_Detection Corner_Detection.cpp )
target_link_libraries( Corner_Detection ${OpenCV_LIBS} )

