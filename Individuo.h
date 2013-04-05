#ifndef INDIVIDUO_H
#define INDIVIDUO_H

class Individuo
{
public:
    Individuo(int pId,unsigned short pCromosoma);//constructor
    ~Individuo();//destructor

//***** GETTERS Y SETTERS *****
    unsigned short getCromosoma();
    int getId();
    void setFitness(double pFitness);
    void setId(int id);
    void setSiguiente(Individuo *siguiente);
    Individuo * getSiguiente();
    void setCromosoma(unsigned short pCromosoma);
    int getPadre();
    int getMadre();
    void setPadre(int pPadre);
    void setMadre(int pMadre);
    int  getGeneracion();
    void setGeneracion(int pGeneracion);
private:
    unsigned short _cromosoma; // cromosoma, un cromosoma esta formado por 32 genes
    int _id; // Identificador del individuo
    double _valorFitness; // valor de su funcion de fitness
    Individuo * _siguiente;
    int _padre;
    int _madre;
    int _generacion;
};

#endif // INDIVIDUO_H
