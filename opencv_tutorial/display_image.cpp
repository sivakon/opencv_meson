#include <stdio.h>
#include <opencv2/opencv.hpp>

extern "C" int display_image(char* s)
{
    cv::Mat image;
    image = cv::imread( s, 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
    cv::imshow("Display Image", image);
    cv::waitKey(0);
    return 0;
}