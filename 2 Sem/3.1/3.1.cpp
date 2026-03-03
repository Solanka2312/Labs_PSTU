// Задача 3.1 - Перевернуть весь массив
#include <iostream>
using namespace std;

int main() {
    const int n = 4;
    int arr[n] = {41, 42, 66, 77};
    int tmp;
    
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Переворачиваем массив
    for (int i = 0; i < n/2; i++) {
        tmp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = tmp;
    }
    
    cout << "Перевернутый массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}