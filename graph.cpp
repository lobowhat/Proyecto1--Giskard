#include "graph.h"


template<typename Data>
Graph<Data>::Graph()
{
    this->_graph = new DoubleCircularList<GraphNode<Data>*>();
    this->_length = 0;
}

template<typename Data>
Graph<Data>::~Graph(){
    free(this->_graph);
}

template<typename Data>
DoubleNode<GraphNode<Data>*>* Graph<Data>::getHeader(){
    return this->_graph->getHead();
}

template<typename Data>
int Graph<Data>::getCountNodes(){
    return this->_length;
}

template<typename Data>
DoubleCircularList<Connection<Data>*>* Graph<Data>::getListConnections(GraphNode<Data>* pNode){
    return pNode->getListConnection();
}

template<typename Data>
void Graph<Data>::insertNodes(Data pData){
    GraphNode<Data>* node = new GraphNode<Data>(pData);
    this->_graph->insertBegin(node);
    this->_length++;
}

template<typename Data>
void Graph<Data>::insertVertex(Data pData, Data pConection, int pWeight){
    GraphNode<Data>* destiny, *header = this->searchVertex(pData);
    if(header != 0){
        destiny = this->searchVertex(pConection);
        if(destiny != 0){
            Connection<Data>* connect = new Connection<Data>(destiny->getData(), pWeight);
            header->getConnectionList()->insertBegin(connect);
        }
        else{
            std::cout << "No existe el nodo de conexion en el grafo" << std::endl;
        }
    }
    else{
        std::cout << "No existe el nodo en el grafo" << std::endl;
    }
}

template<typename Data>
GraphNode<Data>* Graph<Data>::searchVertex(Data pData){
    DoubleNode<GraphNode<Data>*>* tmpNode = this->_graph->getHead();

    if(this->_length == 0){
        std::cout<<"Grafo vacio"<<std::endl;
        return 0;
    }

    while( tmpNode->getNext() != this->_graph->getHead() && ((GraphNode<Data>*)tmpNode->getData())->getData() != pData){
        tmpNode = tmpNode->getNext();
    }
    if(((GraphNode<Data>*)tmpNode->getData())->getData() == pData){
        return ((GraphNode<Data>*)tmpNode->getData());
    }
    return 0;
}

template<typename Data>
void Graph<Data>::printGraph(){
    DoubleNode<GraphNode<Data>*> *tmp = this->_graph->getHead();
    DoubleNode<Connection<Data>*>* connect;

    for (int i = 0; i < this->_graph->length(); ++i) {
        std::cout << "Nodo: " << ((GraphNode<Data>*)tmp->getData())->getData() << std::endl;
        connect = ((GraphNode<Data>*)tmp->getData())->getConnectionList()->getHead();
        std::cout << "Conexiones: ";

        for (int j = 0; j < ((GraphNode<Data>*)tmp->getData())->getConnectionList()->length(); ++j) {
            std::cout << ((Connection<Data>*)connect->getData())->getConnectNode() << " -> ";
            connect = connect->getNext();
        }
        tmp = tmp->getNext();
        std::cout << "NULL" << std::endl;
    }
}

template<typename Data>
int Graph<Data>::getWeight(Data pNode, Data pNodeConnected){
    GraphNode<Data>* searchedNode = this->searchVertex(pNode);

    DoubleCircularList<Connection<Data>*>* tmplist = searchedNode->getConnectionList();

    DoubleNode<Connection<Data>*>* tmpNode = tmplist->getHead();

    for (int i = 0; i < tmplist->length(); ++i) {
        if(((Connection<Data>*)tmpNode->getData())->getConnectNode() == pNodeConnected ){
            return ((Connection<Data>*)tmpNode->getData())->getWeight();
        }
        tmpNode = tmpNode->getNext();
    }

    return 0;
}

template<typename Data>
void Graph<Data>::setWeight(Data pNode, Data pNodeConnected, int pWeight){
    GraphNode<Data>* searchedNode = this->searchVertex(pNode);

    DoubleCircularList<Connection<Data>*>* tmplist = searchedNode->getConnectionList();

    DoubleNode<Connection<Data>*>* tmpNode = tmplist->getHead();

    for (int i = 0; i < tmplist->length(); ++i) {
        if(((Connection<Data>*)tmpNode->getData())->getConnectNode() == pNodeConnected ){
            ((Connection<Data>*)tmpNode->getData())->setWeight(pWeight);
            break;
        }
        tmpNode = tmpNode->getNext();
    }
}
