#ifndef RECONSTRUCCIONIMAGENES_H
#define RECONSTRUCCIONIMAGENES_H

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "IConfiguracionParametros.h"
#include <cv.h>
#include <highgui.h>

using namespace std;
using namespace cv;

class ReconstruccionImagenes{

private:
    IplImage *_imagenGuardada;      //imagen guardada en la computadora
    CvCapture *_capturaCamara;      //imagen desde la computadora
    int _filas;                     //delimita el tamaño de la celda
    int _columnas;                  //delimita el tamaño de la celda
    int ***_ptrMatriz;              //puntero a una matriz3D
    Mat _espacioBorradoImagen;      //espacio borrado de la imagen que hay que reconstruir
    short _filaInicial;             //valor minimo en filas(x) para la region borrada
    short _filaFinal;               //valor maximo en filas(x) para la region borrada
    short _columnaInicial;          //valor minimo en columnas(y) para la region borrada
    short _columnaFinal;            //valor maximo en columnas(y) para la region borrada


public:
    ReconstruccionImagenes();//constructor
    ~ReconstruccionImagenes();//destructor
//***** GETTERS Y SETTERS *****
    IplImage* getImagenGuardada();                              //Se obtiene imagen guardada
    IplImage* getImagenCapturada();                             //Se obtiene imagen capturada desde camara
    void setImagenGuardada(IplImage *_pImagenGuardada);         //cambia imagen guardada
    void setImagenCapturada(IplImage *_pImagenCapturada);       //cambia imagen capturada desde camara
    int getFilaInicial();                                     //obtiene fila inicial del espacio borrado
    int getFilaFinal();                                       //obtiene fila final del espacio borrado
    void setFilaInicial( int pFilaInicial );                     //cambia fila inicial del espacio borrado
    void setFilaFinal( int pFilaFinal );                         //cambia fila final del espacio borrado
    int getColumnaInicial();                                  //obtiene columna inicial del espacio borrado
    int getColumnaFinal();                                    //obtiene columna final del espacio borrado
    void setColumnaInicial( int pColumnaInicial );               //cambia columna inicial del espacio borrado
    void setColumnaFinal( int pColumnaFinal );                   //cambia columna final del espacio borrado

//***** METODOS DE CLASE *****
    void recibeImagenGuardada(char* pPathImagenGuardada);       //recibe imagen desde un path
    void recibeImagenCapturada();                               //recibe imagen desde la cámara de video
    void muestraImagen(IplImage *pImagenAMostrar);              //muestra la imagen en pantalla
    void crearMatrizColores(int pFila, int pColumna);           //crea matriz 3D donde se guardarán los valores RGB
    void agregaPixelesAMatriz();                                //agrega los pixeles de la imagen a la matriz
    int getPixeles(IplImage *pImagen, int pI, int pJ, int pK);  //obtiene los pixeles de una imagen
    void imprimeMatriz();                                       //imprime la matriz 3D
    void initReconstruccionImagen();                            //inicia la reconstrucción de la imagen
    void creaImagenReconstruida();                              //crea la imagen ya reconstruida desde la matriz 3D
    void detectarEspacioBorrado( IplImage* pImagen );           //detecta el espacio barrado en la imagen (color rojo)
    void muestraLimitesEspacioBorrado();                        //imprime las coordenadas xy del espacio borrado

};//fin de la clase

#endif // RECONSTRUCCIONIMAGENES_H
