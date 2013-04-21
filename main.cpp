#include <iostream>
#include "ReconstruccionImagenes.h"
#include "Poblacion.h"


//LIMITACIONES PARA LA IMAGEN DEBE SER FORMATO PNG PARA NO COMPRIMIR LOS BORDES EXTERNOS

int main()
{
    cout << "Hello Giskard!" << endl;
//    ReconstruccionImagenes *p = new ReconstruccionImagenes();

//    p->recibeImagenGuardada( "/home/darayavilla/Qt_projects/lobowhat-Proyecto1--Giskard/raya1.png" );//insertar path de imagen
////    p->recibeImagenCapturada();//inicia la captura de video
//    p->initReconstruccionImagen();
//    delete p;

    Poblacion *po = new Poblacion( 5 );//se inserta un numero de individuos
    po->crearPoblacionInicial();
    po->printPoblacion();
    po->getMejorIndividuo();
    po->getPeorIndividuo();
    delete po;

    return 0;
}

