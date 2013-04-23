#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <iostream>
#include <stdlib.h>
#include <QDebug>

using namespace std;

class Individuo{

public:
    Individuo( int pId );                                               // Constructor
    ~Individuo();                                                       // Destructor

    //***** GETTERS Y SETTERS *****
    unsigned int getId();                                               // Retorna el ID del individuo
    void setId( unsigned int pId );                                     // Cambia el ID del individuo
    unsigned int  getGeneracion();                                      // Retorna el numero de generacion
    void setGeneracion( unsigned int pGeneracion );                     // Cambia el numero de generacion
    void printDatosIndividuo();                                         // Imprime informacion acerca de un individuo
    void setSiguienteIndividuo( Individuo *pSiguienteIndividuo );       // Cambia el siguiente individuo (Lista Simple)
    Individuo *getSiguienteIndividuo();                                 // Obtiene el siguiente individuo (Lista Simple)
    unsigned short getR_RGB();
    unsigned short getG_RGB();
    unsigned short getB_RGB();
    void setR_RGB( unsigned short pR );
    void setG_RGB( unsigned short pG );
    void setB_RGB( unsigned short pB );
    unsigned short *getCromosoma();                                     // Obtiene el arreglo cromosoma del individuo
    void setCromosoma( unsigned short *pCromosoma );                    // Cambia el arreglo cromosoma del individuo
    int getValorFitness();                                              // Obtiene el valor fitness del individuo
    int setValorFitness( int pValorFitness );                           // Cambia el valor fitness del individuo
    bool getIndividuoSeleccionado();                                    // Obtiene si el individuo ha sido seleccionado
    void setIndividuoSeleccionado( bool pIndividuoSeleccionado );       // Cambia si el individuo ha sido seleccionado
    int getPadre();                                                     // Obtiene el ID del padre del individuo
    void setPadre( int pPadre );                                        // Cambia el padre del individuo
    int getMadre();                                                     // Obtiene el ID del madre del individuo
    void setMadre( int pMadre );                                        // Cambia la madre del individuo

    //***** METODOS DE CLASE *****


private:
    int _id;                                    // Identificador del individuo
    Individuo *_siguienteIndividuo;             // siguiente individuo (lista simple de individuos)
    int _generacion;                            // generacion a la que pertenece un individuo
    unsigned short _r;                          // valor de color R en codigo decimal (RGB)
    unsigned short _b;                          // valor de color G en codigo decimal (RGB)
    unsigned short _g;                          // valor de color B en codigo decimal (RGB)
    unsigned short *_cromosoma;                 // Arreglo que contiene los valores RGB del individuo
    int _valorFitness;                          // valor Fitness del individuo
    bool _individuoSeleccionado;                // si es seleccionado para la seleccion natural
    int _padre;                                 // padre del individuo
    int _madre;                                 // madre del individuo

};

#endif // INDIVIDUO_H
