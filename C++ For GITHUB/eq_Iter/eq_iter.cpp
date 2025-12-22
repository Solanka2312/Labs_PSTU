//метод итераций
//f(x)= arccos(x) - /1- 0.3x**3 [0, 1]
//точность E = 0,000001
// f'(x) = (((-1)/sqrt(1-pow(xPrev,2))) + ((0.45*pow(xPrev, 2))/sqrt(1- 0.3* pow(xPrev,3))))
// ф(x) = x + lambda(acos(a) - sqrt(1 - 0.3 * pow(a, 3))) - подставлем исходную функцию в формулу для фи
// выбираем лямбду по условию:
// -1/r < lambda < 0 если f'(x) > 0
//0 < lambda < 1/r если f'(x) < 0
//как понять значение r
//r = max(|f'(a)|, |f'(b)|) - берем макс значение по модулю производной в концах диапозона если в a производная больше берем |f'(a)| 

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float x, xPrev;
    double eps = 0.000001, lambda = 0.5;
    x = 1;
    xPrev = 0;
    while(abs(x-xPrev)>eps)
    {
        xPrev = x;
        x = lambda * (acos(xPrev) - sqrt(1 - 0.3 * pow(xPrev, 3))) + xPrev;
    }
    cout << "корень по методу итерации: " << x << endl;
    return 0;
}