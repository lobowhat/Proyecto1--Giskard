#include "Reproduccion.h"

Reproduccion::Reproduccion(){
    this->_probabilidadInvertir = IConfiguracionParametros::PROBABILIDAD_INVERSION;
    this->_probabilidadMutacion = IConfiguracionParametros::PROBABILIDAD_MUTACION;
    srand (time(NULL));

}

/**
 * @brief Reproduccion::getProbabilidadInvertir
 * obtiene la probabilidad de inversion
 * @return _probabilidadInvertir
 */
int Reproduccion::getProbabilidadInvertir()
{
    return _probabilidadInvertir;
}

/**
 * @brief Reproduccion::setProbabilidadInvertir
 * cambia la probabilidad de inversion
 * @param pProbabilidadInvertir
 */
void Reproduccion::setProbabilidadInvertir( int pProbabilidadInvertir )
{
    _probabilidadInvertir = pProbabilidadInvertir;
}

/**
 * @brief Reproduccion::getProbabilidadMutacion
 * obtiene la probabilidad de mutacion
 * @return _probabilidadMutacion
 */
int Reproduccion::getProbabilidadMutacion()
{
    return _probabilidadMutacion;
}

/**
 * @brief Reproduccion::setProbabilidadMutacion
 * cambia la probabilidad de mutacion
 * @param pProbabilidadMutacion
 */
void Reproduccion::setProbabilidadMutacion( int pProbabilidadMutacion )
{
    _probabilidadMutacion = pProbabilidadMutacion;
}

/**
 * @brief Reproduccion::cruce
 * Cruza 2 padres para generar un descendiente
 * @param pPadre
 * @param pMadre
 * @param pContador
 * @return Individuo
 */
Individuo *Reproduccion::cruce( Individuo *pPadre, Individuo *pMadre, int pContador )
{
    unsigned short *cromosomaDominante, *cromosomaRecesivo, cromosomaFinalHijo[23] ;
    int p = rand() % 100;
    if ( p < 50 ){
        cromosomaDominante = pPadre->getCromosoma();
        cromosomaRecesivo = pMadre->getCromosoma();
    }
    else{
        cromosomaDominante = pMadre->getCromosoma();
        cromosomaRecesivo = pPadre->getCromosoma();
    }
    for(int i = 0; i < 24; i++){
        if (i < 4){                         // 0 - 3    division primera parte de las ristra para el valor R
            cromosomaFinalHijo[i] = cromosomaDominante[i];
        }
        else if(i >= 4 && i < 8){           // 4 - 7    division segunda parte de las ristra para el valor R
            cromosomaFinalHijo[i] = cromosomaRecesivo[i];
        }
        else if(i >= 8 && i < 11){          // 8 - 11   division primera parte de las ristra para el valor G
            cromosomaFinalHijo[i] = cromosomaDominante[i];
        }
        else if(i >= 11 && i < 15){         // 12 - 15  division segunda parte de las ristra para el valor G
            cromosomaFinalHijo[i] = cromosomaRecesivo[i];
        }
        else if(i >= 15 && i < 19){         // 16 - 19  division primera parte de las ristra para el valor B
            cromosomaFinalHijo[i] = cromosomaDominante[i];
        }
        else if(i >= 19 && i <= 23){         // 20 - 23  division segunda parte de las ristra para el valor B
            cromosomaFinalHijo[i] = cromosomaRecesivo[i];
        }
        //qDebug() << "Cromosoma Hijo " << cromosomaFinalHijo[i];
    }
    Individuo *nuevoIndividuo = new Individuo( pContador );
    nuevoIndividuo->setCromosoma( cromosomaFinalHijo );
//    cout << "Nuevo Individuo sin alteraciones " << cromosomaFinalHijo << endl;
    int probabilidad = rand() % 10;
    if( probabilidad == this->_probabilidadMutacion ){
        this->mutacion( nuevoIndividuo );
        cout << "Mutado " << nuevoIndividuo->getCromosoma() << endl;}
    if( probabilidad == this->_probabilidadInvertir ){
        this->inversion( nuevoIndividuo );
        cout << "Invertido " << nuevoIndividuo->getCromosoma() << endl;}
    this->fitness( nuevoIndividuo );
    nuevoIndividuo->setPadre( pPadre->getId() );
    nuevoIndividuo->setMadre( pMadre->getId() );
    return nuevoIndividuo;
}

/**
 * @brief Reproduccion::mutacion
 * Cambia un bit del arreglo, si es 1 lo muta a 0 y viceversa
 * @param pIndividuo
 */
void Reproduccion::mutacion( Individuo *pIndividuo )
{
    int bitMutado = rand() % 23;
    pIndividuo->getCromosoma();
    if ( pIndividuo->getCromosoma()[bitMutado] == 1 ){
        pIndividuo->getCromosoma()[bitMutado] = 0; // si es un 1 se muta a 0
    }
    else{
        pIndividuo->getCromosoma()[bitMutado] = 1;  // si es un 0 se muta a 1
    }
}

/**
 * @brief Reproduccion::inversion
 * Invierte el cromosoma de un Individuo
 * @param pIndividuo
 */
void Reproduccion::inversion( Individuo *pIndividuo )
{
   unsigned short *invertido = new unsigned short[23];
    int j = 23;
    for(int i = 0; i < 24; i++){
        invertido[j] = pIndividuo->getCromosoma()[i];
        j--;
    }
    pIndividuo->setCromosoma(invertido);
}

/**
 * @brief Reproduccion::fitness
 * FUNCION FITNESS, toma los valores rgb y saca el promedio de estos
 * @param pIndividuo
 */
void Reproduccion::fitness(Individuo * pIndividuo){
    int resultado = (pIndividuo->getChromosome()->getRValue() + pIndividuo->getChromosome()->getGValue()
            + pIndividuo->getChromosome()->getBValue()) / 3;
    pIndividuo->setValorFitness( resultado );
}

Reproduccion::~Reproduccion(){}


