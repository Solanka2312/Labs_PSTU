#include <iostream> 
using namespace std; 
int main(){
    int N, S;
    cout << "Введите первое число: "; 
    cin >> N;
    cout << "Введите второе число: "; 
    cin >> S;
    int *ptr1 = &N; 
    int *ptr2 = &S; 
    int tmp = *ptr1; 
    *ptr1 = *ptr2; 
    *ptr2 = tmp;
    cout << N << S << endl;

    return 0;
}