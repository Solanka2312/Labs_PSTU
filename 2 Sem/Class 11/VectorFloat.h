#pragma once
#include <vector>
#include <iostream>

class VectorFloat {
private:
    std::vector<float> data;

public:
    VectorFloat();
    void input(int n);
    void print() const;
    float srednee() const;
    void addAtPosition(float el, int pos);
    void deleteMax();
    void divideByMin();
    float findMax() const;
    float findMin() const;
    int size() const;
};