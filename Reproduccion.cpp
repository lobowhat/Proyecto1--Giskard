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

Individuo *Reproduccion::cruce( Individuo *pPadre, Individuo *pMadre, int pContador )
{
    unsigned short *cromosomaDominante;
    unsigned short *cromosomaRecesivo;
    unsigned short *cromosomaFinalHijo;
    if ( (rand() % 100) < 50 ){
        cromosomaDominante = pPadre->getCromosoma();
        cromosomaRecesivo = pMadre->getCromosoma();
    }
    else{
        cromosomaDominante = pMadre->getCromosoma();
        cromosomaRecesivo = pPadre->getCromosoma();
    }
    for(int i = 0; i < 23; i++){
        if (i < 4){
            cromosomaFinalHijo[i] = cromosomaDominante[i];
        }
        else if(i >= 4 && i < 8){
            cromosomaFinalHijo[i] = cromosomaRecesivo[i];
        }
        else if(i >= 8 && i < 11){
            cromosomaFinalHijo[i] = cromosomaDominante[i];
        }
        else if(i >= 11 && i < 15){
            cromosomaFinalHijo[i] = cromosomaRecesivo[i];
        }
        else if(i >= 15 && i < 19){
            cromosomaFinalHijo[i] = cromosomaDominante[i];
        }
        else if(i >= 19 && i < 23){
            cromosomaFinalHijo[i] = cromosomaRecesivo[i];
        }
    }
    Individuo *nuevoIndividuo = new Individuo( pContador );
    nuevoIndividuo->setCromosoma( cromosomaFinalHijo );
    //cout << "Original " << cromosomaHijo << endl;
//    int probabilidad = rand() % 100;
//    if(mutar < this->_probabilidadMutacion)
//        this->mutacion( nuevoIndividuo );
//    //cout << "Mutado " << nuevoIndividuo->getCromosoma()<< endl;
//    if(invertir < this->_probabilidadInvertir)
//        this->nnversion( nuevoIndividuo );
//    //cout << "Invertido " << nuevoIndividuo->getCromosoma()<< endl;
//    this->fitness( nuevoIndividuo );
    nuevoIndividuo->setPadre( pPadre->getId() );
    nuevoIndividuo->setMadre( pMadre->getId() );
    return nuevoIndividuo;
}

void Reproduccion::mutacion( Individuo *pIndividuo )
{

}

void Reproduccion::inversion( Individuo *pIndividuo )
{

}

Reproduccion::~Reproduccion(){}


