#include "baseconversion.h"

BaseConversion::BaseConversion()
    : p(0), result(0)
{
    // empty body
}

int BaseConversion::binaryToDecimal(int pNumber)
{
    while (pNumber > 0) {
        result += ((pNumber % 10) * pow(2, p++));
        pNumber /= 10;
    }

    return result;
}


int BaseConversion::decimalToBinary(int pNumber)
{
    while (pNumber > 0) {
        result += ((pNumber % 2) * pow10(p++));
        pNumber /= 2;
    }

    return result;
}
