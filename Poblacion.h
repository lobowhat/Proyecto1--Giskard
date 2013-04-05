#ifndef POBLACION_H
#define POBLACION_H

#include <iostream>

using namespace std;

class Poblacion{

public:
    Poblacion(int pPoblacionInicial);//constructor
    ~Poblacion();//destructor

private:
    int _tamanoPoblacion;
    double _probabilidadCruce;
    double _probabilidadMutacion;

};


#endif // POBLACION_H
