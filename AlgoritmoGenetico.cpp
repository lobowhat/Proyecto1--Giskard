#include "AlgoritmoGenetico.h"

/**
 * @brief AlgoritmoGenetico::AlgoritmoGenetico
 * @param pValorR
 * @param pValorG
 * @param pValorB
 */
AlgoritmoGenetico::AlgoritmoGenetico( int pValorR, int pValorG, int pValorB )
{
    this->_poblacion = new Poblacion();
    this->_valorR = pValorR;
    this->_valorG = pValorG;
    this->_valorB = pValorB;
    this->_promedioFitnessPixel = ( _valorR + _valorG + _valorB ) / 3;
}


/**
 * @brief AlgoritmoGenetico::initAlgoritmoGenetico
 * Inicializará el Algoritmo Genetico
 */
void AlgoritmoGenetico::initAlgoritmoGenetico()
{
    this->_poblacion->setValorFitnessPixelEscogido( _promedioFitnessPixel );
    this->_poblacion->crearPoblacionInicial();
    this->_poblacion->printPoblacion();
    this->_poblacion->crearNuevaGeneracion();
    this->_poblacion->printPoblacion();
}

AlgoritmoGenetico::~AlgoritmoGenetico()
{
}

