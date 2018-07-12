#include <stdio.h>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

using namespace cv;
using namespace std;

int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;
double RESIZE_X = 0.2;
double RESIZE_Y = 0.2;

Mat src; Mat dst;
const string window_name = "Image player";

int display_dst( int delay );

extern "C" int img_display(char* s)
{
    Mat image, resized_image;
    image = imread( s, 1 );
    resize(image, resized_image, Size(), RESIZE_X, RESIZE_Y);
    // image = resized_image;
    if ( !resized_image.data )
    {
        printf("No image data \n");
        return -1;
    }
    // namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", resized_image);
    waitKey(0);
    return 0;
}

extern "C" int blur_image(char *s)
{   
    namedWindow(window_name, WINDOW_AUTOSIZE);
    src = imread( s, 1 ); // source image

    Mat src_resized;
    resize(src, src_resized, Size(), RESIZE_X, RESIZE_Y);
    // Error handling later
    
    dst = src_resized.clone();

    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        blur( src_resized, dst, Size( i, i ), Point(-1,-1) );
        if( display_dst( DELAY_BLUR ) != 0 )
        {
            return 0;
        }
    }

    return 0;
}

int display_dst( int delay )
{
    imshow( window_name, dst );
    int c = waitKey ( delay );
    if( c >= 0 ) { return -1; }
    return 0;
}