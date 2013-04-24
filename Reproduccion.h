#ifndef REPRODUCCION_H
#define REPRODUCCION_H

#include <iostream>
#include <stdlib.h>
#include "Individuo.h"
#include "IConfiguracionParametros.h"


using namespace std;

class Reproduccion{

public:
    Reproduccion();                                                     // Constructor
    ~Reproduccion();                                                    // Destructor

    //***** METODOS DE CLASE *****
    Individuo *cruce( Individuo *pPadre, Individuo *pMadre, int pContador); // genera el cruce entre 2 individuos
    void mutacion( Individuo *pIndividuo );                                 // muta el cromosoma del individuo
    void inversion( Individuo *pIndividuo );                                // invierte el cromosoma del individuo
    void fitness( Individuo *pIndividuo );                                  // funcion fitness

    //***** GETTERS Y SETTERS *****
    int getProbabilidadMutacion();                                      // obtiene la probabilidad de mutacion
    void setProbabilidadMutacion( int pProbabilidadMutacion );          // cambia la probabilidad de mutacion
    int getProbabilidadInvertir();                                      // obtiene la probabilidad de inversion
    void setProbabilidadInvertir( int pProbabilidadInvertir );          // cambia la probabilidad de inversion

private:
    int _probabilidadMutacion;                                          // probabilidad de mutacion
    int _probabilidadInvertir;                                          // probabilidad de inversion

};  //fin de la clase

#endif // REPRODUCCION_H
