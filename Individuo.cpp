#include "Individuo.h"

Individuo::Individuo(int pId)
/*    : _id(pId),
      _r(rand() % 255),
      _g(rand() % 255),
      _b(rand() % 255),
      _chromosome(new Chromosome()),
      _cromosoma(_chromosome->convertToArray(_r, _g, _b)),
      _valorFitness(0),
      _individuoSeleccionado(false),
      _padre(-1),                           // No hay padre
      _madre(-1)*/                           // No hay
{
    this->_id = pId;
    this->_individuoSeleccionado = false;
    this->_r = rand() % 255;                    //Parte del cromosoma
    this->_g = rand() % 255;                    //Parte del cromosoma
    this->_b = rand() % 255;                    //Parte del cromosoma
    //srand (time(NULL));                       // reinicia el random//ARREGLAR EL RANDOM
    this->_chromosome = new Chromosome();
    this->_cromosoma = this->_chromosome->convertToArray(_r, _g, _b);  // se crea el arreglo que contendrá los valores RGB
    this->_valorFitness = 0;
    this->_padre = -1;                          // No hay padre
    this->_madre = -1;                       // No hay
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
void Individuo::setGeneracion(unsigned int pGeneracion)
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
 * @brief Individuo::setId
 * Cambia el ID del individuo
 * @param pId
 */
void Individuo::setId(unsigned int pId)
{
    this->_id = pId;
}

/**
 * @brief Individuo::setSiguienteIndividuo
 * Cambia al siguiente Individuo de uno actual
 * @param pSiguienteIndividuo
 */
void Individuo::setSiguienteIndividuo(Individuo *pSiguienteIndividuo)
{
    this->_siguienteIndividuo = pSiguienteIndividuo;
}

/**
 * @brief Individuo::getSiguienteIndividuo
 * Cambia al siguiente Individuo de uno actual
 * @return _siguienteIndividuo
 */
Individuo* Individuo::getSiguienteIndividuo()
{
    return this->_siguienteIndividuo;
}

/**
 * @brief Individuo::getR_RGB
 * @return el valor r
 */
unsigned short Individuo::getR_RGB()
{
    return _r;//_cromosoma[0]
}

/**
 * @brief Individuo::getG_RGB
 * @return el valor g
 */
unsigned short Individuo::getG_RGB()
{
    return _g;//_cromosoma[1]
}

/**
 * @brief Individuo::getB_RGB
 * @return el valor b
 */
unsigned short Individuo::getB_RGB()
{
    return _b;//_cromosoma[2]
}

/**
 * @brief Individuo::setR_RGB
 * Cambia el valor R
 * @param pR
 */
void Individuo::setR_RGB(unsigned short pR)
{
    this->_r = pR; //this->_cromosoma[0] = pR
}

/**
 * @brief Individuo::setG_RGB
 * Cambia el valor G
 * @param pG
 */
void Individuo::setG_RGB(unsigned short pG)
{
    this->_g = pG;  //this->_cromosoma[1] = pG
}

/**
 * @brief Individuo::setB_RGB
 * Cambia el valor B
 * @param pB
 */
void Individuo::setB_RGB(unsigned short pB)
{
    this->_b = pB;  //this->_cromosoma[2] = pB
}

/**
 * @brief Individuo::getCromosoma
 * Retorna el arreglo que contiene el cromosoma (RGB)
 * @return _cromosoma
 */
unsigned short *Individuo::getCromosoma()
{
    return _cromosoma;
}

/**
 * @brief Individuo::setCromosoma
 * Cambia el cromosoma del individuo
 * @param pCromosoma
 */
void Individuo::setCromosoma(unsigned short *pCromosoma)
{
    this->_cromosoma = pCromosoma;
}

/**
 * @brief Individuo::getValorFitness
 * Obtiene el valor fitness del individuo
 * @return _valorFitness
 */
int Individuo::getValorFitness()
{
    return _valorFitness;
}

/**
 * @brief Individuo::setValorFitness
 * @param pValorFitness
 * Cambia el valor fitness del individuo
 */
void Individuo::setValorFitness(int pValorFitness)
{
    this->_valorFitness = pValorFitness;
}

/**
 * @brief Individuo::getIndividuoSeleccionado
 * Obtiene si el individuo ha sido seleccionado
 * @return _individuoSeleccionado
 */
bool Individuo::getIndividuoSeleccionado()
{
    return _individuoSeleccionado;
}

/**
 * @brief Individuo::setIndividuoSeleccionado
 * Cambia si el individuo ha sido seleccionado
 * @param pIndividuoSeleccionado
 */
void Individuo::setIndividuoSeleccionado(bool pIndividuoSeleccionado)
{
    this->_individuoSeleccionado = pIndividuoSeleccionado;
}

/**
 * @brief Individuo::getPadre
 * Obtiene el ID del padre del individuo
 * @return _padre
 */
int Individuo::getPadre()
{
    return _padre;
}

/**
 * @brief Individuo::setPadre
 * Cambia el ID del padre del individuo
 * @param pPadre
 */
void Individuo::setPadre(int pPadre)
{
    this->_padre = pPadre;
}

/**
 * @brief Individuo::getMadre
 * Obtiene el ID del madre del individuo
 * @return _madre
 */
int Individuo::getMadre()
{
    return _madre;
}

/**
 * @brief Individuo::setMadre
 * Cambia el ID del madre del individuo
 * @param pMadre
 */
void Individuo::setMadre(int pMadre)
{
    this->_madre = pMadre;
}

Chromosome *Individuo::getChromosome()
{
    return _chromosome;
}


/**
 * @brief Individuo::printDatosIndividuo
 * Imprime los datos de un individuo
 */
void Individuo::printDatosIndividuo()
{
    qDebug() << "Individuo ID: " << this->_id << "Padre: " << this->_padre << "Madre: " << this->_madre
             << " Generacion: " << this->_generacion << " RGB: "
             << "( " << this->_r << ", " << this->_g << ", " << this->_b << " )"
             //<< " Cromosoma: " << _chromosome->printChromosome()
             << "Fitness: " << this->_valorFitness << endl;
}


Individuo::~Individuo() {} //destructor

