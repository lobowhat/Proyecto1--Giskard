#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <string.h>

/**
 * @brief The Figure class
 *  Clase que define las caracteristicas de una figura
 *  en especifico ya sea un cuadrilatero, triangulo, lineas o circulos
 */
class Figure
{
private:
    int _height;//Alto de la figura
    int _width;//Ancho de la figura
    int _sides;//Lados de la figura
    int _posX, _posY;//Posiciones de la figura
    std::string _name;//Nombre de la figura

public:
    //Constructor
    Figure(int pPosX=0, int pPosY=0, int pHeight=0, int pWidth=0, int pSides=0, std::string pName=NULL);
    //Se define la altura de la figura
    void setHeight(int);
    //Se define el ancho de la figura
    void setWidth(int);
    //Se define los lados de la figura
    void setSides(int);
    //Se define el nombre de la figura
    void setName(std::string);
    //Se obtiene la altura
    int getHeight();
    //Se obtiene el ancho
    int getWidth();
    //Se obtiene el numero de lados
    int getSides();
    //Se obtiene el nombre
    std::string getName();
};//Fin de la clase

#endif // FIGURE_H
