#include "figure.h"

/**
 * @brief Figure::Figure
 *  Constructor de la clase figuras
 */
Figure::Figure(int pPosX, int pPosY, int pHeight, int pWidth, int pSides, std::string pName, int pRadio)
{
    this->_posX = pPosX;//Se define la posicion en x de la figura
    this->_posY = pPosY;//Se define la posicion en y de la figura
    this->_height = pHeight;//Se define el alto de la figura
    this->_width = pWidth;//Se define el ancho de la figura
    this->_sides = pSides;//Se define el numero de lados de la figura
    std::cout << "Num lados: " << this->_sides << std::endl;
    this->_name = pName; //Se define el nombre de la figura
    this->_radio = pRadio;//Se define el radio en caso de ser circulo
}//Fin del constructor

/**
 * @brief Figure::getHeight
 *  Metodo hecho para obtener el valor de _height el cual
 *  corresponde a la altura de la figura
 * @return _height
 */
int Figure::getHeight() const{
    return this->_height;//Se devuelve el valor
}

/**
 * @brief Figure::getWidth
 *  Metodo para obtener el valor de la variable _width que corresponde al
 *  valor del ancho de la figura.
 * @return _width
 */
int Figure::getWidth() const{
    return this->_width;//Se devuelve el valor
}

/**
 * @brief Figure::getSides
 *  Metodo para obtener el numero de la lados de la figura almacenado en
 *  la variable _sides.
 * @return _sides
 */
int Figure::getSides() const{
    return this->_sides;//Se devuelve el valor
}

/**
 * @brief Figure::getName
 *  Metodo para devolver el valor que existe en la variable _name
 *  la cual corresponde a el nombre de la figura
 * @return _name
 */
std::string Figure::getName(){
    return this->_name;//Se devuelve el valor
}

/**
 * @brief Figure::setHeight
 *  Metodo para especificar y definir el alto de la figura
 * @param pHeight
 */
void Figure::setHeight(int pHeight){
    this->_height = pHeight;
}

/**
 * @brief Figure::setWidth
 *  Metodo para especificar y definir el ancho de la figura
 * @param pWidth
 */
void Figure::setWidth(int pWidth){
    this->_width = pWidth;
}

/**
 * @brief Figure::setSides
 *  Metodo para especificar y definir el numero de lados de la figura
 * @param pSides
 */
void Figure::setSides(int pSides){
    this->_sides = pSides;
}

/**
 * @brief Figure::setName
 *  Metodo para especificar y definir el nombre de la figura
 * @param pName
 */
void Figure::setName(std::string pName){
    this->_name = pName;
}

void Figure::setX(int pX){
    this->_posX = pX;
}
void Figure::setY(int pY){
    this->_posY = pY;
}
void Figure::setRadio(int pRadio){
    this->_radio = pRadio;
}
int Figure::getX() const{
    return this->_posX;//Se devuelve el valor
}
int Figure::getY() const{
    return this->_posY;//Se devuelve el valor
}
int Figure::getRadio() const{
    return this->_radio;//Se devuelve el valor
}
