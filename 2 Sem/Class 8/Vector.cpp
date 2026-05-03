#include "Vector.h"
#include "Person.h"
#include "Employee.h"
#include <iostream>

Vector::Vector() : beg(nullptr), size(0), cur(0) {}

Vector::Vector(int n) : beg(new Object* [n]), size(n), cur(0) {}

Vector::Vector(const Vector& other) : size(other.size), cur(other.cur)
{
    beg = new Object * [size];
    for (int i = 0; i < cur; ++i)
        beg[i] = other.beg[i];
}

Vector::~Vector()
{
    for (int i = 0; i < cur; ++i)
        delete beg[i];
    delete[] beg;
}

void Vector::Add()
{
    if (cur >= size)
    {
        std::cout << "Группа заполнена!" << std::endl;
        return;
    }

    int type;
    std::cout << "Выберите тип (1 - Person, 2 - Employee): ";
    std::cin >> type;

    if (type == 1)
        beg[cur] = new Person();
    else if (type == 2)
        beg[cur] = new Employee();
    else
    {
        std::cout << "Неверный тип!" << std::endl;
        return;
    }

    beg[cur]->Input();
    cur++;
}

void Vector::Del()
{
    if (cur == 0)
    {
        std::cout << "Группа пуста!" << std::endl;
        return;
    }

    int index;
    std::cout << "Введите номер элемента для удаления (0-" << cur - 1 << "): ";
    std::cin >> index;

    if (index < 0 || index >= cur)
    {
        std::cout << "Неверный номер!" << std::endl;
        return;
    }
    delete beg[index];
    for (int i = index; i < cur - 1; ++i)
        beg[i] = beg[i + 1];
    cur--;
}

void Vector::Show()
{
    if (cur == 0)
    {
        std::cout << "Группа пуста!" << std::endl;
        return;
    }

    std::cout << "=== Группа (размер: " << cur << ") ===" << std::endl;
    for (int i = 0; i < cur; ++i)
    {
        std::cout << i << ": ";
        beg[i]->Show();
        std::cout << std::endl;
    }
}

int Vector::operator()() const
{
    return cur;
}

void Vector::HandleEvent(const TEvent& event)
{
    if (event.what == evMessage)
    {

        switch (event.command)
        {
        case cmGet:
            if (event.a >= 0 && event.a < cur)
            {
                TEvent tempEvent = event;
                tempEvent.a = 0;
                beg[event.a]->HandleEvent(tempEvent);
            }
            break;
        }
    }
}