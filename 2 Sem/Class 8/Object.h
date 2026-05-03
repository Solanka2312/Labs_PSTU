#pragma once
#include "Event.h"
#include <iostream>

class Object
{
public:
    virtual void Show() = 0;
    virtual void Input() = 0;
    virtual void HandleEvent(const TEvent& event) = 0;
    virtual ~Object() {}
};