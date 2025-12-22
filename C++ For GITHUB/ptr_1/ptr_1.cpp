#include <iostream>
using namespace std;


int main()
{
    int x, i;
    cin >> x;
    int *ptr = &x;
    cout << x << endl;

    cin >> i;

    *ptr = i;
    cout << x << endl;

    *ptr += 5;
    cout << x << endl;

    return 0;

}