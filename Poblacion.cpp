#include "Poblacion.h"

Poblacion::Poblacion()
{
    this->_tamanoPoblacion = IConfiguracionParametros::TAMANO_POBLACION;
    this->_probabilidadCruce = IConfiguracionParametros::PROBABILIDAD_CRUCE;//1 * 100 = 100% debe tomar valores desde 0.5 hasta 1
    this->_contadorIndividuos = 1;
}//constructor

/**
 * @brief Poblacion::crearPoblacionInicial
 * Crea una poblacion con una cantidad n de Individuos
 */
void Poblacion::crearPoblacionInicial()
{
    this->_poblacion = new Individuo(this->_contadorIndividuos);     //individuo inicial(MATUZALEM)
    for(int i = 0; i < this->_tamanoPoblacion - 1; i++){
        this->_contadorIndividuos++;                                    //lleva la cuenta de la cantidad de individuos
        Individuo *tmp = new Individuo(this->_contadorIndividuos);   //se crea otro individuo
        tmp->setSiguienteIndividuo(this->_poblacion);                   //se agrega otro individuo a la lista simple
        this->_poblacion = tmp;
    }//fin del for
}

/**
 * @brief Poblacion::printPoblacion
 * Imprime la poblacion actual segun las generaciones
 */
void Poblacion::printPoblacion()
{
    qDebug() << "---------------- Imprimiendo Poblacion ----------------" << "Generacion # " << this->_generacion << endl;
    //cout << "Generacion # "<< this->_generacion << endl;    //numero de la generacion poblacional
    Individuo * tmp = this->_poblacion;                     //inicia a revisar la poblacion(cantidad de individuos)
    while( tmp != NULL ){
        tmp->printDatosIndividuo();
        tmp = tmp->getSiguienteIndividuo();
    }//fin del while
}

/**
 * @brief Poblacion::seleccionIndividuos
 * Retorna un Individuo
 * @return tmp; individuo
 */
Individuo *Poblacion::seleccionIndividuos()
{
    int fitnessTotal = 0;               //this->getSumatoriaFitness();
    Individuo *tmp = this->_poblacion;
    while( tmp != NULL ){
        if( tmp->getIndividuoSeleccionado() == false && fitnessTotal == tmp->getValorFitness() ){
            tmp->setIndividuoSeleccionado( true );                  //Individuo ha sido seleccionado, no volverá a ser escogido
            break;
        }//fin del if

        tmp = tmp->getSiguienteIndividuo();
    }//fin del while
    return tmp;
}

/**
 * @brief Poblacion::getMejorIndividuo
 * Retorna al mejor Individuo
 * @return mejorIndividuo
 */
Individuo *Poblacion::getMejorIndividuo()
{
    Individuo *tmp = this->_poblacion;
    Individuo *mejorIndividuo = tmp;
    while ( tmp != NULL ){
        if( mejorIndividuo->getValorFitness() < tmp->getValorFitness() ){
            mejorIndividuo = tmp;
        }
        tmp = tmp->getSiguienteIndividuo();
    }
    qDebug() << "El mejor individuo es: " << endl;
    mejorIndividuo->printDatosIndividuo();
    return mejorIndividuo;
}

/**
 * @brief Poblacion::getPeorIndividuo
 * Retorna al peorIndividuo
 * @return peorIndividuo
 */
Individuo *Poblacion::getPeorIndividuo()
{
    Individuo *tmp = this->_poblacion;
    Individuo *peorIndividuo = tmp;
    while ( tmp != NULL ){
        if( peorIndividuo->getValorFitness() > tmp->getValorFitness() ){
            peorIndividuo = tmp;
        }
        tmp = tmp->getSiguienteIndividuo();
    }
    qDebug() << "El peor individuo es: " << endl;
    peorIndividuo->printDatosIndividuo();
    return peorIndividuo;
}

Poblacion::~Poblacion(){}//destructor

