#include "Task2.h"
#include <iostream>
#include <vector>

void task2()
{
    std::cout << "Задача 2 (адаптер контейнера - очередь) " << std::endl;

    std::queue<Money> q;
    int n;
    Money val;

    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Элемент " << i + 1 << ": ";
        std::cin >> val;
        q.push(val);
    }

    std::cout << "Очередь (от начала к концу): ";
    std::queue<Money> temp1 = q;
    while (!temp1.empty())
    {
        std::cout << temp1.front() << " ";
        temp1.pop();
    }
    std::cout << std::endl;

    Money low, high;
    std::cout << "Введите нижнюю границу диапазона: ";
    std::cin >> low;
    std::cout << "Введите верхнюю границу диапазона: ";
    std::cin >> high;

    std::vector<Money> tempVec;
    while (!q.empty())
    {
        Money front = q.front();
        q.pop();
        if (!(front >= low && front <= high))
            tempVec.push_back(front);
    }

    for (const auto& x : tempVec)
        q.push(x);

    std::cout << "После удаления элементов из диапазона [" << low << ", " << high << "]: ";
    std::queue<Money> temp2 = q;
    while (!temp2.empty())
    {
        std::cout << temp2.front() << " ";
        temp2.pop();
    }
    std::cout << std::endl << std::endl;
}