#include "Money.h"
#include <cmath>
#include <iostream>
#include <fstream>

Money::Money() : rub(0), kop(0) {}

Money::Money(long r, int k) : rub(r), kop(k)
{
    if (kop >= 100)
    {
        rub += kop / 100;
        kop %= 100;
    }
    if (kop < 0)
    {
        rub -= 1;
        kop += 100;
    }
}

Money::Money(const Money& other) : rub(other.rub), kop(other.kop) {}

Money::~Money() {}

long Money::getRub() const { return rub; }
int Money::getKop() const { return kop; }

void Money::setRub(long r) { rub = r; }

void Money::setKop(int k)
{
    if (k >= 100)
    {
        rub += k / 100;
        kop = k % 100;
    }
    else if (k < 0)
    {
        rub -= 1;
        kop += 100;
    }
    else
    {
        kop = k;
    }
}


void Money::Show() const
{
    std::cout << rub << ",";
    if (kop < 10) std::cout << "0";
    std::cout << kop << " руб.";
}


Money Money::operator/(const Money& other) const
{
    if (other.rub == 0 && other.kop == 0)
    {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return Money(0, 0);
    }
    double thisVal = rub * 100 + kop;
    double otherVal = other.rub * 100 + other.kop;
    double result = thisVal / otherVal;
    long newRub = static_cast<long>(result);
    int newKop = static_cast<int>((result - newRub) * 100);
    if (newKop < 0)
    {
        newKop += 100;
        newRub--;
    }
    return Money(newRub, newKop);
}

Money Money::operator*(double factor) const
{
    double totalKop = (rub * 100 + kop) * factor;
    long newRub = static_cast<long>(totalKop / 100);
    int newKop = static_cast<int>(totalKop - newRub * 100);
    if (newKop < 0)
    {
        newKop += 100;
        newRub--;
    }
    return Money(newRub, newKop);
}

Money Money::operator/(int divisor) const
{
    if (divisor == 0)
    {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return Money(0, 0);
    }
    int totalKop = rub * 100 + kop;
    int resultKop = totalKop / divisor;
    return Money(resultKop / 100, resultKop % 100);
}


bool Money::operator==(const Money& other) const
{
    return (rub == other.rub && kop == other.kop);
}

bool Money::operator!=(const Money& other) const
{
    return !(*this == other);
}


std::istream& operator>>(std::istream& in, Money& m)
{
    double value;
    std::cout << "Введите сумму (рубли.копейки): ";
    in >> value;
    m.rub = static_cast<long>(value);
    m.kop = static_cast<int>((value - m.rub) * 100 + 0.5);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Money& m)
{
    out << m.rub << ",";
    if (m.kop < 10) out << "0";
    out << m.kop << " руб.";
    return out;
}


std::fstream& operator>>(std::fstream& fin, Money& m)
{
    fin >> m.rub >> m.kop;
    return fin;
}

std::fstream& operator<<(std::fstream& fout, const Money& m)
{
    fout << m.rub << "\n" << m.kop << "\n";
    return fout;
}