#include "graphnode.h"

template<typename Data>
/**
 * @brief GraphNode<Data>::GraphNode
 *  Constructor de la clase
 * @param pData
 */
GraphNode<Data>::GraphNode(Data pData)
{
    this->_data = pData;//Se define el dato
    this->_connectionList = new DoubleCircularList<Connection<Data>*>();//Se inicializa la lista
}

template<typename Data>
/**
 * @brief GraphNode<Data>::~GraphNode
 *  Destructor de la clase
 */
GraphNode<Data>::~GraphNode(){
    free(this->_connectionList);//Liberamos la memoria
}

template<typename Data>
/**
 * @brief GraphNode<Data>::getData
 *  Metodo para obtener el dato almacenado
 * @return _data
 */
Data GraphNode<Data>::getData(){
    //Se devuelve el dato
    return this->_data;
}

template<typename Data>
/**
 * @brief GraphNode<Data>::getConnectionList
 *  Metodo que devuelve la lista de conexiones que existen en este nodo
 * @return _connectionList
 */
DoubleCircularList<Connection<Data> *> *GraphNode<Data>::getConnectionList(){
    return this->_connectionList;//se obtiene la lista
}

template<typename Data>
/**
 * @brief GraphNode<Data>::setData
 *  Metodo que define el dato almacenado
 * @param pData
 */
void GraphNode<Data>::setData(Data pData){
    this->_data = pData; //se define el dato
}
