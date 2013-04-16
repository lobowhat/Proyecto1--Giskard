#include "Poblacion.h"

Poblacion::Poblacion(int pPoblacionInicial)
{
    this->_tamanoPoblacion = pPoblacionInicial;
    this->_probabilidadCruce = 1.0;                         //1 * 100 = 100% debe tomar valores desde 0.5 hasta 1
    this->_probabilidadMutacion = 0.5;                      /*50% ###se recomienda: utilizacion de una probabilidad
                                                            de mutacion del bit de l−1 , siendo l la longitud del string.*/
}//constructor

/**
 * @brief Poblacion::crearPoblacionInicial
 * Crea una poblacion con una cantidad n de Individuos
 */
void Poblacion::crearPoblacionInicial()
{
    cout << "Creando poblacion inicial de " << this->_tamanoPoblacion << endl;
    this->_poblacion = new Individuo(this->_contadorIndividuos, 0);     //individuo inicial(MATUZALEM)
    for(int i = 0; i < this->_tamanoPoblacion; i++){
        this->_contadorIndividuos++;                                    //lleva la cuenta de la cantidad de individuos
        Individuo *tmp = new Individuo(this->_contadorIndividuos, 2);   //se crea otro individuo
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
    cout << "---------------- Imprimiendo Poblacion ----------------" << endl;
    cout << "Generacion # "<< this->_generacion << endl;    //numero de la generacion poblacional
    Individuo * tmp = this->_poblacion;                     //inicia a revisar la poblacion(cantidad de individuos)
    while( tmp != NULL ){
        tmp->printDatosIndividuo();
        tmp = tmp->getSiguienteIndividuo();
    }//fin del while
}


Poblacion::~Poblacion(){}//destructor
