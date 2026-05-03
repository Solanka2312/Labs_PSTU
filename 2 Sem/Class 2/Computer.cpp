#include "Computer.h"
#include <iostream>

Computer::Computer() {
	processor = "";
	ram = 0;
	hdd = 0;
	std::cout << "Конструктор без параметров для объекта " << this << ": " << std::endl;
}

Computer::Computer(std::string proc, int r, int h) {
	processor = proc;
	ram = r;
	hdd = h;
	std::cout << "Конструктор с параметрами для объекта " << this << ": " << std::endl;
}

Computer::Computer(const Computer& other) {
	processor = other.processor;
	ram = other.ram;
	hdd = other.hdd;
	std::cout << "Конструктор копирования для объекта " << this << ": " << std::endl;
}

Computer::~Computer() {
	std::cout << "Деструктор для объекта " << this << std::endl;
}

std::string Computer::getProcessor() const {
	return processor;
}
int Computer::getRam() const {
	return ram;
}
int Computer::getHdd() const {
	return hdd;
}

void Computer::setProcessor(std::string proc) {
	processor = proc;
}
void Computer::setRam(int r) {
	ram = r;
}
void Computer::setHdd(int h) {
	hdd = h;
}

void Computer::Show() const {
	std::cout << "Процессор: " << processor << std::endl;
	std::cout << "Объем ОП: " << ram << std::endl;
	std::cout << "Объем ЖД: " << hdd << std::endl;
}