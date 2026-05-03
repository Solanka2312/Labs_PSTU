#pragma once
#include "Object.h"

class Vector {
private:
    Object** arr;
    int size;
    int cur;

public:
    Vector(int s);
    ~Vector();

    void addPair(int f, int s);
    void addFraction(int integer, int decimal);

    void ShowAll() const;

    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    int getSize() const { return cur; }
};