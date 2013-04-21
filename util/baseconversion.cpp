#include <cmath>
#include <string>
#include <iostream>

#include "baseconversion.h"

BaseConversion::BaseConversion()
{
    // empty body
}

unsigned long BaseConversion::binaryToDecimal(unsigned long pNumber)
{
    return conversion(pNumber, 2, 10);
}

unsigned long BaseConversion::decimalToBinary(unsigned long pNumber)
{
    return conversion(pNumber, 10, 2);
}

unsigned short *BaseConversion::convertToArray()
{
//    char* num = result + '';
    return arrayPtr;
}

void BaseConversion::printArray() const
{
    std::cout << "ppp: " << p << std::endl;
    for (int var = p - 1; var > 0; var--) {
        std::cout << arrayPtr[var] << " ";
    }

}

unsigned long BaseConversion::conversion(unsigned long pNumber, const char pFromBase, const char pToBase)
{
    p = 0;
    result = 0;

    while (pNumber > 0) {
        result += ((pNumber % pToBase) * pow(pFromBase, p++));
        pNumber /= pToBase;
    }

    return result;
}

//int main()
//{
//    BaseConversion p;
//    std::cout << (p.decimalToBinary(1000)) << std::endl;
//    std::cout << (p.binaryToDecimal(10)) << std::endl;
//    p.convertToArray();
//    p.printArray();
//}
