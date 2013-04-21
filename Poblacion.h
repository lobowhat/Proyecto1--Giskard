#ifndef POBLACION_H
#define POBLACION_H

#include <iostream>
#include <cstdlib>
#include <QDebug>
#include "Individuo.h"
#include "Reproduccion.h"

using namespace std;

class Poblacion{

public:
    Poblacion( int pPoblacionInicial );   //constructor
    ~Poblacion();                         //destructor

    //***** METODOS DE CLASE *****
    void crearPoblacionInicial();           // crea la poblacion inicial de individuos
    void crearNuevaGeneracion();            // crea una nueva generacion de individuos
    void printPoblacion();                  // imprime la poblacion segun las generaciones
    void generarNuevaPoblacion();           // genera una nueva generacion
    Individuo *seleccionIndividuos();       // selecciona un individuo de la poblacion
    Individuo *getMejorIndividuo();         // obtiene mejor individuo de la poblacion
    Individuo *getPeorIndividuo();          // obtiene peor individuo de la poblacion


private:
    int _tamanoPoblacion;                   // tamaño de la poblacion
    double _probabilidadCruce;              // probabilidad de que hayan apareamientos
    double _probabilidadMutacion;           // probabilidad de que un cromosoma de individuo mute
    Individuo *_poblacion;                  // representa la poblacion de individuos
    int _contadorIndividuos;                // cantidad de individuos que han sido creados
    int _generacion;                        // generacion a la que pertenece una poblacion
    int _probabilidadNacimiento;            // probabilidad de nacimientos
    int _maxCantidadNacimientos;            // cantidad máxima de nacimientos


};


#endif // POBLACION_H
