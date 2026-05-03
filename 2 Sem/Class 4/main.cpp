#include "Fraction.h"
#include <iostream>
#include <windows.h>

void printPair(const Pair& p) {
    std::cout << "Значение: " << p << std::endl;
}
Pair createPair() {
    Fraction f(7, 15);
    return f;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Базовый класс Pair" << std::endl;
    Pair p1(3, 45);
    Pair p2(3, 50);
    std::cout << "p1 = " << p1 << std::endl;
    std::cout << "p2 = " << p2 << std::endl;
    std::cout << "p1 > p2: " << (p1 > p2 ? "да" : "нет") << std::endl;
    std::cout << "p1 < p2: " << (p1 < p2 ? "да" : "нет") << std::endl;
    std::cout << "p1 == p2: " << (p1 == p2 ? "да" : "нет") << std::endl;
    std::cout << std::endl;

    std::cout << "Производный класс Fraction" << std::endl;
    Fraction f1(2, 75);
    Fraction f2(2, 68);
    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;
    std::cout << "f1 > f2: " << (f1 > f2 ? "да" : "нет") << std::endl;
    std::cout << "f1 < f2: " << (f1 < f2 ? "да" : "нет") << std::endl;
    std::cout << "f1 == f2: " << (f1 == f2 ? "да" : "нет") << std::endl;
    std::cout << "f1 >= f2: " << (f1 >= f2 ? "да" : "нет") << std::endl;
    std::cout << "f1 <= f2: " << (f1 <= f2 ? "да" : "нет") << std::endl;
    std::cout << std::endl;

    Fraction f3(9, 99);
    std::cout << "Передача Fraction в функцию printPair(): ";
    printPair(f3);
    std::cout << std::endl;

    std::cout << "Указатель на Pair указывает на Fraction: ";
    Pair* ptr = new Fraction(8, 88);
    std::cout << *ptr << std::endl;
    delete ptr;
    std::cout << std::endl;

    std::cout << "Возврат Fraction из функции, возвращающей Pair: ";
    Pair p3 = createPair();
    std::cout << p3 << std::endl;
    std::cout << "(произошла срезка)" << std::endl;
    std::cout << std::endl;

    Fraction f4;
    f4.setFirst(5);
    f4.setSecond(50);
    std::cout << "После setFirst(5) и setSecond(50): " << f4 << std::endl;
    f4.setSecond(105);
    std::cout << "После setSecond(105): " << f4 << std::endl;
    std::cout << std::endl;
    Fraction f5;
    f5 = f1;
    std::cout << "f5 = f1: " << f5 << std::endl;

    return 0;
}
