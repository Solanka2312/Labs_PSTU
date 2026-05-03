#pragma once
#include "Vector.h"

class Dialog : public Vector
{
private:
    int endState;

public:
    Dialog();
    virtual ~Dialog();

    virtual void GetEvent(TEvent& event);
    virtual int Execute();
    virtual void HandleEvent(TEvent& event);
    virtual void ClearEvent(TEvent& event);

    int Valid();
    void EndExec();
};
