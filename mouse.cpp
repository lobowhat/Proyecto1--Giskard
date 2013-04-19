#include <cv.h>
#include <highgui.h>




//Funcion principal
void mouseEvent(int evt, int x, int y, int flags, void* param){
    if(evt==CV_EVENT_LBUTTONDOWN){
        printf("%d %d\n",x,y);
    }
}


//int main2()
//{

//        cvNamedWindow("Identificacion de X y Y");

//        //Asignacion de las llamadas para los eventos
//        cvSetMouseCallback("Identificacion de X y Y", mouseEvent, 0);

//        //carga la imagen
//        IplImage* img = cvLoadImage("figuras.jpg");
//        cvShowImage("Identificacion de X y Y", img);

//        //espera
//        cvWaitKey(0);

//        //destruye ventana
//        cvDestroyWindow("Identificacion de X y Y");
//        cvReleaseImage(&img);

//        return 0;
//}
