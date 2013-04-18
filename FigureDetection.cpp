#include "FigureDetection.h"

IplImage* FigureDetection::get(IplImage* img){
    CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* contour;
    CvSeq* sec;

    IplImage *copyImage, *grayImage;//Imagenes
    IplImage* ret = cvCloneImage(img);

    grayImage = cvCreateImage( cvGetSize(img), IPL_DEPTH_8U, 1 );//Creacion de una imagen
    cvCvtColor( img, grayImage, CV_BGR2GRAY);//Convertir imagen original a escala de grises

    copyImage = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);//Creacion de una imagen
    cvCanny(grayImage,copyImage,50,150);//Conversion de la imagen en contornos

    //Encuentra los contornos
    cvFindContours(copyImage, storage, &contour, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
    cout << "Se encontro contornos"<<endl;

    while(contour){//Ciclo de busquedas de contornos

        //Se obtienen las secuencias
        sec = cvApproxPoly(contour, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contour)*0.02,0);

        //Verificacion en caso de ser cuadrilateros
        if(sec->total == 4 && fabs(cvContourArea(sec, CV_WHOLE_SEQ)) > 30){
            CvPoint* ptr[4];
            for(int i = 0; i<4; i++){
                ptr[i] = (CvPoint*)cvGetSeqElem(sec,i);
            }

            cvLine(ret, *ptr[0], *ptr[1], CV_RGB(255,0,255),3);
            cvLine(ret, *ptr[1], *ptr[2], CV_RGB(255,0,255),3);
            cvLine(ret, *ptr[2], *ptr[3], CV_RGB(255,0,255),3);
            cvLine(ret, *ptr[3], *ptr[0], CV_RGB(255,0,255),3);
        }

        //Verificacion en caso de ser triangulo
        if(sec->total == 3 && fabs(cvContourArea(sec, CV_WHOLE_SEQ)) > 30){
            CvPoint* ptr[3];
            for (int i = 0; i < 3; ++i) {
                ptr[i] = (CvPoint*)cvGetSeqElem(sec,i);
            }
            cvLine(ret, *ptr[0], *ptr[1], CV_RGB(255,255,0),3);
            cvLine(ret, *ptr[1], *ptr[2], CV_RGB(255,255,0),3);
            cvLine(ret, *ptr[2], *ptr[0], CV_RGB(255,255,0),3);
        }
        contour = contour->h_next;
    }
    cvReleaseImage( &grayImage );//Libera la memoria de la imagen
    cvReleaseImage( &copyImage );//Libera la memoria de la imagen

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
