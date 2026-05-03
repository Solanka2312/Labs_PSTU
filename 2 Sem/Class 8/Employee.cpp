#include "Employee.h"
#include <iostream>

Employee::Employee() : Person(), salary(0), position("") {}

Employee::Employee(std::string n, int a, float s, std::string p)
    : Person(n, a), salary(s), position(p) {
}

Employee::Employee(const Employee& other)
    : Person(other), salary(other.salary), position(other.position) {
}

Employee::~Employee() {}

void Employee::Show()
{
    Person::Show();
    std::cout << ", Зарплата: " << salary << ", Должность: " << position;
}

void Employee::Input()
{
    Person::Input();
    std::cout << "Введите зарплату: ";
    std::cin >> salary;
    std::cout << "Введите должность: ";
    std::cin >> position;
}

void Employee::HandleEvent(const TEvent& event)
{
    if (event.what == evMessage)
    {
        switch (event.command)
        {
        case cmGet:
            if (event.a == 0)
                std::cout << getName() << std::endl;
            break;
        }
    }
}

float Employee::getSalary() const { return salary; }
std::string Employee::getPosition() const { return position; }

Employee& Employee::operator=(const Employee& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        salary = other.salary;
        position = other.position;
    }
    return *this;
}