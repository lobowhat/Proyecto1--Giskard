#include "Poblacion.h"

Poblacion::Poblacion(int pPoblacionInicial)
{
    this->_tamanoPoblacion = pPoblacionInicial;
    this->_probabilidadCruce = 1.0;                         //1 * 100 = 100% debe tomar valores desde 0.5 hasta 1
    this->_probabilidadMutacion = 0.5;                      /*50% ###se recomienda: utilizacion de una probabilidad
                                                            de mutacion del bit de l−1 , siendo l la longitud del string.*/

}//constructor

void Poblacion::crearPoblacionInicial()
{
    cout << "Creando poblacion inicial de " << this->_tamanoPoblacion << endl;
    this->_poblacion = new Individuo(this->_contadorIndividuos, 0);
    for(int i = 0; i < this->_tamanoPoblacion; i++){
        this->_contadorIndividuos++;
        Individuo *tmp = new Individuo(this->_contadorIndividuos, 2);
        tmp->setSiguienteIndividuo(this->_poblacion);
        this->_poblacion = tmp;
    }//fin del for

}

void Poblacion::printPoblacion()
{
    cout << "---------------- Imprimiendo Poblacion ----------------" << endl;
    cout << "Generacion # "<< this->_generacion << endl;
    Individuo * tmp = this->_poblacion;
    while( tmp != NULL ){
        tmp->printDatosIndividuo();
        tmp = tmp->getSiguienteIndividuo();
    }
}


Poblacion::~Poblacion(){}//destructor
