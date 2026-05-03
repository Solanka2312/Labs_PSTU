#include "StackMoney.h"
#include <vector>
#include <algorithm>

void StackMoney::input(int n)
{
    Money m;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите элемент " << i + 1 << ":" << std::endl;
        std::cin >> m;
        st.push(m);
    }
}

void StackMoney::print() const
{
    std::stack<Money> temp = st;
    std::vector<Money> v;
    while (!temp.empty())
    {
        v.push_back(temp.top());
        temp.pop();
    }
    for (int i = v.size() - 1; i >= 0; --i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

void StackMoney::deleteByKey(const Money& key)
{
    std::stack<Money> tempStack;
    while (!st.empty())
    {
        if (!(st.top() == key))
            tempStack.push(st.top());
        st.pop();
    }
    while (!tempStack.empty())
    {
        st.push(tempStack.top());
        tempStack.pop();
    }
}