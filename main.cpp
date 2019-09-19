#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include <opencv2/core/types.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "cuda/cudaYUV.h"

extern "C"
void useCUDA();


int main(){

    cout<<"Hello,Cuda"<<endl;
    cv::Mat image = cv::imread("../resource/boldt.jpg");
    cv::Mat yuvImage;
    // cv::cvtColor(image,yuvImage,CV_RGBA2YUV_YV12);
    char * yuvData = new char[320*240*3/2];
    //cudaRGBAToYV12(image.data,(uint8_t*)yuvData,320,240);
    //cv::namedWindow("Show Image");
    // cv::imshow("Show Image",image);
    // cout<<"length "<<yuvImage.isContinuous()<<endl;
    // cout<<"cols "<<yuvImage.cols<<",ros"<<yuvImage.rows<<endl;
    ofstream * output = new ofstream("./boldt2.yuv");
    output->write((char*)yuvImage.data,320*240*3/2);
    
    // memcpy(yuvData,(char*)yuvImage.data,320*240*3/2);
    // char * outData = new char[320*240*3];


    //useCUDA();
    delete output;
    
    cv::waitKey(10*1000);

    
    return 0;
}