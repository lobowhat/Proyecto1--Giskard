#include "AlgoritmoGenetico.h"

/**
 * @brief AlgoritmoGenetico::AlgoritmoGenetico
 * @param pValorR
 * @param pValorG
 * @param pValorB
 */
AlgoritmoGenetico::AlgoritmoGenetico( unsigned short pArea, unsigned short pValorR,
                                      unsigned short pValorG, unsigned short pValorB )
{
    this->_poblacion = new Poblacion();
    this->_valorR = pValorR;
    this->_valorG = pValorG;
    this->_valorB = pValorB;
    this->_area = pArea;
    this->_promedioFitnessPixel = ( _valorR + _valorG + _valorB ) / 3;
//    this->_poblacion->setTamanhoPoblacion( IConfiguracionParametros::TAMANO_POBLACION );
    this->_poblacion->setTamanhoPoblacion( _area );
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
    for( unsigned short i = 0; i < IConfiguracionParametros::MAX_GENERACIONES; i++ ){
        this->_poblacion->crearNuevaGeneracion();
        this->_poblacion->printPoblacion();
    }
}

/**
 * @brief AlgoritmoGenetico::getValoresRGB
 * Devuelve un arreglo con los valores RGB
 * @param pCantidadIndividuos
 * @return _arregloMejoresIndividuos
 */
unsigned short *AlgoritmoGenetico::getValoresRGB()
{
    this->_arregloMejoresIndividuos = this->_poblacion->mejoresIndividuos(_area);
    return _arregloMejoresIndividuos;
}

AlgoritmoGenetico::~AlgoritmoGenetico()
{
}

