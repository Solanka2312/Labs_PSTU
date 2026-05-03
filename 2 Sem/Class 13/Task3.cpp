#include "Task3.h"
#include <iostream>
#include <algorithm>
#include <vector>

void task3()
{
    std::cout << "Задача 3 (ассоциативный контейнер - словарь map<int, Money>) " << std::endl;

    std::map<int, Money> m;
    int n, key;
    Money val;

    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите ключ и значение " << i + 1 << ": ";
        std::cin >> key >> val;
        m[key] = val;
    }

    std::cout << "Словарь:" << std::endl;
    for (const auto& p : m)
        std::cout << p.first << " -> " << p.second << std::endl;

    if (!m.empty())
    {
        Money minVal = m.begin()->second;
        for (const auto& p : m)
            if (p.second < minVal) minVal = p.second;

        int newKey = m.rbegin()->first + 1;
        m[newKey] = minVal;

        std::cout << "! ЗАДАНИЕ 3 !" << std::endl;
        std::cout << "Минимальный элемент: " << minVal << std::endl;
        std::cout << "Добавлен в конец с ключом " << newKey << std::endl;
        std::cout << "Словарь после добавления:" << std::endl;
        for (const auto& p : m)
            std::cout << p.first << " -> " << p.second << std::endl;
    }

    int delKey;
    std::cout << "! ЗАДАНИЕ 4 !" << std::endl;
    std::cout << "Введите ключ для удаления: ";
    std::cin >> delKey;

    auto it = m.find(delKey);
    if (it != m.end())
    {
        std::cout << "Удаляем элемент с ключом " << delKey << ": " << it->second << std::endl;
        m.erase(it);
    }
    else
    {
        std::cout << "Элемент с ключом " << delKey << " не найден." << std::endl;
    }

    std::cout << "Словарь после удаления:" << std::endl;
    for (const auto& p : m)
        std::cout << p.first << " -> " << p.second << std::endl;

    if (!m.empty())
    {
        Money minVal = m.begin()->second;
        Money maxVal = m.begin()->second;
        for (const auto& p : m)
        {
            if (p.second < minVal) minVal = p.second;
            if (p.second > maxVal) maxVal = p.second;
        }

        Money sum = minVal + maxVal;

        std::cout << "! ЗАДАНИЕ 5 !" << std::endl;
        std::cout << "Минимальный элемент: " << minVal << std::endl;
        std::cout << "Максимальный элемент: " << maxVal << std::endl;
        std::cout << "Сумма min+max: " << sum << std::endl;

        for (auto& p : m)
            p.second = p.second + sum;

        std::cout << "Словарь после добавления суммы к каждому элементу:" << std::endl;
        for (const auto& p : m)
            std::cout << p.first << " -> " << p.second << std::endl;
    }
}