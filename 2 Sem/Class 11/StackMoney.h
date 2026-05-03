#pragma once
#include <stack>
#include <iostream>
#include "Money.h"

class StackMoney {
private:
    std::stack<Money> st;

public:
    void input(int n);
    void print() const;
    void deleteByKey(const Money& key);
    std::stack<Money> getStack() const { return st; }
};
