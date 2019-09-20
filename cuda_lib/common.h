#include <stdio.h>

// For the CUDA runtime routines (prefixed with "cuda_")
#include <cuda_runtime.h>

extern "C"
void vectorAdd(const int *A,const int *B,int * C,int numElements);