#include "line.h"
#include <iostream>
#include <windows.h>

void Line::Init(double A, double B) {
	first = A;
	second = B;
}
void Line::Read() {
	SetConsoleOutputCP(CP_UTF8);
	std::cout << "Введите коэф. A: ";
	std::cin >> first;
	std::cout << "Введите коэф. B: ";
	std::cin >> second;
}
void Line::Show() {
	std::cout << "Коэф. A = " << first << std::endl;
	std::cout << "Коэф. B = " << second << std::endl;
}
double Line::Function(double x) {
	return first * x + second;
}