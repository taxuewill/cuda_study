cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

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

add_subdirectory(cuda_lib)

set(EXTRA_LIBS ${EXTRA_LIBS} gpu)
set(EXTRA_LIBS ${EXTRA_LIBS} cuda_lib)

add_executable(rgbtest main.cpp)
target_link_libraries(rgbtest ${EXTRA_LIBS} ${OpenCV_LIBRARIES})

add_executable(test1 cuda_test/test1.cpp)
target_link_libraries(test1 ${EXTRA_LIBS} ${OpenCV_LIBRARIES})