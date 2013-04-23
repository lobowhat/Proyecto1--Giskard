#ifndef CHROMOSOME_H
#define CHROMOSOME_H

class Chromosome
{
public:
    Chromosome(); // constructor

    // convierte de binario a decimal
    unsigned long binaryToDecimal(unsigned long pNumber);

    // convierte de decimal a binario
    unsigned long decimalToBinary(unsigned long pNumber);

    // convierte el dato ingresado en un arreglo
    int *convertToArray(int pRvalue, int pGvalue, int pBvalue);

    // convierte un arreglo de 8 espacios en un nuevo arreglo de binarios
    int convertFromArray(int *pValue);

    // imprime un arreglo de cromosomas (24 espacios)
    void printChromosome() const;

    // getters y setters
    int getRValue();
    int getGValue();
    int getBValue();
    int *getChoromosomePtr();

private:

    static const int CHROMOSOME = 8; // tamaño de un cromosoma

    // tamaño del arreglo de RBG binario
    static const int RGBARRAY = 3 * CHROMOSOME;

    int _chromosome[RGBARRAY]; // arreglo con cromosomass

    unsigned long _result; // resultado

    // función de conversion
    unsigned long conversion(unsigned long pNumber, const char pFromBase,
                             const char pToBase);

    // convierte un decimal a arreglo binario
    void binaryArray(unsigned pValue, int *pArray);

    // función auxiliar para retornar valores en el arreglo
    int getDecimalFromArray(int pBegin);
};

#endif // CHROMOSOME_H
