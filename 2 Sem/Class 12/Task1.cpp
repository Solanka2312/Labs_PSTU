#include "Task1.h"
#include <iostream>

void task1()
{
    std::cout << "Задача 1 (multiset float) " << std::endl;

    std::multiset<float> ms;
    int n;
    float val;

    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Элемент " << i + 1 << ": ";
        std::cin >> val;
        ms.insert(val);
    }

    std::cout << "Мультимножество: ";
    for (float x : ms) std::cout << x << " ";
    std::cout << std::endl;

    float minVal = *ms.begin();
    ms.insert(minVal);

    std::cout << "После добавления минимального (" << minVal << ") в конец: ";
    for (float x : ms) std::cout << x << " ";
    std::cout << std::endl << std::endl;
}