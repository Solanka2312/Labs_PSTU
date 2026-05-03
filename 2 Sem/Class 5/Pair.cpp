#include "Pair.h"
#include <iostream>

Pair::Pair() : first(0), second(0) {}
Pair::Pair(int f, int s) : first(f), second(s) {
    if (second >= 100) {
        first += second / 100;
        second %= 100;
    }
    if (second < 0) {
        first -= 1;
        second += 100;
    }
}
Pair::Pair(const Pair& other) : first(other.first), second(other.second) {}
Pair::~Pair() {}

void Pair::setFirst(int f) { first = f; }
void Pair::setSecond(int s) {
    second = s;
    if (second >= 100) {
        first += second / 100;
        second %= 100;
    }
    if (second < 0) {
        first -= 1;
        second += 100;
    }
}
int Pair::getFirst() const { return first; }
int Pair::getSecond() const { return second; }

void Pair::Show() const {
    std::cout << first << ",";
    if (second < 10) std::cout << "0";
    std::cout << second;
}

void Pair::Input() {
    std::cout << "Введите целую часть: ";
    std::cin >> first;
    std::cout << "Введите дробную часть (0-99): ";
    std::cin >> second;
}

bool Pair::operator>(const Pair& other) const {
    if (first > other.first) return true;
    if (first == other.first && second > other.second) return true;
    return false;
}
bool Pair::operator<(const Pair& other) const { return other > *this; }
bool Pair::operator==(const Pair& other) const { return first == other.first && second == other.second; }
bool Pair::operator!=(const Pair& other) const { return !(*this == other); }
bool Pair::operator>=(const Pair& other) const { return (*this > other) || (*this == other); }
bool Pair::operator<=(const Pair& other) const { return (*this < other) || (*this == other); }

Pair& Pair::operator=(const Pair& other) {
    if (this == &other) return *this;
    first = other.first;
    second = other.second;
    return *this;
}

std::istream& operator>>(std::istream& in, Pair& p) {
    p.Input();
    return in;
}
std::ostream& operator<<(std::ostream& out, const Pair& p) {
    p.Show();
    return out;
}