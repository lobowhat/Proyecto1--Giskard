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
    int _radio; //En caso de ser circulo se tiene el radio
    std::string _name;//Nombre de la figura

public:
    //Constructor
    Figure(int pPosX=0, int pPosY=0, int pHeight=0, int pWidth=0, int pSides=0, std::string pName=NULL, int pRadio=0);
    //Se define la altura de la figura
    void setHeight(int);
    //Se define el ancho de la figura
    void setWidth(int);
    //Se define los lados de la figura
    void setSides(int);
    //Se define las posiciones x
    void setX(int);
    //Se define las posiciones y
    void setY(int);
    //Se define el radio
    void setRadio(int);
    //Se define el nombre de la figura
    void setName(std::string);
    //Se obtiene la altura
    int getHeight() const;
    //Se obtiene el ancho
    int getWidth() const;
    //Se obtiene el numero de lados
    int getSides() const;
    //Se obtiene la posicion x
    int getX() const;
    //Se obtiene la posicion y
    int getY() const;
    //Se obtiene el radio
    int getRadio() const;
    //Se obtiene el nombre
    std::string getName();
};//Fin de la clase

#endif // FIGURE_H
