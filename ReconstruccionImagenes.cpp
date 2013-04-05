#include "ReconstruccionImagenes.h"

/**
  Constructor
  */
ReconstruccionImagenes::ReconstruccionImagenes()
{
    this->_capturaCamara = 0;   //no hay imagen
    this->_imagenGuardada = 0;  //no hay video
}//fin del constructor

/**
  Recibe una imagen capturada desde la cámara
  */
void ReconstruccionImagenes::recibeImagenCapturada()
{
    this->_capturaCamara = cvCaptureFromCAM( 0 );//inicializa la cámara de la computadora
    cvNamedWindow( "Giskard" );//crea una ventana con el título "Video"

    while( true ){
        IplImage* frame = cvQueryFrame( _capturaCamara );//toma y recupera cada frame del video en secuencia

        //#############################################

        cvShowImage( "Giskard", frame );//muestra el video
        int c = cvWaitKey(40);//espera 40 ms
        //exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
        if((char)c == 27 ) break;
    }//fin del while
    cvDestroyWindow( "Giskard" );//destroy the opened window
    cvReleaseCapture( &_capturaCamara );//release memory

}//recibeImagenCapturada

/**
  Recibe el path de la imagen almacenada en la computadora
  @param pPathImagen
  */
void ReconstruccionImagenes::recibeImagenGuardada( char* pPathImagenGuardada )
{
    this->_imagenGuardada = cvLoadImage( pPathImagenGuardada );
}//recibeImagenGuardada

/**
  Muestra la imagen en pantalla
  @param pImagenAMostrar, imagen que se desea mostrar
  */
void ReconstruccionImagenes::muestraImagen( IplImage *pImagenAMostrar ){
    if( !pImagenAMostrar ){
        cout << "¡Error!, No se puede leer imagen." << endl;
    }//fin del if
    else{
        cvNamedWindow( "Giskard", CV_WINDOW_AUTOSIZE );//nombre a la ventana que contiene la imagen
        cvShowImage( "Giskard", pImagenAMostrar );// muestra la imagen
        cvWaitKey( 0 );
        cvReleaseImage( &pImagenAMostrar );// Wait for a keystroke in the window
        cvDestroyWindow( "Giskard" );
    }//fin del else
}//fin de muestraImagen

/**
  Destructor
  */
ReconstruccionImagenes::~ReconstruccionImagenes(){}//fin del destructor
