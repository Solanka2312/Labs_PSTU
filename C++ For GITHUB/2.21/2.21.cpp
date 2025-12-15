#include <iostream>
using namespace std;

int main(){
    int T, P;
    bool flag = true;

    cout << "Вводите число (0 для окончания ввода):" << endl;

    cin >> P;

    if (P == 0){
        cout << "Последовательность пустая!" << endl;
        return 0;
    }

    while (true){
        cin >> T;

        if (T == 0){
            break;
        }

        if (T <= P){
            flag = false;
        }

        P = T;
    }
    
    if (flag){
        cout << "Числа упорядочены по возрастанию!" << endl;
    } else {
        cout << "Числа НЕ упорядочены по возрастанию!" << endl;
    }

    return 0;
}