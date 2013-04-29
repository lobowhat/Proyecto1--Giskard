#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "graphnode.h"
#include "graphnode.cpp"

template<typename Data>
/**
 * @brief The Graph class
 *  Clase grafo la cual representa conexiones entre nodos
 *  y se define peso entre ellos.
 */
class Graph
{
private:
    DoubleCircularList<GraphNode<Data>*>* _graph;//Lista circular que posee los elementos
    int _length;//Tamaño del grafo

public:
    Graph();//Constructor
    ~Graph();//Destructor

    //Metodos
    int getCountNodes();//Regresa el tamaño del grafo
    void insertNodes(Data);//Inserta los nodos en orden
    void insertVertex(Data, Data, int);//Inserta el nodo y su coneccion
    DoubleNode<GraphNode<Data>*>* getHeader();//Se obtiene el nodo inicial
    GraphNode<Data> *searchVertex(Data);//Busca un nodo en el grafo
    DoubleCircularList<Connection<Data>*>* getListConnections(GraphNode<Data>*);//Se obtiene la lista de conecciones
    Data deleteNode(Data);//Se borra un nodo del grafo
    void deleteConnection(Data);//Permite borrar una coneccion.
    void printGraph();//Imprime el grafo.
    int getWeight(Data, Data);//Se obtiene el peso entre dos nodos
    void setWeight(Data, Data, int);//Se define el peso entre dos nodos
};

#endif // GRAPH_H
