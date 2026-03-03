// Задача 3.12 - Заменить элементы на побочной диагонали на 0
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
    
    // Обнуляем побочную диагональ (i + j == n - 1)
    for (int i = 0; i < n; i++) {
        arr[i][n-1-i] = 0;
    }
    
    cout << "Матрица после обнуления побочной диагонали:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}