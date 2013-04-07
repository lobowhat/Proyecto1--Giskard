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
    IplImage *_imagenGuardada;      //imagen guardada en la computadora
    CvCapture *_capturaCamara;      //imagen desde la computadora
    int _filas;                     //delimita el tamaño de la celda
    int _columnas;                  //delimita el tamaño de la celda
    int ***_ptrMatriz;              //puntero a una matriz3D

public:
    ReconstruccionImagenes();//constructor
    ~ReconstruccionImagenes();//destructor
//***** GETTERS Y SETTERS *****
    IplImage* getImagenGuardada();                              //Se obtiene imagen guardada
    IplImage* getImagenCapturada();                             //Se obtiene imagen capturada desde camara
    void setImagenGuardada(IplImage *_pImagenGuardada);         //cambia imagen guardada
    void setImagenCapturada(IplImage *_pImagenCapturada);       //cambia imagen capturada desde camara
//***** METODOS DE CLASE *****
    void recibeImagenGuardada(char* pPathImagenGuardada);       //recibe imagen desde un path
    void recibeImagenCapturada();                               //recibe imagen desde la cámara de video
    void muestraImagen(IplImage *pImagenAMostrar);              //muestra la imagen en pantalla
    void crearMatrizColores(int pFila, int pColumna);           //crea matriz 3D donde se guardarán los valores RGB
    void agregaPixelesAMatriz();                                //agrega los pixeles de la imagen a la matriz
    int getPixeles(IplImage *pImagen, int pI, int pJ, int pK);  //obtiene los pixeles de una imagen
    void imprimeMatriz();                                       //imprime la matriz 3D
    void initReconstruccionImagen();                            //inicia la reconstrucción de la imagen


};//fin de la clase

#endif // RECONSTRUCCIONIMAGENES_H
