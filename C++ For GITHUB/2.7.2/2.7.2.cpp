#include <iostream>
using namespace std;
int main(){
    int N;
    cout << "Введите N: ";
    cin >> N;
    cout << "2. Заполненный квадрат:" << endl;
    int i = 1;
    while (i <= N) {
        int j = 1;
        while (j <= N) {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
    cout << endl;
    return 0;
} 