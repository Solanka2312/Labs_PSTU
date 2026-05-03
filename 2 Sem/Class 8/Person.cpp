#include "Person.h"
#include <iostream>

Person::Person() : name(""), age(0) {}

Person::Person(std::string n, int a) : name(n), age(a) {}

Person::Person(const Person& other) : name(other.name), age(other.age) {}

Person::~Person() {}

void Person::Show()
{
    std::cout << "Имя: " << name << ", Возраст: " << age;
}

void Person::Input()
{
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Введите возраст: ";
    std::cin >> age;
}

void Person::HandleEvent(const TEvent& event)
{
    if (event.what == evMessage)
    {
        switch (event.command)
        {
        case cmGet:
            if (event.a == 0)
                std::cout << name << std::endl;
            break;
        }
    }
}

std::string Person::getName() const { return name; }
int Person::getAge() const { return age; }

Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        name = other.name;
        age = other.age;
    }
    return *this;
}