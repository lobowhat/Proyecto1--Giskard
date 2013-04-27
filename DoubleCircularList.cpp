/*
 * DoubleCircularList.cpp
 *
 *  Created on: 03/04/2013
 *      Author: jose
 */
#include "DoubleCircularList.h"

template<typename E>
/**
 * @brief DoubleCircularList<E>::DoubleCircularList
 *  Constructor de la clase define el tamaño y punteros al inicio
 */
DoubleCircularList<E>::DoubleCircularList() {
    this->_head = this->_tail = NULL;
    this->_size = 0;
}

template<typename E>
/**
 * @brief DoubleCircularList<E>::~DoubleCircularList
 *  Destructor de la clase elimina la memoria
 */
DoubleCircularList<E>::~DoubleCircularList() {
    this->clear();//Limpia la lista
    free(this->_head);//Elimina la memoria no usada
    free(this->_tail);//Elimina la memoria no usada
}

template<typename E>
/**
 * @brief DoubleCircularList<E>::getHead
 *  Devuelve el primer elemento de la lista
 * @return _head
 */
DoubleNode<E>* DoubleCircularList<E>::getHead(){
    return this->_head;
}


template<typename E>
/**
 * @brief DoubleCircularList<E>::insertFinal
 *  Inserta un elemento dado en el final de lista
 * @param pData
 */
void DoubleCircularList<E>::insertFinal(const E& pData) {
    //Se inicializa un nodo doble con el dato
    DoubleNode<E>* nNode = new DoubleNode<E>(pData, NULL, NULL);

    //Verficar si la lista esta vacia
    if (this->_head == NULL) {
        //Se define el siguiente nodo como el mismo
        nNode->setNext(nNode);
        //Se define el anterior nodo como el mismo
        nNode->setPrevious(nNode);
        //El inicio y final son el mismo nodo
        this->_head = this->_tail = nNode;
        //Incremento en el tamaño de la lista
        this->_size++;
    }
    //Caso contrario
    else {
        //Se define como nodo anterior al anterior del nodo inicial
        nNode->setPrevious(this->_head->getPrevious());
        //Se definie como siguiente al nodo inicial
        nNode->setNext(this->_head);
        //El nodo previo del nodo inicial se le define como siguiente al nodo nuevo
        this->_head->getPrevious()->setNext(nNode);
        //El nodo inicial se le define como nodo previo al nuevo nodo
        this->_head->setPrevious(nNode);
        //El nodo inicial sera ahora el nuevo nodo
        this->_head = nNode;
        //Incremento en el tamaño de la lista
        this->_size++;
    }
}

template<typename E>
/**
 * @brief DoubleCircularList<E>::insertInOrder
 *  Se realizara una insercion en orden de los datos
 * @param pData
 */
void DoubleCircularList<E>::insertInOrder(const E& pData) {
    //Inicializacion del nodo nuevo
    DoubleNode<E>* nNode = new DoubleNode<E>(pData);
    //Se verifica si la lista esta vacia
    if (this->_head == NULL) {
        //Se define como nodo inicial
        this->_head = nNode;
        //El nodo previo es el mismo
        nNode->setPrevious(nNode);
        //El nodo siguiente es el mismo
        nNode->setNext(nNode);
        //Incremento en el tamaño de la lista
        this->_size++;
    } //Caso Contrario
    else {
        DoubleNode<E>* tmp = this->_head;//Se define un nodo temporal
        while (tmp->getData() < pData && tmp->getNext() != this->_head) {//Ciclo de busqueda de la posicion
            tmp = tmp->getNext();//Movimiento de referencias
        }
        //Se verifica si el nodo siguiente el inicial y si el dato es mayor al del nodo temporal
        if (tmp->getNext() == this->_head && tmp->getData() < pData) {
            //Se define el nodo siguiente del nodo nuevo
            nNode->setNext(tmp->getNext());
            //Se define el nodo previo del nodo nuevo
            nNode->setPrevious(tmp);
            //Se define el nodo previo del siguiente al temporal
            tmp->getNext()->setPrevious(nNode);
            //Se define el nodo siguiente del temporal
            tmp->setNext(nNode);
            //Incremento en el tamaño de la lista
            this->_size++;
        } //Caso contrario
        else {
            //Se define el nodo siguiente
            nNode->setNext(tmp);
            //Se define el nodo previo
            nNode->setPrevious(tmp->getPrevious());
            //Se define el nodo siguiente del anterior al temporal
            tmp->getPrevious()->setNext(nNode);
            //Se define el nodo anterior del nodo temporal
            tmp->setPrevious(nNode);
            //Incremento en le tamaño
            this->_size++;
        }
    }
}

template<typename E>
/**
 * @brief DoubleCircularList<E>::insertBegin
 *  Se realiza una insercion al inicio de la lista dado un dato
 * @param pData
 */
void DoubleCircularList<E>::insertBegin(const E &pData){
    //Se inicializa un nuevo nodo a insertar
    DoubleNode<E>* nNodo = new DoubleNode<E>(pData);
    //Se verifica si la lista esta vacia
    if (this->_head == NULL)
    {
        //Se define el nodo previo
        nNodo->setPrevious(nNodo);
        //Se define el nodo siguiente
        nNodo->setNext(nNodo);
        //Inicio y final son el mismo dato
        this->_head = this->_tail = nNodo;
        //Incremento en el tamaño de la lista
        this->_size++;
    }
    else
    {
        //Se define el nodo previo
        nNodo->setPrevious(this->_head->getPrevious());
        //Se define el nodo siguiente
        nNodo->setNext(this->_head);
        //Se define el nodo siguiente del nodo previo al inicio
        this->_head->getPrevious()->setNext(nNodo);
        //Se define el nodo previo del nodo inicial
        this->_head->setPrevious(nNodo);
        //El inicio sera el nodo nuevo
        this->_head = nNodo;
        //Incremento en el tamaño de la lista
        this->_size++;
    }
}

template<typename E>
/**
 * @brief DoubleCircularList<E>::deleteSpecific
 *  Borrado especifico de un dato dado luego devuelve el dato para casos de verificacion del borrado.
 * @param pData
 * @return _dato
 */
E DoubleCircularList<E>::deleteSpecific(const E& pData) {
    //Caso de la lista vacia
    if (this->_head == NULL) {
        //Se devuleve un dato nulo
        return 0;
    }
    else if (this->_head->getNext() == this->_head) {
        //Se obtiene el dato a devolver
        E tmpData = this->_head->getData();
        //Se define un nodo temporal
        DoubleNode<E>* tmp = this->_head;
        //Se define nulo el nodo inicial
        this->_head = NULL;
        //Se libera la memoria
        free(tmp);
        //Decrecimiento en el tamaño de la lista
        this->_size--;
        //Se devuelve el dato
        return tmpData;
    }//Caso de que el dato sea el del inicio
    else if (this->_head->getData() == pData) {
        //Se obtiene el dato a devolver
        E tmpData = this->_head->getData();
        //Se define un nodo temporal
        DoubleNode<E>* tmp = this->_head;
        //Se define un nodo previo
        this->_head->getNext()->setPrevious(this->_head->getPrevious());
        //se define un nodo siguiente
        this->_head->getPrevious()->setNext(this->_head->getNext());
        //Se mueve referencias
        this->_head = this->_head->getNext();
        //Se libera la memoria
        free(tmp);
        //Decrecimiento en el tamaño de la lista
        this->_size--;
        //Se devuelve el dato
        return tmpData;

    } else {
        //Se define un nodo temporal
        DoubleNode<E>* tmp = this->_head;
        while (tmp->getNext() != this->_head && tmp->getData() != pData) {
            tmp = tmp->getNext();
        }
        if (tmp->getData() == pData) {
            //Se obtiene el dato a devolver
            E tmpData = tmp->getData();
            //Se define un nodo siguiente
            tmp->getPrevious()->setNext(tmp->getNext());
            //Se define un nodo previo
            tmp->getNext()->setPrevious(tmp->getPrevious());
            //Se libera la memoria
            free(tmp);
            //Decrecimiento en el tamaño de la lista
            this->_size--;
            return tmpData;
        } else {
            return 0;
        }
    }
}

template<typename E>
/**
 * @brief DoubleCircularList<E>::deleteFirst
 *  Borrado de la lista del elemento inicial
 *  Luego devuelve el dato
 * @return _data
 */
E DoubleCircularList<E>::deleteFirst() {
    //Caso de ser la lista vacia
    if(_head == NULL){
        return 0;//Se devuelve el dato nulo
    }else{
        //Se verifica si los nodos inicial y final sean iguales
        if(_head == _tail){
            //Se define un nodo temporal
            DoubleNode<E>* tmp = _head;
            //Se obtiene el dato a devolver
            E returnData = tmp->getData();
            //Ambos nodos seran nulos
            _head = _tail = NULL;
            //Se libera la memoria
            free(tmp);
            //Decrecimiento en el tamaño de la lista
            this->_size--;
            //Se devuelve el dato
            return returnData;
        }else{
            //Se obtiene el dato a devolver
            E returnData = _head->getData();
            //Se define un nodo temporal
            DoubleNode<E>* tmp = _head;
            //Se define el nodo previo y siguiente
            this->_head->getNext()->setPrevious(this->_tail);
            this->_tail->setNext(this->_head);
            //Se mueven referencias
            this->_head = this->_head->getNext();
            free(tmp);
            //Decrecimiento en el tamaño de la lista
            this->_size--;
            //Se devuelve el dato
            return returnData;
        }
    }
}

template<typename E>
/**
 * @brief DoubleCircularList<E>::deleteFinal
 *  Borramos el nodo final y luego de hacerlo devolvemos el dato eliminado
 * @return _data
 */
E DoubleCircularList<E>::deleteFinal() {
    if(_head == NULL){
        //Caso de ser vacia la lista
        return 0;//Devolvemos un valor nulo
    }
    else{
        if(_head == _tail){
            //Se define un nodo temporal
            DoubleNode<E>* tmp = _head;
            //Se obtiene el dato a devolver
            E returnData = tmp->getData();
            //Ambos nodos seran nulos
            _head = _tail = NULL;
            //Se libera la memoria
            free(tmp);
            //Decrecimiento en el tamaño de la lista
            this->_size--;
            //Se devuelve el dato
            return returnData;
        }
        else{
            //Obtenemos el dato a devolver
            E returnData = _tail->getData();
            //Se define como temporal el nodo final
            DoubleNode<E>* tmp = _tail;
            //Movemos referencia del nodo final
            _tail = _tail->getPrevious();
            //Se definen nodos previos y siguientes
            this->_tail->setNext(this->_head);
            this->_head->setPrevious(this->_tail);
            //Liberamos la memoria
            free(tmp);
            //Decrecimiento en el tamaño de la lista
            this->_size--;
            //Se devuelve el dato
            return returnData;
        }
    }
}

template<typename E>
/**
 * @brief DoubleCircularList<E>::length
 *  Obtenemos el tamaño de la lista
 * @return _size
 */
int DoubleCircularList<E>::length() const {
    return this->_size;
}

template<typename E>
/**
 * @brief DoubleCircularList<E>::clear
 *  Metodo para limpiar la lista
 */
void DoubleCircularList<E>::clear() {
    while(this->_head != NULL){//Ciclo para eliminar los datos
        this->_tail = this->_head;//Usamos el nodo final como referencia para eliminar
        this->_head = this->_head->getNext();//Movimiento de referencias
        free(this->_tail);//Liberar la memoria
    }
    this->_head = this->_tail = NULL;//Declaramos nulo a ambos nodos
    this->_size = 0;//Tamaño de la lista como al inicio
}


template<typename E>
/**
 * @brief DoubleCircularList<E>::search
 *  Se realiza un ciclo de busqueda sequencia en la lista para encontrar
 *  si existe el dato o no.
 * @param pData
 * @return _data
 */
E DoubleCircularList<E>::search(E pData){
    //Nodo temporal
    DoubleNode<E>* tmp = this->_head;
    //Caso de que la lista este vacia
    if (tmp == NULL) {
        return 0;//Devolvemos un dato nulo
    }
    while (tmp->getNext() != this->_head && tmp->getData() != pData) {//Ciclo de busqueda
        tmp = tmp->getNext();//Movimiento de referencias
    }
    //Verificar si se obtuvo el dato
    if (tmp->getData() == pData) {
        return pData;//Devolver el dato
    } else {
        return 0;//Caso de que no se encuentre se devuelve nulo
    }
}
