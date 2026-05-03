#include "Set.h"
#include <iostream>
#include <algorithm>

Set::Set() : data(new int[10]), size(0), capacity(10) {}

Set::Set(int cap) : data(new int[cap]), size(0), capacity(cap)
{
    if (cap > MAX_SIZE)
        throw 1;
}

Set::Set(const Set& other) : data(new int[other.capacity]), size(other.size), capacity(other.capacity)
{
    for (int i = 0; i < size; ++i)
        data[i] = other.data[i];
}

Set::~Set()
{
    delete[] data;
}

Set& Set::operator=(const Set& other)
{
    if (this != &other)
    {
        delete[] data;
        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

void Set::ensureCapacity()
{
    if (size < capacity) return;
    int newCap = capacity * 2;
    int* newData = new int[newCap];
    for (int i = 0; i < size; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    capacity = newCap;
}

void Set::add(int value)
{
    if (!contains(value))
    {
        ensureCapacity();
        data[size++] = value;
    }
}

bool Set::contains(int value) const
{
    for (int i = 0; i < size; ++i)
        if (data[i] == value) return true;
    return false;
}

void Set::remove(int value)
{
    for (int i = 0; i < size; ++i)
    {
        if (data[i] == value)
        {
            data[i] = data[--size];
            return;
        }
    }
}

int& Set::operator[](int index)
{
    if (index < 0)
        throw 2;
    if (index >= size)
        throw 3;
    return data[index];
}

const int& Set::operator[](int index) const
{
    if (index < 0)
        throw 2;
    if (index >= size)
        throw 3;
    return data[index];
}

Set::operator int() const
{
    return size;
}

Set Set::operator*(const Set& other) const
{
    Set result;
    for (int i = 0; i < size; ++i)
    {
        if (other.contains(data[i]))
            result.add(data[i]);
    }
    return result;
}

Set& Set::operator--()
{
    if (size == 0)
        throw 4;

    if (size == 1)
    {
        size = 0;
        return *this;
    }

    for (int i = 0; i < size - 1; ++i)
        data[i] = data[i + 1];
    size--;
    return *this;
}

Set Set::operator--(int)
{
    if (size == 0)
        throw 4;

    Set temp = *this;
    if (size == 1)
    {
        size = 0;
    }
    else
    {
        size--;
    }
    return temp;
}

std::istream& operator>>(std::istream& in, Set& s)
{
    int n, val;
    std::cout << "Сколько элементов добавить? ";
    in >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите элемент " << i + 1 << ": ";
        in >> val;
        s.add(val);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Set& s)
{
    out << "{ ";
    for (int i = 0; i < (int)s; ++i)
        out << s[i] << " ";
    out << "} (размер: " << (int)s << ")";
    return out;
}