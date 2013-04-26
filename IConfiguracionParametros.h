#ifndef ICONFIGURACIONPARAMETROS_H
#define ICONFIGURACIONPARAMETROS_H

#include <iostream>

using namespace std;

/**
 *  En esta clase se inicializan variables que pueden ser constantes en el programa
 *  a manera de que si se modifican, se haga el cambio desde esta HEADER para no tener
 *  que ir a buscar el parametro en X clase
 * @brief The IConfiguracionParametros class
 */

class IConfiguracionParametros{

public:

    //***** DIRECCION DE LA IMAGEN EN LA COMPUTADORA *****
//    static const char* PATHFILE_IMAGEN = "/home/darayavilla/Qt_projects/lobowhat-Proyecto1--Giskard/raya1.jpg";

    //***** RANGO MINIMO PARA LA DETECCION DE COLOR RGB DEL ESPACIO BORRADO *****
    static const int R_MINIMO = 253;        //R valor minimo
    static const int G_MINIMO = 0;          //G valor minimo
    static const int B_MINIMO = 0;          //B valor minimo

    //***** RANGO MAXIMO PARA LA DETECCION DE COLOR RGB DEL ESPACIO BORRADO *****
    static const int R_MAXIMO = 255;        //R valor maximo
    static const int G_MAXIMO = 0;          //G valor maximo
    static const int B_MAXIMO = 0;          //B valor maximo

    //***** SECCION DE PIXELES ******
    static const int SECCION_FILA = 5;      //tamaño de pixeles por filas
    static const int SECCION_COLUMNA = 5;   //tamaño de pixeles por columnas

    //***** DATOS PARA EL ALGORITMO GENÉTICO ******
    static const int TAMANO_POBLACION = 6;                      // tamaño inicial de la poblacion
    static const int PROBABILIDAD_INVERSION = 6;                // 10%
    static const int PROBABILIDAD_MUTACION = 2;                 // 10%

    static const int PROBABILIDAD_CRUCE = 10;                  // 10 se reprocucen todos
    static const int PROBABILIDAD_NACIMIENTO = 4;               // 50%
    static const int MAX_NACIMIENTOS = 3;                       // maxima cantidad de nacimientos por generacion



};

#endif // ICONFIGURACIONPARAMETROS_H
