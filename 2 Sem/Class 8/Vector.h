#pragma once
#include "Object.h"
#include "Event.h"

class Vector
{
protected:
    Object** beg;
    int size;
    int cur;

public:
    Vector();
    Vector(int n);
    Vector(const Vector& other);
    ~Vector();

    void Add();
    void Del();
    void Show();
    int operator()() const;

    void HandleEvent(const TEvent& event);
};
