#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Constants.hpp"


namespace ts
{
    int FileReadToArray(std::string filenameOfInputFile, int array[size], int fullness);

    void ArrayWriteToConsole(int array[size], int fullness);

    bool IsPrime(int number);

    void ArrayWriteToFile(std::string filenameOfOutputFile, int array[size], int fullness);
}