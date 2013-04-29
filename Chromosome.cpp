#include <cmath>
#include <iostream>
#include "Chromosome.h"

Chromosome::Chromosome()
{
    // empty body
}

unsigned long Chromosome::binaryToDecimal(unsigned long pNumber)
{
    return conversion(pNumber, 2, 10);
}

unsigned long Chromosome::decimalToBinary(unsigned long pNumber)
{
    return conversion(pNumber, 10, 2);
}

unsigned short *Chromosome::convertToArray(int pRvalue, int pGvalue, int pBvalue)
{
    const int size = 3;
    int temp[size] = {pRvalue, pGvalue, pBvalue};
    int pos = 0;
    int array[CHROMOSOME];
    int *tempPtr = array;

    for (int var = 0; var < size; ++var) {
        binaryArray(temp[var], tempPtr);
        for (int var2 = 0; var2 < CHROMOSOME; ++var2) {
            _chromosome[pos] = tempPtr[var2];
            pos++;
        }
    }

    return _chromosome;
}

void Chromosome::printChromosome() const
{
    std::cout << "INIT PRINT";
    for (int var = 0; var < RGBARRAY; ++var) {
        std::cout << "var: " << var ;
        std::cout << " _chromosome[var]: " << _chromosome[var] << std::endl;
        std::cout << _chromosome[var] << " ";
    }

    std::cout << "\n";
}

int Chromosome::getRValue()
{
    return getDecimalFromArray(0);
}

int Chromosome::getGValue()
{
    return getDecimalFromArray(8);
}

int Chromosome::getBValue()
{
    return getDecimalFromArray(16);
}

unsigned short *Chromosome::getChoromosomePtr()
{
    return _chromosome;
}

unsigned long Chromosome::conversion(unsigned long pNumber,
                                     const char pFromBase, const char pToBase)
{
    unsigned short p = 0; // valores de potencia
    _result = 0;

    while (pNumber > 0) {
        _result += ((pNumber % pToBase) * pow(pFromBase, p++));
        pNumber /= pToBase;
    }

    return _result;
}

void Chromosome::binaryArray(unsigned pValue, int* pArray)
{
    long temp = decimalToBinary(pValue);
    for (int var = CHROMOSOME - 1; var >= 0; --var) {
        pArray[var] = (int)(temp % 10);
        temp /= 10;
    }
}

int Chromosome::getDecimalFromArray(int pBegin)
{
    int temp = 0, pow = 7;
    for (int var = pBegin; var < pBegin + CHROMOSOME; ++var) {
        temp += _chromosome[var] * pow10(pow--);
    }
    return binaryToDecimal(temp);
}

