#include "FigureDetection.h"

FigureDetection::FigureDetection(){
     this->storage = cvCreateMemStorage(0);
}
FigureDetection::~FigureDetection(){
    cvReleaseImage( &this->grayImage );//Libera la memoria de la imagen
    cvReleaseImage( &this->copyImage );//Libera la memoria de la imagen
}

IplImage* FigureDetection::get(IplImage* pImg){

    IplImage* ret = cvCloneImage(pImg);

    this->getImageContour(pImg);

    while(this->contour){//Ciclo de busquedas de contornos

        //Se obtienen las secuencias
        this->sec = cvApproxPoly(this->contour, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(this->contour)*0.02,0);

        //Verificacion en caso de ser cuadrilateros
        if(this->sec->total == 4 && fabs(cvContourArea(this->sec, CV_WHOLE_SEQ)) > 30){
            CvPoint* ptr[4];
            for(int i = 0; i<4; i++){
                ptr[i] = (CvPoint*)cvGetSeqElem(this->sec,i);
            }

            this->printCharateristic(ptr, 4);

            cvLine(ret, *ptr[0], *ptr[1], CV_RGB(255,0,255),3);
            cvLine(ret, *ptr[1], *ptr[2], CV_RGB(255,0,255),3);
            cvLine(ret, *ptr[2], *ptr[3], CV_RGB(255,0,255),3);
            cvLine(ret, *ptr[3], *ptr[0], CV_RGB(255,0,255),3);
        }

        //Verificacion en caso de ser triangulo
        //
        if(this->sec->total == 3 && fabs(cvContourArea(this->sec, CV_WHOLE_SEQ)) > 30){
            CvPoint* ptr[3];
            for (int i = 0; i < 3; ++i) {
                ptr[i] = (CvPoint*)cvGetSeqElem(this->sec,i);
            }
            cout << endl;
            this->printCharateristic(ptr, 3);
            cvLine(ret, *ptr[0], *ptr[1], CV_RGB(255,255,0),3);
            cvLine(ret, *ptr[1], *ptr[2], CV_RGB(255,255,0),3);
            cvLine(ret, *ptr[2], *ptr[0], CV_RGB(255,255,0),3);
        }
        this->contour = this->contour->h_next;
    }

    return ret;
}

void FigureDetection::webCam(int pCamara){
    IplImage* frame; //Se define la imagen
    cvNamedWindow("Color detection", CV_WINDOW_AUTOSIZE); //Se crea la ventana
    CvCapture* capture = cvCaptureFromCAM(pCamara); //Se inicializa la captura de imagenes en la camara.
    frame = cvQueryFrame(capture); //Se hace una captura inicial

    int input;
    while ((input = cvWaitKey(50)) != 27)
    { //Ciclo de capturas de la camara
        frame = cvQueryFrame(capture); //Se obtiene la imagen a partir de la camara
        frame = get(frame); //Se llama a la funcion para que defina los contornos e identifique las figuras
        cvShowImage("Color detection", frame); //Se muestra en pantalla la captura
    }
    cvDestroyAllWindows(); // Destruye toda ventana
    cvReleaseCapture(&capture);
    cvReleaseImage(&frame);
}

void FigureDetection::getImageContour(IplImage* pImg){

    this->grayImage = cvCreateImage( cvGetSize(pImg), IPL_DEPTH_8U, 1 );//Creacion de una imagen
    cvCvtColor( pImg, this->grayImage, CV_BGR2GRAY);//Convertir imagen original a escala de grises

    this->copyImage = cvCreateImage(cvGetSize(pImg), IPL_DEPTH_8U, 1);//Creacion de una imagen
    cvCanny(this->grayImage,this->copyImage,50,150);//Conversion de la imagen en contornos

    //Encuentra los contornos
    cvFindContours(this->copyImage, storage, &this->contour, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
}

void FigureDetection::printCharateristic(CvPoint ** pPoints, int pSides){
    if(pSides == 4){
        cout << "Ancho: "<<(pPoints[1]->x - pPoints[0]->x)<<" Largo: "<<(pPoints[2]->y-pPoints[1]->y) << endl;
    }else if(pSides == 3){
        int base, altura;
        base = sqrt(pow((pPoints[2]->x - pPoints[0]->x),2) + pow((pPoints[2]->y - pPoints[0]->y),2));
        altura = sqrt(pow((1),2) + pow((1),2));
        cout << "Base: "<<base<<" Altura: "<<altura << endl;
    }

}
