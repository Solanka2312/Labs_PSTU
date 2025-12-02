#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Введите N: ";
    cin >> N;
    
    if (N % 2 == 0 || N <= 3) {
        cout << "N должно быть нечетным и больше 3!" << endl;
        return 1;
    }
    
    int line = 0;
    
    while (line <= N / 2) {
        int space = 0;
        while (space < N / 2 - line) {
            cout << " ";
            space++;
        }
        
        int star = 0;
        while (star < 2 * line + 1) {
            cout << "*";
            star++;
        }
        
        cout << endl;
        line++;
    }
    
    return 0;
}