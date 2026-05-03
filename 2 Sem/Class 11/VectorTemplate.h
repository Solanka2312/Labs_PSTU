#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

template <class T>
class VectorTemplate {
private:
    std::vector<T> data;

public:
    void input(int n);
    void print() const;
    T findMin() const;
    void addMinToEnd();
    int size() const;
};

template <class T>
void VectorTemplate<T>::input(int n)
{
    data.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите элемент " << i + 1 << ": ";
        std::cin >> data[i];
    }
}

template <class T>
void VectorTemplate<T>::print() const
{
    for (size_t i = 0; i < data.size(); ++i)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

template <class T>
T VectorTemplate<T>::findMin() const
{
    return *std::min_element(data.begin(), data.end());
}

template <class T>
void VectorTemplate<T>::addMinToEnd()
{
    T min = findMin();
    data.push_back(min);
}

template <class T>
int VectorTemplate<T>::size() const
{
    return data.size();
}