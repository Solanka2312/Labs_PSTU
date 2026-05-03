#include "Set.h"
#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "Исключение в конструкторе (размер > MAX_SIZE=30) "<< std::endl;
    try
    {
        Set largeSet(35);
        std::cout << "Множество создано" << std::endl;
    }
    catch (int e)
    {
        if (e == 1)
            std::cout << "Исключение 1: попытка создать множество размером больше MAX_SIZE!" << std::endl;
        else
            std::cout << "Исключение: " << e << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Нормальная работа с множеством " << std::endl;
    Set A(10);
    A.add(5);
    A.add(10);
    A.add(15);
    A.add(20);
    std::cout << "A = " << A << std::endl;
    std::cout << "Размер A: " << (int)A << std::endl;
    std::cout << "A[1] = " << A[1] << std::endl;
    std::cout << std::endl;

    std::cout << "Исключение в operator[] (индекс < 0) " << std::endl;
    try
    {
        std::cout << "Попытка обратиться к A[-1]" << std::endl;
        int val = A[-1];
        std::cout << "Значение: " << val << std::endl;
    }
    catch (int e)
    {
        if (e == 2)
            std::cout << "Исключение 2: индекс меньше 0!" << std::endl;
        else
            std::cout << "Исключение: " << e << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Исключение в operator[] (индекс >= size) " << std::endl;
    try
    {
        std::cout << "Попытка обратиться к A[10] (size=" << (int)A << ")" << std::endl;
        int val = A[10];
        std::cout << "Значение: " << val << std::endl;
    }
    catch (int e)
    {
        if (e == 3)
            std::cout << "Исключение 3: индекс больше или равен текущему размеру!" << std::endl;
        else
            std::cout << "Исключение: " << e << std::endl;
    }
    std::cout << std::endl;


    std::cout << "Исключение в operator-- (удаление из пустого множества) ---" << std::endl;
    Set emptySet;
    std::cout << "Пустое множество: " << emptySet << std::endl;
    try
    {
        std::cout << "Попытка удалить элемент из пустого множества" << std::endl;
        --emptySet;
    }
    catch (int e)
    {
        if (e == 4)
            std::cout << "Исключение 4: попытка удалить элемент из пустого множества!" << std::endl;
        else
            std::cout << "Исключение: " << e << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Демонстрация всех операций " << std::endl;
    Set B;
    B.add(5);
    B.add(10);
    B.add(20);
    B.add(25);
    std::cout << "B = " << B << std::endl;

    Set C = A * B;
    std::cout << "C = A * B = " << C << std::endl;

    std::cout << "Удаление первого элемента (--B): ";
    --B;
    std::cout << B << std::endl;

    std::cout << "Удаление последнего элемента (B--): ";
    B--;
    std::cout << B << std::endl;

    return 0;
}
