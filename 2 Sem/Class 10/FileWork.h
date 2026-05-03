#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int makeFile(const char* fname)
{
    std::fstream stream(fname, std::ios::out | std::ios::trunc);
    if (!stream)
    {
        std::cout << "Ошибка открытия файла для записи!" << std::endl;
        return -1;
    }

    int n;
    Money m;
    std::cout << "Сколько записей добавить? ";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> m;
        stream << m;
    }

    stream.close();
    std::cout << "Файл создан. Записей: " << n << std::endl;
    return n;
}

int printFile(const char* fname)
{
    std::fstream stream(fname, std::ios::in);
    if (!stream)
    {
        std::cout << "Ошибка открытия файла для чтения!" << std::endl;
        return -1;
    }

    Money m;
    int count = 0;
    std::cout << "\n=== Содержимое файла ===" << std::endl;
    while (stream >> m)
    {
        std::cout << ++count << ": " << m << std::endl;
    }

    stream.close();
    if (count == 0)
        std::cout << "Файл пуст!" << std::endl;
    return count;
}

int deleteNotEqual(const char* fname, const Money& value)
{
    std::fstream stream(fname, std::ios::in);
    if (!stream)
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return -1;
    }

    std::vector<Money> temp;
    Money m;
    int deleted = 0;

    while (stream >> m)
    {
        if (m == value)
            temp.push_back(m);
        else
            deleted++;
    }
    stream.close();

    std::fstream out(fname, std::ios::out | std::ios::trunc);
    for (size_t i = 0; i < temp.size(); ++i)
        out << temp[i];
    out.close();

    std::cout << "Удалено записей: " << deleted << std::endl;
    std::cout << "Осталось записей: " << temp.size() << std::endl;
    return temp.size();
}

int halveEqual(const char* fname, const Money& value)
{
    std::fstream stream(fname, std::ios::in);
    if (!stream)
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return -1;
    }

    std::vector<Money> temp;
    Money m;
    int halved = 0;

    while (stream >> m)
    {
        if (m == value)
        {
            Money half = m / 2;
            temp.push_back(half);
            halved++;
        }
        else
        {
            temp.push_back(m);
        }
    }
    stream.close();

    std::fstream out(fname, std::ios::out | std::ios::trunc);
    for (size_t i = 0; i < temp.size(); ++i)
        out << temp[i];
    out.close();

    std::cout << "Уменьшено записей: " << halved << std::endl;
    return temp.size();
}

int addToBeginning(const char* fname, int k)
{
    std::fstream stream(fname, std::ios::in);
    if (!stream)
    {
        std::cout << "Ошибка открытия файла для чтения!" << std::endl;
        return -1;
    }

    std::vector<Money> oldData;
    Money m;
    while (stream >> m)
        oldData.push_back(m);
    stream.close();

    std::vector<Money> newData;
    std::cout << "Введите " << k << " новых сумм:" << std::endl;
    for (int i = 0; i < k; ++i)
    {
        Money newM;
        std::cin >> newM;
        newData.push_back(newM);
    }

    std::fstream out(fname, std::ios::out | std::ios::trunc);
    for (size_t i = 0; i < newData.size(); ++i)
        out << newData[i];
    for (size_t i = 0; i < oldData.size(); ++i)
        out << oldData[i];
    out.close();

    std::cout << "Добавлено " << k << " записей в начало." << std::endl;
    std::cout << "Всего записей: " << newData.size() + oldData.size() << std::endl;
    return newData.size() + oldData.size();
}