#ifndef FIGUREDETECTION_H
#define FIGUREDETECTION_H

#include <highgui.h>
#include <cv.h>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include "SimpleList.h"
#include "SimpleList.cpp"
#include "figure.h"
#include <stdio.h>
#include <opencv2/opencv.hpp>

#include <math.h>


using namespace std;
using namespace cv;

/**
 * @brief The FigureDetection class
 *  Clase utilizada para detectar figuras dentro de una imagen o video
 */
class FigureDetection{

private:
    CvMemStorage* storage;//Memoria
    CvSeq* contour;//Contornos
    CvSeq* sec;//Lineas de figuras
    CvSeq* circles;
    IplImage *copyImage, *grayImage, *grayImage1;//Imagenes
    SimpleList<Figure*>* _list;

public:
    //Constructor
    FigureDetection();
    //Destructor
    ~FigureDetection();
    //Se obtiene la imagen identificando figuras
    IplImage* getImageFigure(IplImage*);
    //Se obtiene los contornos en una figura
    void getImageContour(IplImage*);
    //Se obtienen las lineas de una figura
    void getImageLines(IplImage*);
    //Web Cam
    void webCam(int);
    //Se imprimen y se obtienen las caracteristicas de figuras
    void printCharateristic(CvPoint**, int);
    //se imprimen datos de circulos
    void printcircles(int px,int py,int pradio);
    //Se obtiene la lista de figuras
    SimpleList<Figure*>* getListFigure();
};


#endif // FIGUREDETECTION_H
