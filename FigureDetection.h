#ifndef FIGUREDETECTION_H
#define FIGUREDETECTION_H

#include <highgui.h>
#include <cv.h>
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;
using namespace cv;

class FigureDetection{
private:
    CvMemStorage* storage;
    CvSeq* contour;
    CvSeq* sec;
    IplImage *copyImage, *grayImage;//Imagenes

public:
    FigureDetection();
    ~FigureDetection();
    IplImage* get(IplImage*);
    void getImageContour(IplImage*);
    void webCam(int);
    void printCharateristic(CvPoint**, int);
};


#endif // FIGUREDETECTION_H
