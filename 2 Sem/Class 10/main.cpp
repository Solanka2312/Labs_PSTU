#include "Money.h"
#include "FileWork.h"
#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const char* filename = "money.txt";
    int choice;
    Money value;
    int k;

    do
    {
        std::cout << "МЕНЮ" << std::endl;
        std::cout << "1. Создать файл (запись)" << std::endl;
        std::cout << "2. Просмотреть файл" << std::endl;
        std::cout << "3. Удалить записи НЕ РАВНЫЕ заданному значению" << std::endl;
        std::cout << "4. Уменьшить записи с заданным значением в 2 раза" << std::endl;
        std::cout << "5. Добавить K записей в начало файла" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            makeFile(filename);
            break;

        case 2:
            printFile(filename);
            break;

        case 3:
            std::cout << "Введите значение для сравнения: ";
            std::cin >> value;
            deleteNotEqual(filename, value);
            break;

        case 4:
            std::cout << "Введите значение для уменьшения: ";
            std::cin >> value;
            halveEqual(filename, value);
            break;

        case 5:
            std::cout << "Сколько записей добавить в начало? ";
            std::cin >> k;
            addToBeginning(filename, k);
            break;

        case 0:
            std::cout << "Программа завершена." << std::endl;
            break;

        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
