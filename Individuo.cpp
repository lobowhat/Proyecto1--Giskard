#include "Individuo.h"

Individuo::Individuo( int pId, unsigned short pCromosoma )
{
    this->_id = pId;
    this->_cromosoma = pCromosoma;
    this->_r = rand() % 255;
    this->_g = rand() % 255;
    this->_b = rand() % 255;
}//constructor

/**
 * @brief Individuo::getGeneracion
 * Retorna el numero de la generacion de un Individuo
 */
unsigned int Individuo::getGeneracion()
{
   return this->_generacion;
}

/**
 * @brief Individuo::setGeneracion
 * Cambia el numero de la generacion de un Individuo
 * @param pGeneracion
 */
void Individuo::setGeneracion( unsigned int pGeneracion )
{
    this->_generacion = pGeneracion;
}

/**
 * @brief Individuo::getId
 *  Retorna el numero de identificacion de un Individuo
 */
unsigned int Individuo::getId()
{
    return this->_id;
}

/**
 * @brief Individuo::setSiguienteIndividuo
 * Cambia al siguiente Individuo de uno actual
 * @param pSiguienteIndividuo
 */
void Individuo::setSiguienteIndividuo(Individuo *pSiguienteIndividuo){
    this->_siguienteIndividuo = pSiguienteIndividuo;
}

/**
 * @brief Individuo::getSiguienteIndividuo
 * Cambia al siguiente Individuo de uno actual
 * @return _siguienteIndividuo
 */
Individuo* Individuo::getSiguienteIndividuo(){
    return this->_siguienteIndividuo;
}

/**
 * @brief Individuo::getR_RGB
 * @return el valor r
 */
unsigned short Individuo::getR_RGB()
{
    return _r;
}

/**
 * @brief Individuo::getG_RGB
 * @return el valor g
 */
unsigned short Individuo::getG_RGB()
{
    return _g;
}

/**
 * @brief Individuo::getB_RGB
 * @return el valor b
 */
unsigned short Individuo::getB_RGB()
{
    return _b;
}

/**
 * @brief Individuo::setR_RGB
 * Cambia el valor R
 * @param pR
 */
void Individuo::setR_RGB(unsigned short pR)
{
    this->_r = pR;
}

/**
 * @brief Individuo::setG_RGB
 * Cambia el valor G
 * @param pG
 */
void Individuo::setG_RGB(unsigned short pG)
{
    this->_g = pG;
}

/**
 * @brief Individuo::setB_RGB
 * Cambia el valor B
 * @param pB
 */
void Individuo::setB_RGB(unsigned short pB)
{
    this->_b = pB;
}

/**
 * @brief Individuo::printDatosIndividuo
 * Imprime los datos de un individuo
 */
void Individuo::printDatosIndividuo()
{
    qDebug() << "Individuo ID: " << this->_id << " Generacion: " << this->_generacion << " RGB: "
             << "( " << this->_r << ", " << this->_g << ", " << this->_b << " )"
             << " Cromosoma: " << this->_cromosoma << endl;
}


Individuo::~Individuo(){}//destructor
