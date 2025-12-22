#include <iostream>
using namespace std;
int main()
{
    float a = 3.14f, b = 2.17f, sum;
    float* ptr_a = &a;
    float* ptr_b = &b;
    sum = *ptr_a + *ptr_b;

    cout << a <<" "<< b << endl;
    cout << "a" << "+" << "b" << "=" << sum << endl;

    return 0;
}