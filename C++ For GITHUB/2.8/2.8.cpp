#include <iostream>
using namespace std;

int main() {
    int N;
    
    // Ввод размера треугольника
    cout << "Введите N (больше 2): ";
    cin >> N;
    
    // Проверка, что N больше 2
    if (N <= 2) {
        cout << "N должно быть больше 2!" << endl;
        return 1;
    }
    
    // Рисуем треугольник
    for (int i = 1; i <= N; i++) {          // i - номер строки
        for (int j = 1; j <= i; j++) {      // j - количество звёздочек в строке
            cout << "*";
        }
        cout << endl;  // переход на новую строку
    }
    
    return 0;
}