#pragma once
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
class StackContainer {
private:
    std::stack<T> st;

public:
    void input(int n);
    void print() const;
    void addSumMinMaxToEach();
    T findMin() const;
    T findMax() const;
    int size() const;
};

template <class T>
void StackContainer<T>::input(int n)
{
    T a;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите элемент " << i + 1 << ": ";
        std::cin >> a;
        st.push(a);
    }
}

template <class T>
void StackContainer<T>::print() const
{
    std::stack<T> temp = st;
    std::vector<T> v;
    while (!temp.empty())
    {
        v.push_back(temp.top());
        temp.pop();
    }
    for (int i = v.size() - 1; i >= 0; --i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

template <class T>
T StackContainer<T>::findMin() const
{
    std::stack<T> temp = st;
    T min = temp.top();
    temp.pop();
    while (!temp.empty())
    {
        if (temp.top() < min)
            min = temp.top();
        temp.pop();
    }
    return min;
}

template <class T>
T StackContainer<T>::findMax() const
{
    std::stack<T> temp = st;
    T max = temp.top();
    temp.pop();
    while (!temp.empty())
    {
        if (temp.top() > max)
            max = temp.top();
        temp.pop();
    }
    return max;
}

template <class T>
void StackContainer<T>::addSumMinMaxToEach()
{
    T minVal = findMin();
    T maxVal = findMax();
    T sum = minVal + maxVal;

    std::vector<T> v;
    while (!st.empty())
    {
        v.push_back(st.top() + sum);
        st.pop();
    }
    for (int i = v.size() - 1; i >= 0; --i)
        st.push(v[i]);
}

template <class T>
int StackContainer<T>::size() const
{
    std::stack<T> temp = st;
    int count = 0;
    while (!temp.empty())
    {
        count++;
        temp.pop();
    }
    return count;
}