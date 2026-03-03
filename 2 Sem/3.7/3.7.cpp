// Задача 3.7 - Найти и минимум, и максимум за один проход
#include <iostream>
using namespace std;

int main() {
    const int n = 11;
    int arr[n] = {41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22};
    int max = arr[0];
    int min = arr[0];
    
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Ищем и минимум, и максимум в одном цикле
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    cout << "Максимальный элемент: " << max << endl;
    cout << "Минимальный элемент: " << min << endl;
    
    return 0;
}