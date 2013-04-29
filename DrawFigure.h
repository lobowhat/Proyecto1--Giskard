#ifndef DRAWFIGURE_H
#define DRAWFIGURE_H

#include <opencv2/opencv.hpp>

class DrawFigure
{
private:
    IplImage* _image;
    CvScalar _color;

public:
    //Constructor
    DrawFigure(IplImage *pImage);
    //Destructor
    ~DrawFigure();
    //Dibujar cudrilatero
    void drawQuadrilater(int, int, int, int);
    //Dibujar triangulo
    void drawTriangule(int, int, int, int);
    //Dibujar circulo
    void drawCircule(int, int, int);
    //Dibuja una linea
    void drawLine(int, int, int);
};

#endif // DRAWFIGURE_H
