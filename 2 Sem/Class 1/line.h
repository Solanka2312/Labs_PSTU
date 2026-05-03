#pragma once
#include <iostream>

class Line {
private:
	double first;
	double second;

public:
	void Init(double A, double B);
	void Read();
	void Show();
	double Function(double x);
};