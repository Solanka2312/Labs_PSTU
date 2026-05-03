#include "VectorFloat.h"
#include <algorithm>
#include <numeric>
#include <iostream>

VectorFloat::VectorFloat() {}

void VectorFloat::input(int n)
{
    data.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите элемент " << i + 1 << ": ";
        std::cin >> data[i];
    }
}

void VectorFloat::print() const
{
    for (size_t i = 0; i < data.size(); ++i)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

float VectorFloat::srednee() const
{
    float sum = std::accumulate(data.begin(), data.end(), 0.0f);
    return sum / data.size();
}

void VectorFloat::addAtPosition(float el, int pos)
{
    if (pos < 0 || pos >(int)data.size())
    {
        std::cout << "Неверная позиция!" << std::endl;
        return;
    }
    data.insert(data.begin() + pos, el);
}

float VectorFloat::findMax() const
{
    return *std::max_element(data.begin(), data.end());
}

void VectorFloat::deleteMax()
{
    float max = findMax();
    auto it = std::find(data.begin(), data.end(), max);
    if (it != data.end())
        data.erase(it);
}

float VectorFloat::findMin() const
{
    return *std::min_element(data.begin(), data.end());
}

void VectorFloat::divideByMin()
{
    float min = findMin();
    if (min == 0)
    {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return;
    }
    for (size_t i = 0; i < data.size(); ++i)
        data[i] = data[i] / min;
}

int VectorFloat::size() const
{
    return data.size();
}