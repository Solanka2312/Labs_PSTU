
#pragma once
#include "Object.h"
#include <string>

class Person : public Object
{
protected:
    std::string name;
    int age;

public:
    Person();
    Person(std::string n, int a);
    Person(const Person& other);
    virtual ~Person();

    void Show() override;
    void Input() override;
    void HandleEvent(const TEvent& event) override;

    std::string getName() const;
    int getAge() const;

    Person& operator=(const Person& other);
};