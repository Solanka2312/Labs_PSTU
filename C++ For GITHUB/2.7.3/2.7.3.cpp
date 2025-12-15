#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Введите N: ";
    cin >> N;
    // 3. Пустой квадрат (минимум N = 2)
    cout << "3. Пустой квадрат:" << endl;
    int stroka3 = 1;
    while (stroka3 <= N) {
        int mesto = 1;
        while (mesto <= N) {
            // Если это первая или последняя строка, или первое или последнее место - печатаем звезду
            if (stroka3 == 1 || stroka3 == N || mesto == 1 || mesto == N) {
                cout << "*";
            } else {
                cout << " ";  // внутри квадрата - пробелы
            }
            mesto++;
        }
        cout << endl;
        stroka3++;
    }
    
    return 0;
}