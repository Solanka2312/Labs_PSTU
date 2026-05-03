#include "line.h"
#include <iostream>
#include <windows.h>

Line make_line(double A, double B) {
	Line result;
	result.Init(A, B);
	return result;
}
int main() {
	SetConsoleOutputCP(CP_UTF8);
	Line L1;
	double a, b;
	std::cout << "Введите коэффициенты для L1:" << std::endl;
	std::cout << "A: ";
	std::cin >> a;
	std::cout << "B: ";
	std::cin >> b;
	L1.Init(a, b);
	L1.Show();

	double x;
	std::cout << "Введите x для L1: ";
	std::cin >> x;
	std::cout << "y = " << L1.Function(x) << std::endl;

	Line L2;
	std::cout << "Введите коэффициенты для L2:" << std::endl;
	L2.Read();
	L2.Show();
	std::cout << "Введите x для L2: ";
	std::cin >> x;
	std::cout << "y = " << L2.Function(x) << std::endl;

	Line L3 = make_line(4.0, 6.0);
	L3.Show();
	std::cout << "Введите x для L3: ";
	std::cin >> x;
	std::cout << "y = " << L3.Function(x) << std::endl;
	
	return 0;
}
