#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <iostream>
#include <QDebug>

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
    unsigned short getR_RGB();
    unsigned short getG_RGB();
    unsigned short getB_RGB();
    void setR_RGB( unsigned short pR );
    void setG_RGB( unsigned short pG );
    void setB_RGB( unsigned short pB );

private:
    unsigned short _cromosoma;                  // cromosoma, un cromosoma esta formado por 32 genes
    int _id;                                    // Identificador del individuo
    double _valorFitness;                       // valor de su funcion de fitness
    Individuo *_siguienteIndividuo;             // siguiente individuo (lista simple de individuos)
    int _generacion;                            // generacion a la que pertenece un individuo
    unsigned short _r;                          // valor de color R en codigo decimal (RGB)
    unsigned short _b;                          // valor de color G en codigo decimal (RGB)
    unsigned short _g;                          // valor de color B en codigo decimal (RGB)


};

#endif // INDIVIDUO_H
