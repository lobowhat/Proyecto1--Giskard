#include "Poblacion.h"

Poblacion::Poblacion(int pPoblacionInicial)
{
    this->_tamanoPoblacion = pPoblacionInicial;
    this->_probabilidadCruce = 1.0;//1 * 100 = 100% debe tomar valores desde 0.5 hasta 1
    this->_probabilidadMutacion = 0.5;//50% ###se recomienda: utilizacion de una probabilidad
    //de mutacion del bit de l−1 , siendo l la longitud del string.

}//constructor

Poblacion::~Poblacion(){}//destructor
