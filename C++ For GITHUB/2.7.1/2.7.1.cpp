#include <iostream>
using namespace std;

int main(){
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
}