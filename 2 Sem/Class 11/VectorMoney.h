#pragma once
#include <vector>
#include <iostream>
#include "Money.h"

class VectorMoney {
private:
    std::vector<Money> data;

public:
    VectorMoney();
    void input(int n);
    void print() const;
    Money srednee() const;
    void addAtPosition(const Money& el, int pos);
    void deleteMax();
    void divideByMin();
    Money findMax() const;
    Money findMin() const;
    int size() const;
};
