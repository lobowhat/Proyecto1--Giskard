#ifndef BASECONVERSION_H
#define BASECONVERSION_H

class BaseConversion
{
public:
    BaseConversion(); // constructor

    // convierte de binario a decimal
    unsigned long binaryToDecimal(unsigned long pNumber);

    // convierte de decimal a binario
    unsigned long decimalToBinary(unsigned long pNumber);

    unsigned short *convertToArray();

    void printArray() const;

private:
    unsigned short p; // valores de potencia
    unsigned long result; // resultado
    unsigned short *arrayPtr; // puntero al arreglo equivalente del número

    // función de conversion
    unsigned long conversion(unsigned long pNumber, const char pFromBase,
                             const char pToBase);
};

#endif // BASECONVERSION_H
