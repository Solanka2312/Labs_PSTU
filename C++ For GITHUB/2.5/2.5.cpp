#include <iostream>
using namespace std;

int main() {
    int N;
    
    cout << "Введите N (больше 2): ";
    cin >> N;
    
    // Проверяем, что N больше 2
    if (N <= 2) {
        cout << "Ошибка: N должно быть больше 2!" << endl;
        return 1;
    }
    
    cout << "Треугольник:" << endl;
    
    // Внешний цикл для строк (от 1 до N)
    int i = 1;
    while (i <= N) {
        
        // Внутренний цикл для пробелов
        int spaces = 0;
        while (spaces < N - i) {
            cout << " ";
            spaces++;
        }
        
        // Внутренний цикл для звездочек
        int stars = 0;
        while (stars < i) {
            cout << "*";
            stars++;
        }
        
        // Переход на новую строку
        cout << endl;
        i++;
    }
    
    return 0;
}