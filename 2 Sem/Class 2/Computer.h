#pragma once
#include <iostream>
#include <string>

class Computer {
private:
	std::string processor;
	int ram;
	int hdd;

public:
	Computer();
	Computer(std::string proc, int r, int h);
	Computer(const Computer& other);

	~Computer();

	std::string getProcessor() const;
	int getRam() const;
	int getHdd() const;

	void setProcessor(std::string proc);
	void setRam(int r);
	void setHdd(int h);

	void Show() const;
};