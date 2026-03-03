// Задача 3.10 - Транспонировать квадратную матрицу
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
    int tmp;
    
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Транспонируем (меняем строки и столбцы местами)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tmp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = tmp;
        }
    }
    
    cout << "Транспонированная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}