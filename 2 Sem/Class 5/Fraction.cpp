#include "Fraction.h"
#include <iostream>

Fraction::Fraction() : Pair() {}
Fraction::Fraction(int integer, int decimal) : Pair(integer, decimal) {}
Fraction::Fraction(const Fraction& other) : Pair(other) {}
Fraction::~Fraction() {}

void Fraction::Show() const {
    std::cout << first << ",";
    if (second < 10) std::cout << "0";
    std::cout << second;
}

void Fraction::Input() {
    double value;
    std::cout << "Введите десятичную дробь (например 3.45): ";
    std::cin >> value;
    first = (int)value;
    second = (int)((value - first) * 100 + 0.5);
}

bool Fraction::operator>(const Fraction& other) const {
    long leftVal = (long)first * 100 + second;
    long rightVal = (long)other.first * 100 + other.second;
    return leftVal > rightVal;
}
bool Fraction::operator<(const Fraction& other) const { return other > *this; }
bool Fraction::operator==(const Fraction& other) const {
    return (first == other.first && second == other.second);
}
bool Fraction::operator!=(const Fraction& other) const { return !(*this == other); }
bool Fraction::operator>=(const Fraction& other) const { return !(*this < other); }
bool Fraction::operator<=(const Fraction& other) const { return !(*this > other); }

Fraction& Fraction::operator=(const Fraction& other) {
    if (this == &other) return *this;
    first = other.first;
    second = other.second;
    return *this;
}

std::istream& operator>>(std::istream& in, Fraction& f) {
    f.Input();
    return in;
}
std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    f.Show();
    return out;
}