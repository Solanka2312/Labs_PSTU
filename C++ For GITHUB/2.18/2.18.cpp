#include <iostream>
using namespace std;

int main(){
    int N;

    cout << "Введите натуральное число N: ";
    cin >> N;

    if (N <= 0){
        cout << "Число должно быть больше 0" << endl;
        return 0;
    }

    int reversed = 0;

    for (int temp = N; temp > 0; temp = temp / 10){
        int PoslChisl = temp % 10;

        reversed = reversed * 10 + PoslChisl;
    }
    
    cout << "Исходное число: " << N << endl;
    cout << "Перевёрнутое число: " << reversed << endl;

    return 0;
}