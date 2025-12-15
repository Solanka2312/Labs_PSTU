#include <iostream>
using namespace std;

int main(){
    int n, tmp, max, min;
    cout << "Введите длину последовательности:" << endl;
    cin >> n;
    cout << "Введите первое число:" << endl;
    cin >> tmp;
    max = tmp;
    min = tmp;
    for (int i = 2; i <= n; i++){
        cout << "Введите следующее число:" << endl;
        cin >> tmp;
        if (tmp > max) { max = tmp; }
        else if (tmp < min) { min = tmp; }
    }
    cout << "Сумма максимального и минимального элементов: " << (max+min) << endl;
}