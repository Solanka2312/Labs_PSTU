#include <iostream>
#include <cmath>
#include <stdarg.h>
using namespace std;

double triangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double square(int n, ...) {
    if (n < 3) {
        cout << "Ошибка: n должно быть >= 3!" << endl;
        return 0.0;
    }
    
    va_list args;
    va_start(args, n);
    
    double* sides = new double[n];
    for (int i = 0; i < n; i++) {
        sides[i] = va_arg(args, double);
    }
    
    va_end(args);
    
    double totalArea = 0.0;
    for (int i = 1; i < n - 1; i++) {
        totalArea += triangleArea(sides[0], sides[i], sides[i + 1]);
    }
    
    delete[] sides;
    return totalArea;
}

int main() {
    
    cout << "1. Треугольник со сторонами 3, 4, 5:" << endl;
    double area3 = square(3, 3.0, 4.0, 5.0);
    cout << "   Площадь = " << area3 << endl;
    cout << "   Проверка: sqrt(6*3*2*1) = sqrt(36) = 6" << endl;
    cout << endl;
    
    cout << "2. Четырехугольник со сторонами 3, 4, 5, 6:" << endl;
    double area4 = square(4, 3.0, 4.0, 5.0, 6.0);
    cout << "   Площадь = " << area4 << endl;
    cout << endl;
    
    cout << "3. Пятиугольник со сторонами 3, 4, 5, 6, 7:" << endl;
    double area5 = square(5, 3.0, 4.0, 5.0, 6.0, 7.0);
    cout << "   Площадь = " << area5 << endl;
    cout << endl;

    return 0;
}
