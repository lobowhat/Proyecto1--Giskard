/*
 * DNode.h
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#ifndef DNODE_H_
#define DNODE_H_
#include <iostream>
#include "DoubleCircularList.h"

template<typename E>
class DoubleNode {
private:
    // Valor del nodo
	E _data;
    // Puntero al nodo anterior
	DoubleNode<E> *_next;
    //Puntero al nodo anterior
	DoubleNode<E> *_previous;

public:
    //Constructor
    DoubleNode(const E& pData, DoubleNode* pNextNode = NULL, DoubleNode* pPreviosNode = NULL);
    //Constructor Secundario
    DoubleNode(DoubleNode* pNextNode = NULL, DoubleNode* pPreviousNode = NULL);
    //Detructor
    virtual ~DoubleNode();
    //Se obtiene el siguiente nodo
    DoubleNode<E> * getNext();
    //Se obtiene el anterior nodo
    DoubleNode<E> * getPrevious();
    //Se define el nodo siguiente
    void setNext(DoubleNode<E>* pNode);
    //Se define el nodo anterior
    void setPrevious(DoubleNode<E>* pNode);
    //Se obtiene el dato almacenado
    E getData();
};

#endif /* DNODE_H_ */

