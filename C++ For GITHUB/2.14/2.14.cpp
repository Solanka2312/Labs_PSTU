#include <iostream>

using namespace std;

int main() {
    int N, sum = 0;
    
    // Шаг 1: Ввод числа
    cout << "Введите натуральное число N: ";
    cin >> N;
    
    // Проверка, что число натуральное
    if (N <= 0) {
        cout << "Число должно быть натуральным (больше 0)!" << endl;
        return 0;
    }
    
    // Шаг 2: Вычисляем сумму цифр через for
    for (int temp = N; temp > 0; temp = temp / 10) {
        // Берём последнюю цифру
        int digit = temp % 10;
        
        // Добавляем к сумме
        sum += digit;
    }
    
    // Шаг 3: Выводим результат
    cout << "Сумма цифр числа " << N << " = " << sum << endl;
    
    return 0;
}