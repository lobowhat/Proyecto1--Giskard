#include <iostream>
#include "ReconstruccionImagenes.h"
#include "AlgoritmoGenetico.h"

//LIMITACIONES PARA LA IMAGEN DEBE SER FORMATO PNG PARA NO COMPRIMIR LOS BORDES EXTERNOS

int main()
{
    cout << "Hello Giskard!" << endl;
//    Chromosome p;
//    std::cout << p.decimalToBinary(1023);
    /*
     * Para hacerlo con QtCreator, se van a Projects, Build & Run, Run, y en
     * Working directory, cambian el que tienen por la dirección donde está el
     * proyecto
     */
    ReconstruccionImagenes *p = new ReconstruccionImagenes();
    p->recibeImagenGuardada( "raya1.png" );//insertar path de imagen
//    p->recibeImagenCapturada();//inicia la captura de video
    p->initReconstruccionImagen();  // aqui se obtiene ubicacion del espacio borrado
    delete p;

//    AlgoritmoGenetico *po = new AlgoritmoGenetico( 255, 255, 255 );
//    cout << "hola" << endl;
//    po->initAlgoritmoGenetico();
//    delete po;

    return 0;
}
