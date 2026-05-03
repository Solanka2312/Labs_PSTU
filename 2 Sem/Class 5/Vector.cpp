#include "Vector.h"
#include "Pair.h"
#include "Fraction.h"
#include <iostream>

Vector::Vector(int s) : size(s), cur(0) {
    arr = new Object * [size];
    for (int i = 0; i < size; ++i) arr[i] = nullptr;
}

Vector::~Vector() {
    for (int i = 0; i < cur; ++i) delete arr[i];
    delete[] arr;
}
void Vector::addPair(int f, int s) {
    if (cur >= size) {
        std::cout << "Группа заполнена!" << std::endl;
        return;
    }
    arr[cur] = new Pair(f, s);
    cur++;
}
void Vector::addFraction(int integer, int decimal) {
    if (cur >= size) {
        std::cout << "Группа заполнена!" << std::endl;
        return;
    }
    arr[cur] = new Fraction(integer, decimal);
    cur++;
}
void Vector::ShowAll() const {
    if (cur == 0) {
        std::cout << "Группа пуста!" << std::endl;
        return;
    }
    for (int i = 0; i < cur; ++i) {
        std::cout << i + 1 << ": ";
        arr[i]->Show();
        std::cout << std::endl;
    }
}
std::ostream& operator<<(std::ostream& out, const Vector& v) {
    v.ShowAll();
    return out;
}