#include "Vector.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    Vector group(5);

    group.addPair(3, 45);
    group.addFraction(2, 75);
    group.addPair(5, 30);
    group.addFraction(4, 99);

    std::cout << "Содержимое группы:";
    std::cout << group;

    return 0;
}
