//метод ньютона или касательной
//f(x)= arccos(x) - /1- 0.3x**3 [0, 1]
//точность E = 0,000001
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float x, xPrev;
    double eps = 0.000001;
    //проверка что идет сначала а или б просто подставить сначала а в функцию и посчитать а потом б
    //f(b) = 3,14 * 0,84 > 0 тоесть икс нулевая будет Б(еслиб было меньше то взять а подставить в функцию и т.д)
    // f(a) = 1, 57 - 1 > 0 
    // (acos(a) - sqrt(1 - 0.3 * pow(a, 3)))
    x = 0;
    xPrev = 1;
    while(abs(x-xPrev)>eps)
    {
        xPrev = x;
        x = xPrev - (acos(xPrev) - sqrt(1 - 0.3 * pow(xPrev, 3))) / (((-1)/sqrt(1-pow(xPrev,2))) + ((0.45*pow(xPrev, 2))/sqrt(1- 0.3* pow(xPrev,3))));
    }
    cout << "Корень: " << x << endl;
    return 0;
}