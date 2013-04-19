#ifndef POBLACION_H
#define POBLACION_H

#include <iostream>
#include <cstdlib>
#include <QDebug>
#include "Individuo.h"

using namespace std;

class Poblacion{

public:
    Poblacion( int pPoblacionInicial );   //constructor
    ~Poblacion();                         //destructor

    void crearPoblacionInicial();           //crea la poblacion inicial de individuos
    void crearNuevaGeneracion();            //crea una nueva generacion de individuos
    void printPoblacion();                  //imprime la poblacion segun las generaciones


private:
    int _tamanoPoblacion;                   //tamaño de la poblacion
    double _probabilidadCruce;              //probabilidad de que hayan apareamientos
    double _probabilidadMutacion;           //probabilidad de que un cromosoma de individuo mute
    Individuo *_poblacion;                  //representa la poblacion de individuos
    int _contadorIndividuos;                //cantidad de individuos que han sido creados
    int _generacion;                        //generacion a la que pertenece una poblacion


};


#endif // POBLACION_H
