#ifndef ALGORITMOGENETICO_H
#define ALGORITMOGENETICO_H

#include <iostream>
#include "Poblacion.h"

using namespace std;

class AlgoritmoGenetico{

public:
    AlgoritmoGenetico( int pValorR, int pValorG, int pValorB  );        // Constructor
    ~AlgoritmoGenetico();                                               // Destructor

    void initAlgoritmoGenetico();           // Inicializa el Algoritmo Genético

private:
    int _valorR;                            // Valor de R (colores RGB)
    int _valorG;                            // Valor de G (colores RGB)
    int _valorB;                            // Valor de B (colores RGB)
    int _promedioFitnessPixel;              // Promedio Fitness del Pixel
    Poblacion *_poblacion;                  // Poblacion para inicializar el genetico

};

#endif // ALGORITMOGENETICO_H
