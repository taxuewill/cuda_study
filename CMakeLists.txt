cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(rgbtest)


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV  REQUIRED )
find_package(OpenCV 3 REQUIRED
  COMPONENTS
    opencv_core
    opencv_imgproc
    opencv_imgcodecs
  CONFIG
)
FIND_PACKAGE(CUDA REQUIRED)
include_directories(
/usr/local/cuda/include
)
add_subdirectory(cuda)

set(EXTRA_LIBS ${EXTRA_LIBS} gpu)

add_executable(rgbtest main.cpp)
target_link_libraries(rgbtest ${EXTRA_LIBS} ${OpenCV_LIBRARIES})