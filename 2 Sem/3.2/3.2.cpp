// Задача 3.2 - Перевернуть часть массива от p до q
#include <iostream>
using namespace std;

int main() {
    const int n = 11;
    int arr[n] = {41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22};
    int p = 2, q = 6; // переворачиваем с индекса 2 по индекс 6
    int tmp;
    
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Переворачиваем часть массива
    int start = p, end = q;
    while (start < end) {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
    
    cout << "Массив после переворота части: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}