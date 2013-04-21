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
//    unsigned short _puntoCruce1R;                                     // 0 - 3    division primera parte de las ristra para el valor R
//    unsigned short _puntoCruce1G;                                     // 8 - 11   division primera parte de las ristra para el valor G
//    unsigned short _puntoCruce1B;                                     // 16 - 19  division primera parte de las ristra para el valor B
//    unsigned short _puntoCruce2R;                                     // 4 - 7    division segunda parte de las ristra para el valor R
//    unsigned short _puntoCruce2G;                                     // 12 - 15  division segunda parte de las ristra para el valor G
//    unsigned short _puntoCruce2B;                                     // 20 - 23  division segunda parte de las ristra para el valor B


};  //fin de la clase

#endif // REPRODUCCION_H
