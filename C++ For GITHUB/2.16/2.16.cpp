#include <iostream>
using namespace std;

int main(){
    int N;

    cout << "Введите количество слагаемых N:";
    cin >> N;

    if (N <= 0){
        cout << "N должно быть натуральным числом!" << endl;
        return 0;
    }

    int S = 0;

    for (int i = 1; i <= N; i++){
        if (i % 2 == 1){
            S -= i;
        } else {
            S += i;
        }
    }
    
    cout << "Сумма S = " << S << endl;
    return 0;
}