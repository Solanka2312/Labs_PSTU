#include <iostream>
#include <windows.h>
#include "Money.h"
#include "VectorFloat.h"
#include "VectorMoney.h"
#include "VectorTemplate.h"
#include "StackMoney.h"
#include "StackContainer.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::cout << "Задача 1 (вектор float) " << std::endl;
    VectorFloat v1;
    int n, k;
    std::cout << "Введите размер вектора: ";
    std::cin >> n;
    v1.input(n);
    std::cout << "Вектор: ";
    v1.print();

    float avg = v1.srednee();
    std::cout << "Среднее арифметическое: " << avg << std::endl;

    std::cout << "Введите позицию для вставки (0-" << v1.size() << "): ";
    std::cin >> k;
    v1.addAtPosition(avg, k);
    std::cout << "После добавления: ";
    v1.print();

    v1.deleteMax();
    std::cout << "После удаления max: ";
    v1.print();

    v1.divideByMin();
    std::cout << "После деления на min: ";
    v1.print();
    std::cout << std::endl;

    std::cout << "Задача 2 (вектор Money) " << std::endl;
    VectorMoney v2;
    std::cout << "Введите размер вектора: ";
    std::cin >> n;
    v2.input(n);
    std::cout << "Вектор: ";
    v2.print();

    Money avgMoney = v2.srednee();
    std::cout << "Среднее арифметическое: " << avgMoney << std::endl;

    std::cout << "Введите позицию для вставки (0-" << v2.size() << "): ";
    std::cin >> k;
    v2.addAtPosition(avgMoney, k);
    std::cout << "После добавления: ";
    v2.print();

    v2.deleteMax();
    std::cout << "После удаления max: ";
    v2.print();

    v2.divideByMin();
    std::cout << "После деления на min: ";
    v2.print();
    std::cout << std::endl;

    std::cout << "Задача 3 (параметризированный класс VectorTemplate<Money>) " << std::endl;
    VectorTemplate<Money> v3;
    std::cout << "Введите размер вектора: ";
    std::cin >> n;
    v3.input(n);
    std::cout << "Вектор: ";
    v3.print();

    v3.addMinToEnd();
    std::cout << "После добавления минимального в конец: ";
    v3.print();
    std::cout << std::endl;

    std::cout << "Задача 4 (стек Money) " << std::endl;
    StackMoney s4;
    Money key;
    std::cout << "Введите размер стека: ";
    std::cin >> n;
    s4.input(n);
    std::cout << "Стек: ";
    s4.print();

    std::cout << "Введите ключ для удаления: ";
    std::cin >> key;
    s4.deleteByKey(key);
    std::cout << "После удаления: ";
    s4.print();
    std::cout << std::endl;

    std::cout << "Задача 5 (параметризированный класс StackContainer<Money>) " << std::endl;
    StackContainer<Money> s5;
    std::cout << "Введите размер стека: ";
    std::cin >> n;
    s5.input(n);
    std::cout << "Стек: ";
    s5.print();

    s5.addSumMinMaxToEach();
    std::cout << "После добавления суммы min+max к каждому элементу: ";
    s5.print();

    return 0;
}
