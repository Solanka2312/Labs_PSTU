#include <iostream>
using namespace std;

int main(){
    int N, S;
    
    cout << "Введите число N:";
    cin >> N;
    cout << "Введите цифру от 0 - 9:";
    cin >> S;

    if (N <= 0) {
        cout << "Число должно быть больше 0" << endl;
        return 0;
    }

    if (S < 0 || S > 9){
    cout << "S - Цифра должна быть от 0 - 9:" << endl;
    return 0;
    }
    
    bool found = false; // Flag не найден

    for (int temp = N; temp > 0; temp = temp / 10){
        int lc = temp % 10;
        
        if (lc == S){
            found = true;
            break;
        }
    }

    if (found){
        cout << "Цифра " << S << " входит в отрезок" << endl;
    } else {
        cout << "Цифра " << S << " не входит в отрезок" << endl;
    }

    return 0;
}