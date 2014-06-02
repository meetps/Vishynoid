cmake_minimum_required(VERSION 2.8)
project( Edge )
find_package( OpenCV REQUIRED )
add_executable( Edge Edge.cpp )
target_link_libraries( Edge ${OpenCV_LIBS} )

