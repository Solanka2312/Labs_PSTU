#include <iostream>
using namespace std;

int main(){
    int N;
    cout << "Введите начальное число: " << endl;
    cin >> N;
    int *ptr = &N;
    cout << "Введите изм. число: " << endl;

    cin >> *ptr;
    cout << N << endl;
    return 0;
}