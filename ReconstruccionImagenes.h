#ifndef RECONSTRUCCIONIMAGENES_H
#define RECONSTRUCCIONIMAGENES_H

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>

using namespace std;
using namespace cv;

class ReconstruccionImagenes{

private:
    IplImage *_imagenGuardada;              //imagen guardada en la computadora
    CvCapture *_capturaCamara;      //imagen desde la computadora

public:
    ReconstruccionImagenes();//constructor
    ~ReconstruccionImagenes();//destructor
//***** GETTERS Y SETTERS *****
    IplImage* getImagenGuardada();
    IplImage* getImagenCapturada();
    void setImagenGuardada(IplImage *_pImagenGuardada);
    void setImagenCapturada(IplImage *_pImagenCapturada);
//***** METODOS DE CLASE *****
    void recibeImagenGuardada(char* pPathImagenGuardada);
    void recibeImagenCapturada();
    void muestraImagen(IplImage *pImagenAMostrar);


};//fin de la clase

#endif // RECONSTRUCCIONIMAGENES_H
