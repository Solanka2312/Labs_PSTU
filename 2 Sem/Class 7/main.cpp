#include "Set.h"
#include "Money.h"
#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Set A;
    std::cout << "Пустое множество A: " << A << std::endl;
    std::cin >> A;
    std::cout << "A после ввода: " << A << std::endl;
    if ((int)A > 0)
    {
        std::cout << "Первый элемент A[0] = " << A[0] << std::endl;
        A[0] = 100;
        std::cout << "После A[0] = 100: " << A << std::endl;
    }

    Set B;
    B.add(5);
    B.add(100);
    B.add(7);
    std::cout << "Множество B: " << B << std::endl;

    Set C = A * B;
    std::cout << "Пересечение A * B: " << C << std::endl;

    std::cout << "Размер A через int(): " << (int)A << " элементов" << std::endl;

    Set D = C;
    std::cout << "Копия D = C: " << D << std::endl;

    Set E;
    E = B;
    std::cout << "Присваивание E = B: " << E << std::endl;

    std::cout << " Тестирование класса Money " << std::endl;

    Money m1(150, 75);
    Money m2(50, 25);
    Money m3 = m1 + m2;
    std::cout << m1 << " + " << m2 << " = " << m3 << std::endl;
    Money m4 = m1 * 2.5;
    std::cout << m1 << " * 2.5 = " << m4 << std::endl;
    Money m5 = m1 / m2;
    std::cout << m1 << " / " << m2 << " = " << m5 << std::endl;
    Money m6 = m1 / 3;
    std::cout << m1 << " / 3 = " << m6 << std::endl;

    return 0;
}
