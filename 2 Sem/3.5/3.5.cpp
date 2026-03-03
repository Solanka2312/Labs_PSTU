// Задача 3.5 - Найти максимальный элемент массива
#include <iostream>
using namespace std;

int main() {
    const int n = 11;
    int arr[n] = {41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22};
    int max = arr[0];
    
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Ищем максимальный элемент
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    cout << "Максимальный элемент: " << max << endl;
    
    return 0;
}