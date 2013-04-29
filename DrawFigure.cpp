#include "DrawFigure.h"

/**
 * @brief DrawFigure::DrawFigure
 *Constructor de la clase. Esta clase dibuja figuras geometricas basicas.
 *  Se inicializa una variable para la imagen y el color de las figuras
 * @param pImage
 */
DrawFigure::DrawFigure(IplImage* pImage)
{
    this->_image = pImage;//Instanciamos la imagen
    this->_color = cvScalar(0, 0, 0);//Se define el color de las figuras
}

/**
 * @brief DrawFigure::~DrawFigure
 *Destructor de la clase
 */
DrawFigure::~DrawFigure(){
}

/**
 * @brief DrawFigure::drawLine
 *  Metodo para dibujar lineas dentro de una imagen
 * @param pX
 * @param pY
 * @param width
 */
void DrawFigure::drawLine(int pX, int pY, int width){
    //Se dibuja la linea
    cvLine( this->_image, cvPoint(pX,pY), cvPoint(pX+width,pY), this->_color, 3 );
}

/**
 * @brief DrawFigure::drawQuadrilater
 * Metodo para dibujar una figura cuadrilatera
 * @param pX
 * @param pY
 * @param height
 * @param width
 */
void DrawFigure::drawQuadrilater(int pX, int pY, int height, int width){
    //Se dibuja el cuadrilatero
    cvRectangle(this->_image, cvPoint(pX,pY), cvPoint(pX,pY), this->_color, 3 );
}

/**
 * @brief DrawFigure::drawTriangule
 *  Metodo para dibujar un triangulo
 * @param pX
 * @param pY
 * @param width
 * @param height
 */
void DrawFigure::drawTriangule(int pX, int pY, int width, int height){
    cvLine( this->_image, cvPoint(pX,pY), cvPoint(pX-(width/2),pY+height), this->_color, 3 );
    cvLine( this->_image, cvPoint(pX,pY), cvPoint(pX+(width/2),pY+height), this->_color, 3 );
    cvLine( this->_image, cvPoint(pX-(width/2),pY+height), cvPoint(pX+(width/2),pY+height), this->_color, 3 );
}

/**
 * @brief DrawFigure::drawCircule
 *  Metodo aplicado para dibujar un circulo en una imagen
 * @param pX
 * @param pY
 * @param pRadio
 */
void DrawFigure::drawCircule(int pX, int pY, int pRadio){
    cvCircle(this->_image, cvPoint(pX,pY), pRadio, this->_color, 3);

}
