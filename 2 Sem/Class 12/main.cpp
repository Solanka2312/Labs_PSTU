#include <iostream>
#include <windows.h>
#include "Money.h"
#include "Task1.h"
#include "Task2.h"
#include "MapContainer.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    task1();
    task2();

    std::cout << "Задача 3 (параметризированный класс MapContainer<int, Money>) " << std::endl;
    MapContainer<int, Money> mc;
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    mc.input(n);

    std::cout << "Исходный контейнер:" << std::endl;
    mc.print();

    mc.addMinToEnd();
    std::cout << "!ЗАДАНИЕ 3: После добавления минимального в конец!" << std::endl;
    mc.print();

    int delKey;
    std::cout << "!ЗАДАНИЕ 4: Введите ключ для удаления: ";
    std::cin >> delKey;
    mc.deleteByKey(delKey);
    std::cout << "После удаления:" << std::endl;
    mc.print();

    mc.addSumMinMaxToEach();
    std::cout << "!ЗАДАНИЕ 5: После добавления суммы min+max к каждому элементу" << std::endl;
    mc.print();

    return 0;
}
