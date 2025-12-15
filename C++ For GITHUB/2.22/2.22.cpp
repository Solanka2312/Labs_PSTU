#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float n, a, max;
    int i = 2; // Чтобы последовательность была приличная
    int numFirst = 1;
    int numLast = 1;

    cin >> n;

    max = sin (n + 1/n);

    while (i <= n){
        a = sin(n + i/n);
        if (a > max){
            max = a;
            numFirst = i;
            numLast = i;
        }
        else if (a == max){
            numLast = i;
        }
        i++;
    }
    cout << "Максимальный элемнт: " << max << endl;
    cout << "& первого элемента с таким значением: " << numFirst << endl;
    cout << "& последнего элемента с таким значением: " << numLast << endl;
}