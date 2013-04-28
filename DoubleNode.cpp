/*
 * DoubleNode.cpp
 *
 *  Created on: 03/04/2013
 *      Author: jose
 */
#include "DoubleNode.h"


template<typename E>
/**
 * @brief DoubleNode<E>::DoubleNode Constructor principal de la clase
 * @param pData
 * @param pNextNode
 * @param pPreviosNode
 */
DoubleNode<E>::DoubleNode(const E& pData, DoubleNode* pNextNode,
		DoubleNode* pPreviosNode) {
    this->_data = pData;//Se define el dato
    this->_next = pNextNode;//Se define el puntero al siguiente nodo
    this->_previous = pPreviosNode;//Se define el puntero al anterior nodo
}

template<typename E>
/**
 * @brief DoubleNode<E>::DoubleNode Constructor Secundario
 * @param pNextNode
 * @param pPreviousNode
 */
DoubleNode<E>::DoubleNode(DoubleNode* pNextNode, DoubleNode* pPreviousNode) {
	this->_data = 0;
	this->_next = pNextNode;
	this->_previous = pPreviousNode;
}

template<typename E>
/**
 * @brief DoubleNode<E>::~DoubleNode
 *  Destructor de la clase
 */
DoubleNode<E>::~DoubleNode() {
}

template<typename E>
/**
 * @brief DoubleNode<E>::getNext
 *  Devuelve el puntero del nodo siguiente
 * @return _next
 */
DoubleNode<E> * DoubleNode<E>::getNext() {
	return this->_next;
}

template<typename E>
/**
 * @brief DoubleNode<E>::getPrevious
 *  Devuelve el puntero al nodo anterior
 * @return  _previous
 */
DoubleNode<E> * DoubleNode<E>::getPrevious() {
	return this->_previous;
}

template<typename E>
/**
 * @brief DoubleNode<E>::setNext
 *  Define el puntero al nodo siguiente
 * @param pNode
 */
void DoubleNode<E>::setNext(DoubleNode* pNode) {
	this->_next = pNode;
}

template<typename E>
/**
 * @brief DoubleNode<E>::setPrevious
 *  Define el puntero al nodo anterior
 * @param pNode
 */
void DoubleNode<E>::setPrevious(DoubleNode* pNode) {
	this->_previous = pNode;
}

template<typename E>
/**
 * @brief DoubleNode<E>::getData
 *  Devuelve el dato almacenado dentro del nodo
 * @return _data
 */
E DoubleNode<E>::getData() {
	return this->_data;
}
