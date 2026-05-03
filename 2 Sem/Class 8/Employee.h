#pragma once
#include "Person.h"

class Employee : public Person
{
private:
    float salary;
    std::string position;

public:
    Employee();
    Employee(std::string n, int a, float s, std::string p);
    Employee(const Employee& other);
    ~Employee();

    void Show() override;
    void Input() override;
    void HandleEvent(const TEvent& event) override;

    float getSalary() const;
    std::string getPosition() const;

    Employee& operator=(const Employee& other);
};