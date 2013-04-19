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
    //muestraImagen( _imagenGuardada );
    //detectarEspacioBorrado(_imagenGuardada);
}//recibeImagenGuardada

void ReconstruccionImagenes::initReconstruccionImagen()
{
    cout << "Crear Matriz de la Imagen" << endl;
    crearMatrizColores( _imagenGuardada->height, _imagenGuardada->width );//CAMBIAR EL TAMAÑO DE LA MATRIZ
    cout << "Se agregan Pixeles a la Matriz" << endl;
    agregaPixelesAMatriz();
    cout << "MUESTRA COORDENADAS" << endl;
    muestraLimitesEspacioBorrado();
}//Fin de initReconstruccionImagen()

/**
 * @brief ReconstruccionImagenes::detectarEspacioBorrado
 * Detecta el espacio borrado de una imagen (detecta el color rojo)
 * @param pImagen
 * @return
 */
void ReconstruccionImagenes::detectarEspacioBorrado( IplImage *pImagen)
{
    Mat sector(pImagen) ;                                                       //se convierte imagen desde IplImage a Mat
    assert( sector.type() == CV_8UC3 );
    _espacioBorradoImagen = sector;
    inRange( sector,
             Scalar(IConfiguracionParametros::R_MINIMO, IConfiguracionParametros::G_MINIMO, IConfiguracionParametros::B_MINIMO),
             Scalar(IConfiguracionParametros::R_MAXIMO, IConfiguracionParametros::G_MAXIMO, IConfiguracionParametros::B_MAXIMO),
             _espacioBorradoImagen );//rango a detectar del color ROJO (color por default)
//    IplImage ipl_img = _espacioBorradoImagen;                                   //conversion de Mat imagen a IplImage
//    IplImage *_imagenEspacioBorrado = &ipl_img;                                 //conversion de IplImage a IplImage*
    //muestraImagen(_imagenEspacioBorrado );                                      //hay que poner el Ampersand
    imshow("Giskard: Espacio Borrado de la imagen", _espacioBorradoImagen);
    imshow("Giskard: Imagen Actual", sector);
    waitKey(0);
    cvReleaseImage( &pImagen );
    cvDestroyAllWindows();
}

/**
 * @brief ReconstruccionImagenes::muestraLimitesEspacioBorrado
 * Imprime las coordenadas xy del espacio borrado
 * Recordar que los valores en la imagen vienen dados BGR
 */
void ReconstruccionImagenes::muestraLimitesEspacioBorrado(){
    bool bandera = false;
    int i = 0;
    for( i; i < _filas; ++i){                                //recorre filas
        int j = 0;
        for( j; j < _columnas; ++j){                         //recorre columnas
            if (this->_ptrMatriz[i][j][2] <= IConfiguracionParametros::R_MAXIMO && this->_ptrMatriz[i][j][2] >=
                    IConfiguracionParametros::R_MINIMO && this->_ptrMatriz[i][j][1] == IConfiguracionParametros::G_MAXIMO
                    && this->_ptrMatriz[i][j][0] == IConfiguracionParametros::B_MAXIMO){

                cout << "(" << j << "," << i << ")" << " ---> " << "(" << this->_ptrMatriz[i][j][2] << ","
                     << this->_ptrMatriz[i][j][1] << "," << this->_ptrMatriz[i][j][0] << ")" << endl;
                if(!bandera){
                   _filaInicial = j;
                   _columnaInicial = i;
                   bandera = true;
                }
                _filaFinal = j;
                _columnaFinal = i;
            }
        }//fin for interno

    }//fin for externo
    cout << "Coordenada Inicial del Espacio BORRADO: " << "(" << _filaInicial << "," << _columnaInicial << ")" << " \n"
         << "Coordenada Final del Espacio BORRADO: " << "(" << _filaFinal << "," << _columnaFinal << ")" << endl;
}//fin agregaPixelesAMatriz


/**
  Crea la matriz que contendrá un arreglo de RGB en cada celda
  @param pFila, cantidad de filas de la matriz
  @param pColumna, cantidad de columnas de la matriz
  */
void ReconstruccionImagenes::crearMatrizColores( int pFila, int pColumna ){
    this->_filas = pFila;
    this->_columnas = pColumna;
    this->_ptrMatriz = new int**[_filas];
    for(int i = 0; i < _filas; ++i){
        this->_ptrMatriz[i] = new int*[_columnas];
        for(int j = 0; j < _columnas; ++j){
            this->_ptrMatriz[i][j] = new int[2];
        }//fin del for
    }//fin del for
    cout << "MATRIZ DE COLORES CREADA" << endl;
}//fin de crearMatrizColores

/**
  Agrega arreglosRGB a cada celda de la matriz
  */
void ReconstruccionImagenes::agregaPixelesAMatriz(){
    for(int i = 0; i < _filas; ++i){//recorre filas
        for(int j = 0; j < _columnas; ++j){//recorre columnas
            for(int k = 0; k <= 2; ++k){
                this->_ptrMatriz[i][j][k] = getPixeles( _imagenGuardada, i, j, k );
            }//fin for
        }//fin for interno
    }//fin for externo
    cout << "FIN AGREGAR PIXELES" << endl;
}//fin agregaPixelesAMatriz


/**
  Obtiene los pixeles de una imagen completa (SIN REDUCCION DE PIXELES)
  @param pImagen, recibe una imagen para obtener los pixeles de esta
  @return scal.val[pK], devuelve un int con los valores R,G,B de un pixel de una celda de la imagen
  */
int ReconstruccionImagenes::getPixeles( IplImage *pImagen, int pI, int pJ, int pK ){
    CvMat mathdr, *mat = cvGetMat( pImagen, &mathdr );
    CvScalar scal = cvGet2D( mat, pI, pJ );
    return scal.val[pK];
}//fin de getPixeles

/**
  Crea la imagen ya reconstruida desde la matriz 3D
  */
void ReconstruccionImagenes::creaImagenReconstruida(){
    IplImage * img = cvCreateImage(cvSize(_filas, _columnas), IPL_DEPTH_8U, 3);
    for(int i = 0; i < _filas; i++) {
        for (int j = 0; j < _columnas; j++){
            ((uchar *)(img->imageData + i*img->widthStep))[j*img->nChannels + 0] = this->_ptrMatriz[i][j][0]; // B
            ((uchar *)(img->imageData + i*img->widthStep))[j*img->nChannels + 1] = this->_ptrMatriz[i][j][1]; // G
            ((uchar *)(img->imageData + i*img->widthStep))[j*img->nChannels + 2] = this->_ptrMatriz[i][j][2]; // R
        }//fin for de filas o ancho
    }//fin for de columnas o largo
    muestraImagen( img );
}//fin de creaImagenAnalizada

/**
  Muestra la imagen en pantalla
  @param pImagenAMostrar, imagen que se desea mostrar
  */
void ReconstruccionImagenes::muestraImagen( IplImage *pImagenAMostrar ){
    if( !pImagenAMostrar ){
        cout << "¡Error!, No se puede mostrar imagen." << endl;
    }//fin del if
    else{
        cvNamedWindow( "Giskard", CV_WINDOW_AUTOSIZE );             //nombre a la ventana que contiene la imagen
        cvShowImage( "Giskard", pImagenAMostrar );                  // muestra la imagen
        cvWaitKey( 0 );
        cvReleaseImage( &pImagenAMostrar );                         // Wait for a keystroke in the window
        cvDestroyWindow( "Giskard" );
    }//fin del else
}//fin de muestraImagen

/**
  Imprime la matriz 3D que se usa para almacenar los dator RGB de una imagen
  */
void ReconstruccionImagenes::imprimeMatriz(){
    for(int i = 0; i < _filas; ++i){                                //recorre filas
        cout << i << endl;
        for(int j = 0; j < _columnas; ++j){                         //recorre columnas
            cout << endl;
            for(int k = 0; k <= 2; ++k){
                cout << '\t' << this->_ptrMatriz[i][j][k];
            }//fin for
           // cout << " " << endl;
        }//fin for interno
    cout << endl << endl;
    }//fin for externo
}//fin agregaPixelesAMatriz

/**
 * @brief ReconstruccionImagenes::getFilaInicial
 * @return _filaInicial del espacio borrado
 */
int ReconstruccionImagenes::getFilaInicial()
{
    return _filaInicial;
}

/**
 * @brief ReconstruccionImagenes::getFilaFinal
 * @return _filaFinal del espacio borrado
 */
int ReconstruccionImagenes::getFilaFinal()
{
    return _filaFinal;
}

/**
 * @brief ReconstruccionImagenes::setFilaInicial
 * @param pFilaInicial
 */
void ReconstruccionImagenes::setFilaInicial( int pFilaInicial )
{
    this->_filaInicial = pFilaInicial;
}

/**
 * @brief ReconstruccionImagenes::setFilaFinal
 * @param pFilaFinal
 */
void ReconstruccionImagenes::setFilaFinal( int pFilaFinal )
{
    this->_filaFinal = pFilaFinal;
}

/**
 * @brief ReconstruccionImagenes::getColumnaInicial
 * @return columna inicial del espacio borrado
 */
int ReconstruccionImagenes::getColumnaInicial()
{
    return _columnaInicial;
}

/**
 * @brief ReconstruccionImagenes::getColumnaFinal
 * @return columna final del espacio borrado
 */
int ReconstruccionImagenes::getColumnaFinal()
{
    return _columnaFinal;
}

/**
 * @brief ReconstruccionImagenes::setColumnaInicial
 * @param pColumnaInicial
 */
void ReconstruccionImagenes::setColumnaInicial(int pColumnaInicial)
{
    this->_columnaInicial = pColumnaInicial;
}

/**
 * @brief ReconstruccionImagenes::setColumnaFinal
 * @param pColumnaFinal
 */
void ReconstruccionImagenes::setColumnaFinal(int pColumnaFinal)
{
    this->_columnaFinal = pColumnaFinal;
}


/**
  Destructor
  */
ReconstruccionImagenes::~ReconstruccionImagenes(){}//fin del destructor











