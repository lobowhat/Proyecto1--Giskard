#ifndef REPRODUCCION_H
#define REPRODUCCION_H

#include <iostream>

using namespace std;

class Reproduccion{

public:
    Reproduccion();     //constructor
    ~Reproduccion();    //destructor

    //***** METODOS DE CLASE *****
    //Individuo * cruce(Individuo *pPadre, Individuo *pMadre);
    //void Mutacion( Individuo * pIndividuo );
    //void Inversion( Individuo * pIndividuo );
    //void fitness( Individuo * pIndividuo );

    //***** GETTERS Y SETTERS *****

private:
    double _probabilidadMutacion;
    double _probabilidadInvertir;

};  //fin de la clase

#endif // REPRODUCCION_H
