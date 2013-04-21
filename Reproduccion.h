#ifndef REPRODUCCION_H
#define REPRODUCCION_H

#include <iostream>
#include <stdlib.h>
#include "Individuo.h"
#include "IConfiguracionParametros.h"

using namespace std;

class Reproduccion{

public:
    Reproduccion();     //constructor
    ~Reproduccion();    //destructor

    //***** METODOS DE CLASE *****
    Individuo *cruce( Individuo *pPadre, Individuo *pMadre, int pContador);
    void mutacion( Individuo *pIndividuo );
    void inversion( Individuo *pIndividuo );
    void fitness( Individuo *pIndividuo );

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
