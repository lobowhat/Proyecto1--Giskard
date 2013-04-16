#include "Individuo.h"

Individuo::Individuo( int pId, unsigned short pCromosoma )
{
    this->_id = pId;
    this->_cromosoma = pCromosoma;
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
 * @brief Individuo::printDatosIndividuo
 * Imprime los datos de un individuo
 */
void Individuo::printDatosIndividuo()
{
    cout << "Individuo ID: " << this->_id << " Generacion: " << this->_generacion << " Cromosoma: " << this->_cromosoma << endl;
}


Individuo::~Individuo(){}//destructor
