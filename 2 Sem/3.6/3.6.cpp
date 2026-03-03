// Задача 3.6 - Циклически сдвинуть массив на k элементов влево
#include <iostream>
using namespace std;

int main() {
    const int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
    int k;
    
    cout << "Введите k: ";
    cin >> k;
    
    k = k % n; // если k больше размера массива
    
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Создаем временный массив
    int tmp[n];
    
    // Сдвигаем элементы
    for (int i = 0; i < n; i++) {
        int new_pos = i - k;
        if (new_pos < 0) {
            new_pos += n;
        }
        tmp[new_pos] = arr[i];
    }
    
    // Копируем обратно
    for (int i = 0; i < n; i++) {
        arr[i] = tmp[i];
    }
    
    cout << "Массив после сдвига: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}