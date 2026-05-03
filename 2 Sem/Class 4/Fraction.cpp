#include "Fraction.h"
#include <iostream>
Fraction::Fraction() : Pair() {
    std::cout << "Конструктор Fraction без параметров" << std::endl;
}
Fraction::Fraction(int integer, int decimal) : Pair(integer, decimal) {
    std::cout << "Конструктор Fraction с параметрами" << std::endl;
}
Fraction::Fraction(const Fraction& other) : Pair(other) {
    std::cout << "Конструктор копирования Fraction" << std::endl;
}
Fraction::~Fraction() {
    std::cout << "Деструктор Fraction" << std::endl;
}

bool Fraction::operator>(const Fraction& other) const {
    long leftVal = (long)first * 100 + second;
    long rightVal = (long)other.first * 100 + other.second;
    return leftVal > rightVal;
}
bool Fraction::operator<(const Fraction& other) const {
    return other > *this;
}
bool Fraction::operator==(const Fraction& other) const {
    return (first == other.first && second == other.second);
}
bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}
bool Fraction::operator>=(const Fraction& other) const {
    return (*this > other) || (*this == other);
}
bool Fraction::operator<=(const Fraction& other) const {
    return (*this < other) || (*this == other);
}
void Fraction::Show() const {
    std::cout << first << ",";
    if (second < 10) std::cout << "0";
    std::cout << second;
}


Fraction& Fraction::operator=(const Fraction& other) {
    if (this == &other) return *this;
    first = other.first;
    second = other.second;
    return *this;
}
std::istream& operator>>(std::istream& in, Fraction& f) {
    double value;
    std::cout << "Введите десятичную дробь (например 3.45): ";
    in >> value;
    f.setFirst((int)value);
    f.setSecond((int)((value - f.getFirst()) * 100 + 0.5));
    return in;
}
std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.getFirst() << ",";
    if (f.getSecond() < 10) out << "0";
    out << f.getSecond();
    return out;
}
