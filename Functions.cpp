#include "Functions.hpp"

int ts::FileReadToArray(std::string filenameOfInputFile, int array[size], int fullness = 0)
{
    std::ifstream in(filenameOfInputFile);

    if (!in)
    {
        std::cout << "File do not opened!\n";
        return -1;
    }
    else
    {
        for (int i = 0; !in.eof(); ++i)
        {
            in >> array[i];
            fullness++;
        }
        std::cout << "File copied to array!\n";
        return fullness;
    }
}

void ts::ArrayWriteToConsole(int array[size], int fullness)
{
    for (int i = 0; i < fullness; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std:: endl;
}

bool ts::IsPrime(int number) {

    if (number < 2) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    for (int i = 3; (i * i) <= number; i += 2) {
        if (number % i == 0) return false;
    }
    return true;
}

void ts::ArrayWriteToFile(std::string filenameOfOutputFile, int array[size], int fullness) {
    std::ofstream out(filenameOfOutputFile);
    if (!out)
    {
        std::cout << "File do not created!\n";
    }
    else
    {
        for (int i = 0; i < fullness; i++)
            out << array[i] << " ";
        std::cout << "Array writed to a file!\n";
    }
}
