cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(cuda_lib)

FIND_PACKAGE(CUDA REQUIRED)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# nvcc flags
set(
	CUDA_NVCC_FLAGS
	${CUDA_NVCC_FLAGS}; 
    -O3 -gencode arch=compute_53,code=sm_53
)

file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp *.cuh)
file(GLOB CURRENT_SOURCES  *.cpp *.cu)


include_directories("${CUDA_INCLUDE_DIRS}")

source_group("Include" FILES ${CURRENT_HEADERS})
source_group("Source" FILES ${CURRENT_SOURCES})

cuda_add_library(cuda_lib SHARED ${CURRENT_HEADERS} ${CURRENT_SOURCES})
