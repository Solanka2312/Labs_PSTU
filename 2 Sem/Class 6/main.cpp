#include "Set.h"
#include <iostream>
#include <windows.h>

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Set A;
	std::cout << "Пустое множество A: " << A << std::endl;
	std::cin >> A;
	std::cout << "A после ввода: " << A << std::endl;
	if ((int)A > 0) {
		std::cout << "Первый элемент A[0] = " << A[0] << std::endl;
		A[0] = 100;
		std::cout << "После A[0] = 100: " << A << std::endl;
	}
	else {
		std::cout << "Множество A пусто, демонстрация [] пропущена." << std::endl;
	}

	Set B;
	B.add(5);
	B.add(100);
	B.add(7);
	std::cout << "Множество B: " << B << std::endl;

	Set C = A * B;
	std::cout << "Пересечение A * B: " << C << std::endl;

	std::cout << "Элементы множества C: ";
	for (Set::Iterator it = C.begin(); it != C.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Обратный обход (через --): ";
	if ((int)C > 0) {
		Set::Iterator it = C.end();
		--it;
		while (true) {
			std::cout << *it << " ";
			if (it == C.begin()) break; 
			--it;
		}
	}
	std::cout << std::endl;

	Set D = C;
	std::cout << "Копия D = C: " << D << std::endl;

	Set E;
	E = B;
	std::cout << "Присваивание E = B: " << E << std::endl;
	return 0;
}
