#include <iostream>
using namespace std;

int main() {
    const int N = 4;
    int a[N][N] = {
        {5, 3, 8, 1},
        {2, 7, 4, 6},
        {9, 1, 3, 5},
        {4, 8, 2, 7}
    };
    
    cout << "Было:" << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < N; i++) {
        a[i][N-1-i] = 0;
    }

    cout << endl;
    
    cout << "Стало:" << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}