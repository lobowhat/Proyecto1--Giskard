#include "FigureDetection.h"

/**
 * @brief FigureDetection::FigureDetection
 * Constructor de la clase
 */
FigureDetection::FigureDetection(){
    //Se instancia cvMemoryStorage
    this->storage = cvCreateMemStorage(0);
    //Instanciamos la lista
    this->_list = new SimpleList<Figure*>();
}
/**
 * @brief FigureDetection::~FigureDetection
 *  Destructor de la clase
 */
FigureDetection::~FigureDetection(){
    cvReleaseImage( &this->grayImage );//Libera la memoria de la imagen
    cvReleaseImage( &this->copyImage );//Libera la memoria de la imagen
    free(this->_list);//Liberamos la memoria de la lista
}

/**
 * @brief FigureDetection::get
 *  Metodo para identificar las figuras que esten presentes en una imagen
 *  dada por el usuario.
 * @param pImg
 * @return _result
 */
IplImage* FigureDetection::get(IplImage* pImg){

    //Se clona la imagen original
    IplImage* result = cvCloneImage(pImg);

    //Obtenemos la imagen de contornos
    this->getImageContour(pImg);

    while(this->contour){//Ciclo de busquedas de contornos

        //Se obtienen las secuencias
        this->sec = cvApproxPoly(this->contour, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(this->contour)*0.02,0);
        this->circles=cvHoughCircles(grayImage, storage, CV_HOUGH_GRADIENT, 1,pImg->height/6, 100, 50);

        //Verificacion en caso de ser cuadrilateros
        if(this->sec->total == 4 && fabs(cvContourArea(this->sec, CV_WHOLE_SEQ)) > 100){
            CvPoint* ptr[4];//Arreglo de puntos x,y
            //Ciclo de busqueda de puntos x,y
            for(int i = 0; i<4; i++){
                ptr[i] = (CvPoint*)cvGetSeqElem(this->sec,i);
            }
            //Imprime las caracteristicas
            this->printCharateristic(ptr, 4);

            //Se dibujan cuatro lineas correspondientes al cuadrilatero
            cvLine(result, *ptr[0], *ptr[1], CV_RGB(255,0,255),2);
            cvLine(result, *ptr[1], *ptr[2], CV_RGB(255,0,255),2);
            cvLine(result, *ptr[2], *ptr[3], CV_RGB(255,0,255),2);
            cvLine(result, *ptr[3], *ptr[0], CV_RGB(255,0,255),2);
        }
        //verificacion de circulos
        for (size_t i = 0; i < circles->total; i++)
                {
                     // detecta x  y y ,radios
                     float* p = (float*)cvGetSeqElem(circles, i);
                     cv::Point center(cvRound(p[0]), cvRound(p[1]));
                     int radio = cvRound(p[2]); //agrego



                     // dibuja circulo afuera  0,0,255
                     cvCircle(result, center, radio+1, CV_RGB(255,0,0), 2, 8, 0 ); //agrego

                     printf("x: %d y: %d r: %d\n", center.x, center.y, radius); //agrego
                }


        //Verificacion en caso de ser triangulo
        if(this->sec->total == 3 && fabs(cvContourArea(this->sec, CV_WHOLE_SEQ)) > 100){
            CvPoint* ptr[3];//Arreglo de puntos x,y

            //Ciclo de busqueda de puntos x,y
            for (int i = 0; i < 3; ++i) {
                ptr[i] = (CvPoint*)cvGetSeqElem(this->sec,i);
            }
            //Imprime caracteristicas
            this->printCharateristic(ptr, 3);
            //Dibuja lineas correspondientes al triangulo
            cvLine(result, *ptr[0], *ptr[1], CV_RGB(255,255,0),2);
            cvLine(result, *ptr[1], *ptr[2], CV_RGB(255,255,0),2);
            cvLine(result, *ptr[2], *ptr[0], CV_RGB(255,255,0),2);
        }
        this->contour = this->contour->h_next;
    }
    //Devolvemos la imagen identificando figuras
    return result;
}

/**
 * @brief FigureDetection::webCam
 * @param pCamara
 */
void FigureDetection::webCam(int pCamara){
    IplImage* frame; //Se define la imagen
    cvNamedWindow("Color detection", CV_WINDOW_AUTOSIZE); //Se crea la ventana
    CvCapture* capture = cvCaptureFromCAM(pCamara); //Se inicializa la captura de imagenes en la camara.
    frame = cvQueryFrame(capture); //Se hace una captura inicial

    int time = 0;
    int input;
    while ((input = cvWaitKey(100)) != 27)
    { //Ciclo de capturas de la camara
        frame = cvQueryFrame(capture); //Se obtiene la imagen a partir de la camara
        if(time%50 == 0){
            frame = get(frame); //Se llama a la funcion para que defina los contornos e identifique las figuras
            this->getImageCircules(frame);
            this->getImageCircules(frame);
        }
        cvShowImage("Color detection", frame); //Se muestra en pantalla la captura
        time++;
    }
    cvDestroyAllWindows(); // Destruye toda ventana
    cvReleaseCapture(&capture);
    cvReleaseImage(&frame);
}

/**
 * @brief FigureDetection::getImageContour
 *  Metodo para encontrar los contornos de la imagenes
 * @param pImg
 */
void FigureDetection::getImageContour(IplImage* pImg){
    this->grayImage = cvCreateImage( cvGetSize(pImg), IPL_DEPTH_8U, 1 );//Creacion de una imagen
    cvCvtColor( pImg, this->grayImage, CV_BGR2GRAY);//Convertir imagen original a escala de grises

    this->copyImage = cvCreateImage(cvGetSize(pImg), IPL_DEPTH_8U, 1);//Creacion de una imagen
    cvCanny(this->grayImage,this->copyImage,50,150);//Conversion de la imagen en contornos

    //Encuentra los contornos
    cvFindContours(this->copyImage, storage, &this->contour, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
}

/**
 * @brief FigureDetection::printCharateristic
 *  Metodo para imprimir las caracteristicas de las figuras
 * @param pPoints
 * @param pSides
 */
void FigureDetection::printCharateristic(CvPoint ** pPoints, int pSides){
    if(pSides == 4){
        int height, width;
        //Calculo del ancho
        width = sqrt(pow((pPoints[1]->x - pPoints[0]->x),2) + pow((pPoints[1]->y - pPoints[0]->y),2));
        //Calculo de la altura
        height = sqrt(pow((pPoints[2]->x - pPoints[1]->x),2) + pow((pPoints[2]->y - pPoints[1]->y),2));
        //Imprime las caracteristicas
        cout << "Ancho: "<< width <<" Largo: "<< height << endl;
        //Insertar caracteristicas
        this->_list->insertFinal(new Figure(pPoints[0]->x,pPoints[0]->y,height,width,pSides,"Cuadrilatero"));

    }else if(pSides == 3){
        int width, height, x, y;
        x = (pPoints[2]->x - pPoints[1]->y)/2;
        y = (pPoints[2]->y - pPoints[1]->y)/2;
        //Calcullo del ancho
        width = sqrt(pow((pPoints[2]->x - pPoints[0]->x),2) + pow((pPoints[2]->y - pPoints[0]->y),2));
        //Calculo de la altura
        height = sqrt(pow((x - pPoints[0]->x),2) + pow((y - pPoints[0]->y),2));
        //Imprimimos las caracteristicas
        cout << "Base: "<< abs(width) <<" Altura: "<< abs(height) << endl;
        //Insertamos las caracteristicas de la figura
        this->_list->insertFinal(new Figure(pPoints[0]->x,pPoints[0]->y,height,width,pSides,"Triangulo"));
    }
}

/**
 * @brief FigureDetection::getImageLines
 *  Metodo para encontrar todas las lineas presentes en las imagenes
 * @param pImg
 */
void FigureDetection::getImageLines(IplImage* pImg){
    //Secuencia para lineas
    CvSeq* lines = 0;

    //Imagen a escala de grises
    IplImage* gray_out = cvCreateImage( cvGetSize(pImg), IPL_DEPTH_8U, 1 );
    //Imagen de contornos
    IplImage* canny_out = cvCreateImage( cvGetSize(pImg), IPL_DEPTH_8U, 1 );
    //Imagen de escala de grises
    IplImage* gray_out1 = cvCreateImage( cvGetSize(pImg), IPL_DEPTH_8U, 3 );

    //Cambio de la imagen
    cvCvtColor(pImg , gray_out, CV_RGB2GRAY);
    //Cambio de la imagen a contornos
    cvCanny( gray_out, canny_out, 50, 125, 3 );
    //Escala a grises
    cvCvtColor(canny_out ,gray_out1, CV_GRAY2BGR);
    //Busqueda de todas las lineas dadas en una imagen
    lines = cvHoughLines2( canny_out, storage, CV_HOUGH_PROBABILISTIC, 1, CV_PI/180, 80,50, 10 );
    for(int i = 0; i < lines->total; i++ )
    {
        //Se encuentra los puntos de inicio y final de la linea
        CvPoint* line = (CvPoint*)cvGetSeqElem(lines,i);
        //Se dibuja la linea
        cvLine( pImg, line[0], line[1], CV_RGB(0,255,0), 2, 8 );
        //Se imprime los valores de la linea
        std::cout << "Linea: " << sqrt(pow(line[1].x - line[0].x,2) + pow(line[1].y - line[0].y,2)) << std::endl;
    }
}

/**
 * @brief FigureDetection::getListFigure
 *  Metodo utilizado para obtener la lista de figuras que
 *  estan dentro de la imagen
 * @return _list
 */
SimpleList<Figure*>* FigureDetection::getListFigure(){
    return this->_list;//Devolvemos la lista
}

void FigureDetection::getImageCircules(IplImage* pImg){
    Mat Image(pImg), Image_gray;

    // La convierte a gris para detectar
    cvtColor( Image, Image_gray, CV_BGR2GRAY );

    // Reduce la conjetura para evitar circulos falsos
    GaussianBlur( Image_gray, Image_gray, Size(19,19 ), 0, 0 );

    vector<Vec3f> circles;

    // Encontrar los circulos
    HoughCircles( Image_gray, circles, CV_HOUGH_GRADIENT, 1, Image_gray.rows/8, 10, 100, 0, 0 );

    // Dibuja circulos detectados                       //  Image_gray.rows/90
    for( size_t i = 0; i < circles.size(); i++ )
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        // centro de circulo
//        circle( Image, center, 3, Scalar(0,255,0), -1, 8, 0);
        // fuera del circulo
        circle( Image, center, radius, Scalar(0,0,255), 3, 8, 0 );

        std::cout << "Radio: " << radius << std::endl;
    }
}
