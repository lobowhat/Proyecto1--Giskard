#ifndef POBLACION_H
#define POBLACION_H

#include <iostream>
#include <cstdlib>
#include <QDebug>
#include "Individuo.h"
#include "Reproduccion.h"
#include "IConfiguracionParametros.h"

using namespace std;

class Poblacion{

public:
    Poblacion();                            // Constructor
    ~Poblacion();                           // Destructor
    //***** METODOS DE CLASE *****
    void crearPoblacionInicial();                                  // crea la poblacion inicial de individuos
    void crearNuevaGeneracion();                                   // crea una nueva generacion de individuos
    void printPoblacion();                                         // imprime la poblacion segun las generaciones
    Individuo *seleccionIndividuos();                              // selecciona un individuo de la poblacion
    Individuo *getMejorIndividuo( Individuo *pPoblacion );         // obtiene mejor individuo de la poblacion
    Individuo *getPeorIndividuo( Individuo *pPoblacion );          // obtiene peor individuo de la poblacion
    void mezclarPoblacion( Individuo *pNuevaGeneracion );          // Mezcla la poblacion actual con la nueva generacion
    void cambiarIndividuos( Individuo *pIndividuo1, Individuo *pIndividuo2 ); // cambia individuos entre generaciones
    void cambiaValorIndividuoSeleccionado();                        // setea el atributo para poder ser seleccionado en cruce
    void aplicarFitness();                                          // Aplica el fitness
    void setValorFitnessPixelEscogido( int pValorFitnessPixel );    // cambia el Valor Fitness del Pixel Escogido
    int getValorFitnessPixelEscogido();                             // obtiene el Valor Fitness del Pixel Escogido
    void imprimeNuevaGeneracion(Individuo *p);      //BORRAR METODO!!!!
    //Obtiene una lista con una cantidad de mejores Individuos
    unsigned short *mejoresIndividuos( unsigned short pCantidadIndividuos );

private:
    int _tamanoPoblacion;                   // tamaño de la poblacion inicial
    int _probabilidadCruce;                 // probabilidad de que hayan apareamientos
    Individuo *_poblacion;                  // representa la poblacion de individuos
    int _contadorIndividuos;                // cantidad de individuos que han sido creados
    int _generacion;                        // generacion a la que pertenece una poblacion
    int _probabilidadNacimiento;            // probabilidad de nacimientos
    int _maxCantidadNacimientos;            // cantidad máxima de nacimientos
    Reproduccion *_reproduccion;            // reproduccion de los individuos
    int _valorFitnessPixel;                 // valor fitness (RGB)
    Individuo *_mejoresIndividuosFinal;     // lista con los mejores individuos de todos los tiempos
    unsigned short *_individuosSeleccionados;   // individuos seleccionados para ser pixeles

};


#endif // POBLACION_H
