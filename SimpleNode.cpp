/*
 * SimpleNode.cpp
 *
 *  Created on: 03/04/2013
 *      Author: jose
 */
#include "SimpleNode.h"

template<typename E>
/**
 * @brief SimpleNode<E>::SimpleNode
 *  Constructor de clase
 * @param pData
 * @param pNextNode
 */
SimpleNode<E>::SimpleNode(const E& pData, SimpleNode* pNextNode = NULL) {
	this->_data = pData;
	this->_next = pNextNode;
}

template<typename E>
/**
 * @brief SimpleNode<E>::SimpleNode
 *Constructor secundario
 * @param pNextNode
 */
SimpleNode<E>::SimpleNode(SimpleNode* pNextNode = NULL) {
	this->_data = 0;
	this->_next = pNextNode;
}

template<typename E>
/**
 * @brief SimpleNode<E>::~SimpleNode
 *Destructor
 */
SimpleNode<E>::~SimpleNode() {
	free(this->_next);
}

template<typename E>
/**
 * @brief SimpleNode<E>::setNext
 *Se defiene el puntero al siguiente nodo
 * @param pNode
 */
void SimpleNode<E>::setNext(SimpleNode* pNode) {
	this->_next = pNode;
}

template<typename E>
/**
 * @brief SimpleNode<E>::getNext
 *Se obtiene el puntero al siguiente nodo
 * @return _next
 */
SimpleNode<E> * SimpleNode<E>::getNext() {
	return this->_next;
}

template<typename E>
/**
 * @brief SimpleNode<E>::getData
 *Se obtiene el dato
 * @return _data
 */
E SimpleNode<E>::getData() {
	return this->_data;
}
