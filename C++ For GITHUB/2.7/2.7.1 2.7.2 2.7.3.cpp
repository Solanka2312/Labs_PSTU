#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Введите N: ";
    cin >> N;
    
    // 1. Всего N звездочек (минимум N = 1)
    cout << "1. " << N << " звездочек:" << endl;
    int ostalos = N;  // сколько звездочек осталось напечатать
    int stroka = 1;   // номер строки
    
    while (ostalos > 0) {
        int zvezdy_v_stroke = 1;
        while (zvezdy_v_stroke <= stroka && ostalos > 0) {
            cout << "*";
            zvezdy_v_stroke++;
            ostalos--;
        }
        cout << endl;
        stroka++;
    }
    cout << endl;
    
    // 2. Заполненный квадрат (минимум N = 1)
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