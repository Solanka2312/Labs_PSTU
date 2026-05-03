#pragma once
#include <iostream>

class Object {
public:
    virtual void Show() const = 0;
    virtual void Input() = 0;        
    virtual ~Object() {}
};