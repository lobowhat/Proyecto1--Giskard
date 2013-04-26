#include "Poblacion.h"

Poblacion::Poblacion()
{
    this->_tamanoPoblacion = IConfiguracionParametros::TAMANO_POBLACION;
    this->_probabilidadCruce = IConfiguracionParametros::PROBABILIDAD_CRUCE;//1 * 100 = 100% debe tomar valores desde 0.5 hasta 1
    this->_contadorIndividuos = 1;
    this->_maxCantidadNacimientos = IConfiguracionParametros::MAX_NACIMIENTOS;
    this->_reproduccion = new Reproduccion();
    this->_valorFitnessPixel = -1;          // no ha recibido el valor del pixel
}//constructor



/**
 * @brief Poblacion::crearPoblacionInicial
 * Crea una poblacion con una cantidad n de Individuos
 */
void Poblacion::crearPoblacionInicial()
{
    this->_poblacion = new Individuo( this->_contadorIndividuos );     //individuo inicial(MATUZALEM)
    for(int i = 0; i < this->_tamanoPoblacion - 1; i++){
        this->_contadorIndividuos++;                                    //lleva la cuenta de la cantidad de individuos
        Individuo *tmp = new Individuo( this->_contadorIndividuos );   //se crea otro individuo
        tmp->setSiguienteIndividuo(this->_poblacion);                   //se agrega otro individuo a la lista simple
        this->_poblacion = tmp;
    }//fin del for
    aplicarFitness();
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
    Individuo *tmp = this->_poblacion;
    while( tmp != NULL ){
        //&& fitnessTotal == tmp->getValorFitness()
        if( tmp->getIndividuoSeleccionado() != true  ){
            tmp->setIndividuoSeleccionado( true );      //Individuo ha sido seleccionado, no volverá a ser escogido
            break;
        }//fin del if
        else{
            tmp = tmp->getSiguienteIndividuo();
        }
    }//fin del while
    return tmp;
}

/**
 * @brief Poblacion::nuevaGeneracion
 * Crea la nueva generacion de individuos
 */
void Poblacion::crearNuevaGeneracion()
{
    Individuo *nacimientos = NULL;          //se genera una nueva lista simple( nueva generacion)
    Individuo *padre1 = NULL;
    Individuo *padre2 = NULL;
    for(int i = 0 ; i < this->_maxCantidadNacimientos; i++){
        if((rand()% 10) < this->_probabilidadCruce){//habrá hijos si rand es menor que la probabilidad de cruce

            padre1 = this->seleccionIndividuos();
            padre2 = this->seleccionIndividuos();
            this->_contadorIndividuos++;
            Individuo *tmp = _reproduccion->cruce( padre1, padre2, this->_contadorIndividuos );
            tmp->setSiguienteIndividuo( nacimientos );
            nacimientos = tmp;
            nacimientos->setGeneracion( this->_generacion + 1);
        }
//        qDebug() << "LULA1" << endl;
    }
    imprimeNuevaGeneracion( nacimientos);
    mezclarPoblacion( nacimientos );
    this->_generacion += 1;
    //qDebug()<<"GENERACION ............................ " << this->_generacion << endl;
}

/**
 * @brief Poblacion::imprimeNuevaGeneracion
 * Imprime solo nuevas generaciones de individuos
 * @param p
 */
void Poblacion::imprimeNuevaGeneracion(Individuo *p)
{
    qDebug() << "---------------- Imprimiendo Poblacion ----------------" << "Generacion # " << this->_generacion << endl;
    //cout << "Generacion # "<< this->_generacion << endl;    //numero de la generacion poblacional
    Individuo * tmp = p;                     //inicia a revisar la poblacion(cantidad de individuos)
    while( tmp != NULL ){
        tmp->printDatosIndividuo();
        tmp = tmp->getSiguienteIndividuo();
    }//fin del while
}

/**
 * @brief Poblacion::mezclarPoblacion
 * Cambiara a los mejores individuos de la nueva generacion
 * por los peores de la generacion actual
 * @param pNuevaGeneracion
 */
void Poblacion::mezclarPoblacion( Individuo *pNuevaGeneracion )
{
    Individuo *  debilGeneracionActual = this->getPeorIndividuo( this->_poblacion );
    Individuo *  fuerteNuevaGeneracion = this->getMejorIndividuo( pNuevaGeneracion );

    while( debilGeneracionActual->getValorFitness() < fuerteNuevaGeneracion->getValorFitness() ){

        this->cambiarIndividuos( debilGeneracionActual,fuerteNuevaGeneracion );

        debilGeneracionActual = this->getPeorIndividuo( this->_poblacion );
        fuerteNuevaGeneracion = this->getMejorIndividuo( pNuevaGeneracion );
    }
    cambiaValorIndividuoSeleccionado();
}

/**
 * @brief Poblacion::cambiarIndividuos
 * Cambia a los individuos de la nueva generacion a la anterior(GENERAL)
 * Modificando sus valores con getters y setters
 * @param pIndividuo1
 * @param pIndividuo2
 */
void Poblacion::cambiarIndividuos( Individuo *pIndividuo1, Individuo *pIndividuo2 )
{
    // Se generan valores temporales para hacer el cambio
    int id = pIndividuo1->getId();
    unsigned short *cromosoma = pIndividuo1->getCromosoma();
    int fitness = pIndividuo1->getValorFitness();
    int generacion = pIndividuo1->getGeneracion();
    int padre = pIndividuo1->getPadre();
    int madre = pIndividuo1->getMadre();
    // CAMBIO DE VALORES DEL INDIVIDUO 2 HACIA EL INDIVIDUO 1
    pIndividuo1->setValorFitness( pIndividuo2->getValorFitness() );
    pIndividuo1->setId( pIndividuo2->getId() );
    pIndividuo1->setCromosoma( pIndividuo2->getCromosoma() );
    pIndividuo1->setGeneracion( pIndividuo2->getGeneracion() );
    pIndividuo1->setPadre( pIndividuo2->getPadre() );
    pIndividuo1->setMadre( pIndividuo2->getMadre() );
    // CAMBIO DE VALORES DEL INDIVIDUO 1 HACIA EL INDIVIDUO 2
    pIndividuo2->setId( id );
    pIndividuo2->setCromosoma( cromosoma );
    pIndividuo2->setValorFitness( fitness );
    pIndividuo2->setGeneracion( generacion );
    pIndividuo2->setMadre( madre );
    pIndividuo2->setPadre( padre );
}
/**
 * @brief Poblacion::cambiaValorIndividuoSeleccionado
 * Cambia el valor de IndividuoSeleccionado para que pueda ser seleccionado para el cruce
 */
void Poblacion::cambiaValorIndividuoSeleccionado()
{
    Individuo *tmp = this->_poblacion;
    while ( tmp != NULL ){
        if( tmp->getIndividuoSeleccionado() == true ){
            tmp->setIndividuoSeleccionado( false );
        }
        tmp = tmp->getSiguienteIndividuo();
    }
}

/**
 * @brief Poblacion::getMejorIndividuo
 * Retorna al mejor Individuo
 * @return mejorIndividuo
 */
Individuo *Poblacion::getMejorIndividuo( Individuo *pPoblacion )
{
    Individuo *tmp = pPoblacion;
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

void Poblacion::aplicarFitness()
{
    Individuo * tmp = this->_poblacion;
    while(tmp != NULL)
    {
        _reproduccion->fitness( tmp );
        tmp = tmp->getSiguienteIndividuo();
    }
}

/**
 * @brief Poblacion::setValorFitnessPixelEscogido
 * @param pValorFitnessPixel
 */
void Poblacion::setValorFitnessPixelEscogido(int pValorFitnessPixel)
{
    this->_valorFitnessPixel = pValorFitnessPixel;
}

/**
 * @brief Poblacion::getValorFitnessPixelEscogido
 * @return _valorFitnessPixel
 */
int Poblacion::getValorFitnessPixelEscogido()
{
    return _valorFitnessPixel;
}



/**
 * @brief Poblacion::getPeorIndividuo
 * Retorna al peorIndividuo
 * @return peorIndividuo
 */
Individuo *Poblacion::getPeorIndividuo( Individuo *pPoblacion )
{
    Individuo *tmp = pPoblacion;
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

/**
 * @brief Poblacion::mejoresIndividuos
 * Obtiene una lista con una cierta cantidad de los mejores Individuos de la poblacion en todas las generaciones
 * @param pCantidadIndividuos
 * @return _individuosSeleccionados;
 */
unsigned short *Poblacion::mejoresIndividuos( unsigned short pCantidadIndividuos )
{
    Individuo *tmp;
    for(int i = 0; i < pCantidadIndividuos; i++){
        tmp = getMejorIndividuo( this->_poblacion );
        tmp->setSiguienteIndividuo(this->_mejoresIndividuosFinal);  //se agrega otro individuo a la lista simple
        this->_mejoresIndividuosFinal = tmp;
    }//fin del for
    this->_individuosSeleccionados = new unsigned short[pCantidadIndividuos];
    Individuo *tmp1 = this->_mejoresIndividuosFinal;
    for(int i = 0; i < pCantidadIndividuos; i += 3){
        this->_individuosSeleccionados[i] = _mejoresIndividuosFinal->getChromosome()->getRValue();
        this->_individuosSeleccionados[i + 1] = _mejoresIndividuosFinal->getChromosome()->getGValue();
        this->_individuosSeleccionados[i + 2] = _mejoresIndividuosFinal->getChromosome()->getBValue();
        tmp1 = tmp1->getSiguienteIndividuo();
    }
    return _individuosSeleccionados;
}





Poblacion::~Poblacion(){}//destructor

