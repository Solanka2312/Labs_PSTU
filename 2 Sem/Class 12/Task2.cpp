#include "Task2.h"
#include <iostream>

void task2()
{
    std::cout << "Задача 2 (map int, Money) " << std::endl;

    std::map<int, Money> m;
    int n, key;
    Money val;

    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Ключ: ";
        std::cin >> key;
        std::cin >> val;
        m[key] = val;
    }

    std::cout << "Словарь: " << std::endl;
    for (const auto& p : m)
        std::cout << p.first << " -> " << p.second << std::endl;

    Money sum;
    for (const auto& p : m)
        sum = sum + p.second;
    Money avg = sum / m.size();
    std::cout << "Среднее арифметическое: " << avg << std::endl;

    int k;
    std::cout << "Введите ключ для вставки среднего: ";
    std::cin >> k;
    m[k] = avg;

    std::cout << "После добавления среднего:" << std::endl;
    for (const auto& p : m)
        std::cout << p.first << " -> " << p.second << std::endl;

    if (!m.empty())
    {
        auto maxIt = m.end();
        --maxIt;
        std::cout << "Удаляем максимальный элемент: ключ " << maxIt->first
            << " значение " << maxIt->second << std::endl;
        m.erase(maxIt);
    }

    std::cout << "После удаления максимального:" << std::endl;
    for (const auto& p : m)
        std::cout << p.first << " -> " << p.second << std::endl;

    if (!m.empty())
    {
        std::cout << "После деления на 2:" << std::endl;
        for (auto& p : m)
        {
            p.second = p.second / 2;
            std::cout << p.first << " -> " << p.second << std::endl;
        }
    }
    std::cout << std::endl;
}