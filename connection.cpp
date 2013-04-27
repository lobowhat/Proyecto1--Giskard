#include "connection.h"

template<typename Data>
/**
 * @brief Connection<Data>::Connection
 *  Constructor de la clase
 * @param pNode
 * @param pWeight
 */
Connection<Data>::Connection(Data pNode, int pWeight)
{
    this->_connectNode = pNode;
    this->_weight = pWeight;
}

template<typename Data>
/**
 * @brief Connection<Data>::~Connection
 *  Destructor de la clase
 */
Connection<Data>::~Connection(){
}

template<typename Data>
/**
 * @brief Connection<Data>::getConnectNode
 *  Se devuelve el dato con el que se encuentra conectado
 * @return _data
 */
Data Connection<Data>::getConnectNode()
{
    return _connectNode;
}

template<typename Data>
/**
 * @brief Connection<Data>::getWeight
 *  Se devuelve el peso entre los dos datos
 * @return _weight
 */
int Connection<Data>::getWeight(){
    return this->_weight;
}


template<typename Data>
/**
 * @brief Connection<Data>::setWeight
 *  Se define el peso entre los dos datos
 * @param pWeight
 */
void Connection<Data>::setWeight(int pWeight){
    this->_weight = pWeight;
}
