#include "common.h"

#include <stdio.h>


__global__ void
cudaVectorAdd(const int *A, const int *B, int *C, int numElements)
{
    // int i = threadIdx.x;
    // printf("add %d",blockDim.x);
    // if (i < numElements)
    // {
    //     C[i] = A[i] + B[i];
    // }
    printf("CUDA!\n");
}


void vectorAdd(const int *A,const int *B,int * C,int numElements){
    printf("vectorAdd\n");
    
    cudaVectorAdd<<<1,30>>>(A,B,C,numElements);
}