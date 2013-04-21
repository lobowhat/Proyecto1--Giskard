#ifndef BASECONVERSION_H
#define BASECONVERSION_H

class BaseConversion
{
public:
    BaseConversion(); // constructor
    int binaryToDecimal(int pNumber); // convierte de binario a decimal
    int decimalToBinary(int pNumber); // convierte

private:
    int p; // valores de potencia
    int result; // resultado
};

#endif // BASECONVERSION_H
