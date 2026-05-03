#include "Task1.h"
#include <iostream>
#include <algorithm>
#include <numeric>

void task1()
{
    std::cout << "Задача 1 (вектор Money) " << std::endl;

    std::vector<Money> v;
    int n, k;
    Money val;

    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Элемент " << i + 1 << ": ";
        std::cin >> val;
        v.push_back(val);
    }

    std::cout << "Вектор: ";
    for (const auto& x : v) std::cout << x << " ";
    std::cout << std::endl;

    Money sum;
    for (const auto& x : v) sum = sum + x;
    Money avg = sum / v.size();
    std::cout << "Среднее арифметическое: " << avg << std::endl;

    std::cout << "Введите позицию k (0-" << v.size() << "): ";
    std::cin >> k;
    if (k >= 0 && k <= (int)v.size())
        v.insert(v.begin() + k, avg);
    else
        std::cout << "Неверная позиция!" << std::endl;

    std::cout << "После добавления среднего: ";
    for (const auto& x : v) std::cout << x << " ";
    std::cout << std::endl;

    if (!v.empty())
    {
        auto maxIt = std::max_element(v.begin(), v.end());
        std::cout << "Удаляем максимальный элемент: " << *maxIt << std::endl;
        v.erase(maxIt);
    }

    std::cout << "После удаления максимального: ";
    for (const auto& x : v) std::cout << x << " ";
    std::cout << std::endl;

    if (!v.empty())
    {
        auto minIt = std::min_element(v.begin(), v.end());
        Money minVal = *minIt;
        std::cout << "Минимальный элемент: " << minVal << std::endl;

        for (auto& x : v)
            x = x / 2;
    }

    std::cout << "После деления на минимальный: ";
    for (const auto& x : v) std::cout << x << " ";
    std::cout << std::endl << std::endl;
}