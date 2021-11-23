//Задача №5
//«Удаление и дублирование»
//
//Реализуйте задачу с использованием простого массива.
//
//Сначала введите последовательность в массив. Затем удалите и продублируйте элементы. Затем выведите полученную
//последовательность (каждый элемент по одному разу). Используйте в программе только один массив, функции и процедуры.
//
//Вариант-1.
//Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). Удалить из последовательности простые числа и
//продублировать составные числа, сумма цифр которых равна 15.

#include <iostream>
#include "Functions.hpp"


void MoveRightAllAfterI(int array[size], int a, int fullness)
{
    for (int i = fullness*2; i > a-1; i--)
    {
        array[i+1] = array[i];
        ts::ArrayWriteToConsole(array, fullness);
    }
}

int main()
{
    int array[size];
    int fullness = 0;
    fullness = ts::FileReadToArray(filenameOfInputFile, array, fullness);
    if (fullness == -1)
        return -1;
    ts::ArrayWriteToConsole(array, fullness);
    for (int i = 0; i < fullness; ++i)
    {
        if (ts::IsPrime(array[i]))
        {
            std::cout << "prime: " << array[i] << std::endl;
        }
    }


    //Простые числа скипать
    int c = 0;
    int fullnessBefore = fullness;
    for (int i = 0; i < fullnessBefore; i++)
    {
        if (ts::IsPrime(array[i]))
            fullness--;
        if (!ts::IsPrime(array[i]))
        {
            array[c] = array[i];
            c++;
        }
    }
    //std::cout << fullness << std::endl;


    //Если число составное, то его продублировать
    fullnessBefore = fullness*2;
    for (int i = 0; i < fullnessBefore; i+=2)
        if (!ts::IsPrime(array[i]))
        {
            //std::cout << "NEW NUMBER!" << std::endl;
            MoveRightAllAfterI(array, i, fullness);
            fullness++;

        }

    std::cout << "After:\n";


    ts::ArrayWriteToConsole(array, fullness);

    ts::ArrayWriteToFile(filenameOfOutputFile, array, fullness);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
