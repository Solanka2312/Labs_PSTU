#include "VectorMoney.h"
#include <algorithm>
#include <iostream>

VectorMoney::VectorMoney() {}

void VectorMoney::input(int n)
{
    data.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите элемент " << i + 1 << ":" << std::endl;
        std::cin >> data[i];
    }
}

void VectorMoney::print() const
{
    for (size_t i = 0; i < data.size(); ++i)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

Money VectorMoney::srednee() const
{
    Money sum;
    for (size_t i = 0; i < data.size(); ++i)
        sum = sum + data[i];
    return sum / data.size();
}

void VectorMoney::addAtPosition(const Money& el, int pos)
{
    if (pos < 0 || pos >(int)data.size())
    {
        std::cout << "Неверная позиция!" << std::endl;
        return;
    }
    data.insert(data.begin() + pos, el);
}

Money VectorMoney::findMax() const
{
    Money max = data[0];
    for (size_t i = 1; i < data.size(); ++i)
        if (data[i] > max) max = data[i];
    return max;
}

void VectorMoney::deleteMax()
{
    Money max = findMax();
    auto it = std::find(data.begin(), data.end(), max);
    if (it != data.end())
        data.erase(it);
}

Money VectorMoney::findMin() const
{
    Money min = data[0];
    for (size_t i = 1; i < data.size(); ++i)
        if (data[i] < min) min = data[i];
    return min;
}

void VectorMoney::divideByMin()
{
    Money min = findMin();
    for (size_t i = 0; i < data.size(); ++i)
        data[i] = data[i] / 2;
}

int VectorMoney::size() const
{
    return data.size();
}