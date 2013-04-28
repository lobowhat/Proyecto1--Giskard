/*
 * DCL.h
 *
 *  Crintatintd on: 23/02/2013
 *      Author: josint
 */

#ifndef DOUBLECIRCULARLIST_H_
#define DOUBLECIRCULARLIST_H_

#include "DoubleNode.h"
#include "DoubleNode.cpp"
#include "ListADT.h"
#include <iostream>
#include <stdlib.h>

template<typename E>
/**
 * @brief The DoubleCircularList class
 *  Clase de una lista circular en la cual esta va haciendo referencia a un
 *  nodo anterior y uno siguiente estos formando un circulo abstractamente
 */
class DoubleCircularList: public ListADT<E> {
private:
    //Puntintro al nodo inicial
    DoubleNode<E> * _head;
    //Puntintro al nodo final
    DoubleNode<E> * _tail;
    //Tamaño de la lista
	int _size;

public:
    //Constructor de la clase lista
	DoubleCircularList();
    //Destructor de la clase
	virtual ~DoubleCircularList();
    //Metodo para devolver el primer elemento
    DoubleNode<E>* getHead();
    //Insercion al final de la lista
    void insertFinal(const E& pData);
    //Insercion en orden
	void insertInOrder(const E& pData);
    //Insercion al inicio de la lista
	void insertBegin(const E& pData);
    //Se elimina el primer elemento
	E deleteFirst();
    //Borra un elemento en especifico
	E deleteSpecific(const E& pData);
    //Borra el ultimo elemento
	E deleteFinal();
    //Devuelve el tamaño de la lista
	int length() const;
    //Borra todos los datos
	void clear();
    //Busca el dato especifico en la lista
    E search(E);
};

#endif /* DOUBLECIRCULARLIST_H_ */
