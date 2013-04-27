//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//#include <stdio.h>

//using namespace cv;

//int main(int argc, char** argv)
//{
// Mat Image, Image_gray;

// /// lee imagen
// Image = imread( "/home/howar/Escritorio/QT/lobowhat-Proyecto1--Giskard/figuras.jpg", 1 );

// if( !Image.data )
//   { return -1; }

// /// La convierte a gris para detectar
// cvtColor( Image, Image_gray, CV_BGR2GRAY );

// /// Reduce la conjetura para evitar circulos falsos
// GaussianBlur( Image_gray, Image_gray, Size(19,19 ), 0, 0 );

// vector<Vec3f> circles;

// /// Encontrar los circulos
// HoughCircles( Image_gray, circles, CV_HOUGH_GRADIENT, 1, Image_gray.rows/8, 10, 100, 0, 0 );

// /// Dibuja circulos detectados                       //  Image_gray.rows/90
// for( size_t i = 0; i < circles.size(); i++ )
// {
//     Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
//     int radius = cvRound(circles[i][2]);
//     // centro de circulo
//     circle( Image, center, 3, Scalar(0,255,0), -1, 8, 0);
//     // fuera del circulo
//     circle( Image, center, radius, Scalar(0,0,255), 3, 8, 0 );
//  }

// /// Resultados
// namedWindow( "circles", CV_WINDOW_AUTOSIZE );
// imshow( "circles", Image );

// waitKey(0);
// return 0;
//}

