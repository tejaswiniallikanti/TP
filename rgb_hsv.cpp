#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace cv;

/// Global variables

//int threshold_value = 0;
//int threshold_type = 3;;
//int const max_value = 255;
//int const max_type = 4;
//int const max_BINARY_value = 255;

Mat original;
int main( int argc, char** argv )
{
  int type = 1;//img
  Mat imgOriginal;
  
  VideoCapture cap(argv[1]); // try capture the video
  if(argc >= 2)
  { 
      type = 2; //video

  }
  else
  {
    imgOriginal = imread(argv[1], CV_LOAD_IMAGE_UNCHANGED);
  }
  namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"
  int iLowH,iHighH;
  int iLowS,iHighS;
  int iLowV,iHighV;
  cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
  cvCreateTrackbar("HighH", "Control", &iHighH, 179);

  cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
  cvCreateTrackbar("HighS", "Control", &iHighS, 255);

  cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
  cvCreateTrackbar("HighV", "Control", &iHighV, 255);

  /// Load an image

  //original = imread( argv[1], 1 );

    //if ( !original.data )
    //{
      //  printf("No image data \n");
        //return -1;
    //}
  //Mat RGB_HSV;
  /// Convert the image to Gray
  
  /// Create a window to display results
  //namedWindow("RGB_HSV", CV_WINDOW_AUTOSIZE );
  Mat imgThreshold;
      

  /// Create Trackbar to choose type of Threshold
  
   
  /// Wait until user finishes program
  while(true)
  {
    int c;
    //std::cout<<iLowH<<" "<<iHighH<<"\n";

    cvtColor( original, RGB_HSV, COLOR_BGR2HSV );
    inRange(RGB_HSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThreshold); //Threshold the image
  imshow("Threshold Image", imgThreshold); //show the thresholded image

  /// Call the function to initialize
 // Threshold_Demo( 0, 0 );
  imshow("Original", original); //show the original image

    c = waitKey( 20 );
    if( (char)c == 27 )
      { break; }
   }

}


/**
 * @function Threshold_Demo
 */
/*void Threshold_Demo( int, void* )
{
  /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
   

  threshold( src_gray, dst, threshold_value, max_BINARY_value,threshold_type );

  imshow( window_name, dst );
}*/
