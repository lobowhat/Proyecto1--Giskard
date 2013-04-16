#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <iostream>

using namespace std;

class Individuo{

public:
    Individuo( int pId,unsigned short pCromosoma );     //Constructor
    ~Individuo();                                       //Destructor


//***** GETTERS Y SETTERS *****
    unsigned int getId();                               //Retorna el ID del individuo
    unsigned int  getGeneracion();                      //Retorna el numero de generacion
    void setGeneracion( unsigned int pGeneracion );     //Cambia el numero de generacion
    void printDatosIndividuo();                         //Imprime informacion acerca de un individuo
    void setSiguienteIndividuo( Individuo *pSiguienteIndividuo );
    Individuo* getSiguienteIndividuo();

private:
    unsigned short _cromosoma;      // cromosoma, un cromosoma esta formado por 32 genes
    int _id;                        // Identificador del individuo
    double _valorFitness;           // valor de su funcion de fitness
    Individuo *_siguienteIndividuo;          // siguiente individuo (lista simple de individuos)
    int _generacion;                // generacion a la que pertenece un individuo


};

#endif // INDIVIDUO_H
