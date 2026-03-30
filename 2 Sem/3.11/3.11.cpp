// Задача 3.11 - Заменить элементы на главной диагонали на 0
#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    int arr[n][n] = {
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4},
        {5, 5, 5, 5, 5}
    };
    
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Обнуляем главную диагональ (элементы, где i == j)
    for (int i = 0; i < n; i++) {
        arr[i][i] = 0;
    }
    
    cout << "Матрица после обнуления главной диагонали:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}