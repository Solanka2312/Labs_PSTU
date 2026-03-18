#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == b)
        return b;
    else if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

int main (){
    int n, m;
    cout << "Введите два числа: ";
    cin >> n >> m;
    while (n < 0 || m < 0){
        cout << "Ошибка. Введите числа ещё раз: ";
        cin >> n >> m;
    }
    if (n == 0 || m == 0){
        if (n == 0 && m == 0) cout << "Ошибка" << endl;
        else if (n == 0) cout << "НОДL " << m << endl;
        else cout << "НОД: " << n << endl;
    }
    else
        cout << "НОД: " << gcd(n,m);
    return 0;
}