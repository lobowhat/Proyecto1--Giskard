/*
 * SNode.h
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#ifndef SIMPLENODE_H_
#define SIMPLENODE_H_

#include <iostream>
#include <stdlib.h>

template<typename E>
class SimpleNode {
private:
	E _data;
	// Valor del nodo.
	SimpleNode *_next;
	// Puntero al nodo siguiente.
public:
    //Constructor
	SimpleNode(const E& pData, SimpleNode* pNextNode);
    //Constructor secundario
	SimpleNode(SimpleNode* pNextNode);
    //Destructor
	virtual ~SimpleNode();
    //Define el nodo siguiente
	void setNext(SimpleNode* pNode);
    //Se obtiene el nodo siguiente
	SimpleNode * getNext();
    //Se obtiene el dato
	E getData();
};

#endif /* SIMPLENODE_H_ */
