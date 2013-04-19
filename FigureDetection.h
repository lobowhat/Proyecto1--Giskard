#ifndef FIGUREDETECTION_H
#define FIGUREDETECTION_H

#include <highgui.h>
#include <cv.h>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

class FigureDetection{
private:

public:
    IplImage* get(IplImage*);
    void webCam(int);
};


#endif // FIGUREDETECTION_H
