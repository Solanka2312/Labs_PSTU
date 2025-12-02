#include <iostream>
using namespace std;

int main() {
    int N;
    
    cout << "Введи размер куба (сторону N): ";
    cin >> N;
    
    if (N < 1) {
        cout << "Размер куба должен быть хотя бы 1!" << endl;
        return 1;
    }
    
    cout << "\nКуб размером " << N << ":\n" << endl;
    for (int i = 0; i < N/2 + 1; i++) {
        for (int space = 0; space < N/2 - i; space++) {
            cout << " ";
        }
        for (int j = 0; j < N; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N/2; j++) {
            cout << "* ";
        }
        for (int j = 0; j < N; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    return 0;
}