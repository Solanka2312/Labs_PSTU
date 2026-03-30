// Задача 3.13 - Отсортировать матрицу по заданной строке
#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    int arr[n][n] = {
        {3, 7, 0},
        {9, 4, 6},
        {5, 1, 2}
    };
    int k = 1; // сортируем по первой строке (индекс 1)
    int tmp;
    
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "Сортируем по строке " << k << endl;
    
    // Сортируем пузырьком по строке k, переставляя столбцы
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[k][j] > arr[k][j+1]) {
                // Меняем местами столбцы j и j+1
                for (int r = 0; r < n; r++) {
                    tmp = arr[r][j];
                    arr[r][j] = arr[r][j+1];
                    arr[r][j+1] = tmp;
                }
            }
        }
    }
    
    cout << "Матрица после сортировки:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}