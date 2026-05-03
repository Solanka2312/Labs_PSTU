#include "Money.h"
#include <iostream>
#include <windows.h>

Money make_money() {
	long r;
	int k;
	std::cout << "Введите рубли: ";
	std::cin >> r;
	std::cout << "Введите копейки: ";
	std::cin >> k;
	Money m(r, k);
	return m;
}

void print_money(Money m) {
	m.Show();
	std::cout << std::endl;
}

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	std::cout << "Конструктор без параметров: " << std::endl;
	Money m1;
	std::cout << "m1 = " << m1 << std::endl;

	std::cout << "Конструктор с параметрами: " << std::endl;
	Money m2(150, 42);
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "Конструктор копирования (1): " << std::endl;
	Money m3 = m2;
	std::cout << "m3 = " << m3 << std::endl;

	std::cout << "Конструктор копирования (2): " << std::endl;
	print_money(m2);
	std::cout << std::endl;

	std::cout << "Конструктор копирования (3): " << std::endl;
	Money m4 = make_money();
	std::cout << "Создана сумма: " << m4 << std::endl;

	std::cout << "Операция умножения:" << std::endl;
	Money m5 = m3 * 2.5;
	std::cout << m3 << " * 2.5 = " << m5 << std::endl;

	std::cout << "Операция деления:" << std::endl;
	Money m6 = m3 / 3;
	std::cout << m3 << " / 3 = " << m6 << std::endl;

	return 0;
}