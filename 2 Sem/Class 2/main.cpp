#include "Computer.h"
#include <iostream>
#include <windows.h>

Computer make_computer() {
	std::string proc;
	int r, h;
	std::cout << "Введите процессор: ";
	std::cin >> proc;
	std::cout << "Введите объем ОП (ГБ): ";
	std::cin >> r;
	std::cout << "Введите объем ЖД (ГБ): ";
	std::cin >> h;
	Computer comp(proc, r, h);
	return comp;
}

void print_computer(Computer comp) {
	comp.Show();
}

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	std::cout << "Конструктор без параметров: " << std::endl;
	Computer comp1;
	comp1.Show();
	std::cout << std::endl;

	std::cout << "Конструктор с параметрами: " << std::endl;
	Computer comp2("Interl_Core_i5", 16, 1024);
	comp2.Show();
	std::cout << std::endl;

	std::cout << "Конструктор копирования: " << std::endl;
	Computer comp3 = comp2;
	comp3.Show();
	std::cout << std::endl;

	std::cout << "Изменение через модификаторы: " << std::endl;
	comp3.setProcessor("Intel_Duo");
	comp3.setRam(4);
	comp3.setHdd(64);
	comp3.Show();
	std::cout << std::endl;

	std::cout << "Передача объекта в функцию: " << std::endl;
	print_computer(comp2);
	std::cout << std::endl;
	std::cout << "Возврат объекта из функции: " << std::endl;
	Computer comp5 = make_computer();
	comp5.Show();
	std::cout << std::endl;

	return 0;
}
