#pragma once
#include <map>
#include <iostream>

template <class Key, class T>
class MapContainer {
private:
    std::map<Key, T> data;

public:
    void input(int n);
    void print() const;

    void addMinToEnd();

    void deleteByKey(const Key& key);

    void addSumMinMaxToEach();

    T findMinValue() const;
    T findMaxValue() const;
    int size() const { return data.size(); }
};

template <class Key, class T>
void MapContainer<Key, T>::input(int n)
{
    Key k;
    T val;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите ключ и значение " << i + 1 << ": ";
        std::cin >> k >> val;
        data[k] = val;
    }
}

template <class Key, class T>
void MapContainer<Key, T>::print() const
{
    for (const auto& p : data)
        std::cout << p.first << " -> " << p.second << std::endl;
}

template <class Key, class T>
T MapContainer<Key, T>::findMinValue() const
{
    if (data.empty()) return T();
    T minVal = data.begin()->second;
    for (const auto& p : data)
        if (p.second < minVal) minVal = p.second;
    return minVal;
}

template <class Key, class T>
T MapContainer<Key, T>::findMaxValue() const
{
    if (data.empty()) return T();
    T maxVal = data.begin()->second;
    for (const auto& p : data)
        if (p.second > maxVal) maxVal = p.second;
    return maxVal;
}

template <class Key, class T>
void MapContainer<Key, T>::addMinToEnd()
{
    if (data.empty()) return;
    T minVal = findMinValue();
    int newKey = data.size();
    data[newKey] = minVal;
}

template <class Key, class T>
void MapContainer<Key, T>::deleteByKey(const Key& key)
{
    auto it = data.find(key);
    if (it != data.end())
    {
        std::cout << "Удаляем элемент с ключом " << key << ": " << it->second << std::endl;
        data.erase(it);
    }
    else
    {
        std::cout << "Элемент с ключом " << key << " не найден." << std::endl;
    }
}

template <class Key, class T>
void MapContainer<Key, T>::addSumMinMaxToEach()
{
    if (data.empty()) return;
    T minVal = findMinValue();
    T maxVal = findMaxValue();
    T sum = minVal + maxVal;

    for (auto& p : data)
        p.second = p.second + sum;
}