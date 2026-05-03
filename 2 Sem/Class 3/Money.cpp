#include "Money.h"
#include <cmath>
#include <iostream>

Money::Money() {
	rub = 0;
	kop = 0;
	std::cout << "Конструктор без параметров для объекта: " << this << ": " << std::endl;
}
Money::Money(long r, int k) {
	rub = r;
	if (r > 99) {
		rub += k / 100;
		kop = k % 100;
	}
	else if (k < 0) {
		rub -= (abs(k) / 100) + 1;
		kop = 100 - (abs(k) % 100);
		if (kop == 100) kop = 0;
	}
	else {
		kop = k;
	}
	std::cout << "Конструктор с параметрами для объекта" << this << ": " << std::endl;
}
Money::Money(const Money& other) {
	rub = other.rub;
	kop = other.kop;
	std::cout << "Конструктор копирования для объекта" << this << ": " << std::endl;
}

long Money::getRub()const {
	return rub;
}
int Money::getKop()const {
	return kop;
}

void Money::setRub(long r) {
	rub = r;
}
void Money::setKop(int k) {
	if (k > 99) {
		rub += k / 100;
		kop = k % 100;
	}
	else if (k < 0) {
		rub -= (abs(k) / 100) + 1;
		kop = 100 - (abs(k) % 100);
		if (kop == 100) kop = 0;
	}
	else {
		kop = k;
	}
}

void Money::Show() const {
	std::cout << rub << ", ";
	if (kop < 10) std::cout << "0";
	std::cout << kop << " руб";
}

Money& Money::operator=(const Money& other) {
	std::cout << "Оператор присваивания для объекта " << this << ": " << std::endl;
	if (this == &other) return *this;
	rub = other.rub;
	kop = other.kop;
	return *this;
}

Money Money::operator/(double d) const {
	if (d == 0) return Money(0, 0);
	double total = (rub * 100 + kop) / d;
	long newRub = (long)(total / 100);
	int newKop = (int)(total - newRub * 100);
	return Money(newRub, newKop);
}
Money Money::operator*(double d)const {
	double total = (rub * 100 + kop) * d;
	long newRub = (long)(total / 100);
	int newKop = (int)(total - newRub * 100);
	if (newKop < 0)
	{
		newKop += 100;
		newRub--;
	}
	return Money(newRub, newKop);
}

istream& operator>>(istream& in, Money& m) {
	double value;
	std::cout << "Введите сумму (Рубли.копейки): ";
	in >> value;
	m.rub = (long)value;
	m.kop = (int)((value - m.rub) * 100 + 0.5);
	return in;
}
ostream& operator<<(ostream& out, Money& m) {
	out << m.rub << ",";
	if (m.kop < 10) out << "0";
	out << m.kop << " руб.";
	return out;
}

Money::~Money()
{
	cout << "Деструктор для объекта: " << this << endl;
}