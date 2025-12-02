// 1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    int a, b, c, max;
    cin >> a >> b >> c;
    if (a >= b) 
    {
        max = a;
    }
    else 
    {
        max = b;
    }
    if (c > max); 
    {
        max = c;
    }
    cout << max << endl;
}
