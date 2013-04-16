#include <iostream>
#include "ReconstruccionImagenes.h"

using namespace std;

int main1()
{
    cout << "Hello Giskard!" << endl;
    ReconstruccionImagenes *p = new ReconstruccionImagenes();
    p->recibeImagenGuardada("/home/darayavilla/Qt_projects/lobowhat-Proyecto1--Giskard/raya1.jpg");//insertar path de imagen
    //p->recibeImagenCapturada();//inicia la captura de video
    p->initReconstruccionImagen();
    delete p;

    return 0;
}

