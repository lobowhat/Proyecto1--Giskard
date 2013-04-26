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
    //cout << "Valor del PIXEL: " << _poblacion->getValorFitnessPixelEscogido() << endl;
    this->_poblacion->crearPoblacionInicial();
    this->_poblacion->printPoblacion();
    this->_poblacion->crearNuevaGeneracion();
    this->_poblacion->printPoblacion();
}

/**
 * @brief AlgoritmoGenetico::getValoresRGB
 * Devuelve un arreglo con los valores RGB
 * @param pCantidadIndividuos
 * @return _arregloMejoresIndividuos
 */
unsigned short *AlgoritmoGenetico::getValoresRGB(unsigned short pCantidadIndividuos)
{
    this->_arregloMejoresIndividuos = this->_poblacion->mejoresIndividuos(pCantidadIndividuos);
    return _arregloMejoresIndividuos;
}

AlgoritmoGenetico::~AlgoritmoGenetico()
{
}

