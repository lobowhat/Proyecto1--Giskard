#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include "DoubleCircularList.h"
#include "DoubleCircularList.cpp"
#include "connection.h"
#include "connection.cpp"

template<typename Data>
/**
 * @brief The GraphNode class
 *  Clase hecha para tener una lista de conexiones y datos almacenados
 */
class GraphNode
{
private:
    //Dato almacenado
    Data _data;
    //Lista de conexiones
    DoubleCircularList<Connection<Data>*>* _connectionList;

public:
    //Constructor
    GraphNode(Data);
    //Destructor
    ~GraphNode();
    //Se obtiene el dato del nodo
    Data getData();
    //Se obtiene la lista de conexiones
    DoubleCircularList<Connection<Data>*>* getConnectionList();
    //Se define el dato
    void setData(Data);

};

#endif // GRAPHNODE_H
