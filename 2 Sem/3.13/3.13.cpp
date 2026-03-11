#include <iostream>
using namespace std;

int main() {
    const int R = 3, C = 3;
    int a[R][C] = {
        {3, 7, 0},
        {9, 4, 6},
        {5, 1, 2}
    };
    int row = 2;  // строка для сортировки
    
    cout << "До сортировки:" << endl;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Сортировка пузырьком столбцов
    for(int k = 0; k < C-1; k++) {
        for(int j = 0; j < C-1-k; j++) {
            if(a[row][j] > a[row][j+1]) {
                // Меняем столбцы местами
                for(int i = 0; i < R; i++) {
                    int temp = a[i][j];
                    a[i][j] = a[i][j+1];
                    a[i][j+1] = temp;
                }
            }
        }
    }
    
    cout << endl;

    cout << "После сортировки по строке " << row << ":" << endl;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}