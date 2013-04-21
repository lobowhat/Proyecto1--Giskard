#include <iostream>
#include "ReconstruccionImagenes.h"
#include "Poblacion.h"

//LIMITACIONES PARA LA IMAGEN DEBE SER FORMATO PNG PARA NO COMPRIMIR LOS BORDES EXTERNOS

int main()
{
    cout << "Hello Giskard!" << endl;

    /*
     * Para hacerlo con QtCreator, se van a Projects, Build & Run, Run, y en
     * Working directory, cambian el que tienen por la dirección donde está el
     * proyecto
     */
//    ReconstruccionImagenes *p = new ReconstruccionImagenes();
//    p->recibeImagenGuardada( "raya1.png" );//insertar path de imagen
////    p->recibeImagenCapturada();//inicia la captura de video
//    p->initReconstruccionImagen();
//    delete p;

    Poblacion *po = new Poblacion();
    po->crearPoblacionInicial();
    po->printPoblacion();
    po->getMejorIndividuo();
    po->getPeorIndividuo();
    delete po;

    return 0;
}

