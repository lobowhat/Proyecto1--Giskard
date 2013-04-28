#ifndef CONNECTION_H
#define CONNECTION_H

template<typename Data>
/**
 * @brief The Connection class
 *  Clase definida para realizar las conexiones en un grafo
 */
class Connection
{
private:
    //Dato conectado
    Data _connectNode;
    //Peso de la conexion
    int _weight;

public:
    //Constructor
    Connection(Data, int);
    //Destructor
    ~Connection();
    //Definicion del peso
    void setWeight(int);
    //Obtencion del peso
    int getWeight();
    //Obtencion de la conexion
    Data getConnectNode();
};

#endif // CONNECTION_H
