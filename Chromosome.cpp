#include <cmath>
#include <iostream>
#include "Chromosome.h"

Chromosome::Chromosome(int pRvalue, int pGvalue, int pBvalue)
    : _rValue(pRvalue), _gValue(pGvalue), _bValue(pBvalue)
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

int *Chromosome::convertToArray()
{
    const int size = 3;
    int temp[size] = {_rValue, _gValue, _bValue};
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
    for (int var = 0; var < RGBARRAY; ++var) {
        std::cout << _chromosome[var] << " ";
    }

    std::cout << "\n";
}

int Chromosome::getRValue() const
{
    return _rValue;
}

int Chromosome::getGValue() const
{
    return _gValue;
}

int Chromosome::getBValue() const
{
    return _bValue;
}

int *Chromosome::choromosomePtr()
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

int main()
{
    Chromosome p(245, 32, 45);
    p.convertToArray();
    p.printChromosome();
}
