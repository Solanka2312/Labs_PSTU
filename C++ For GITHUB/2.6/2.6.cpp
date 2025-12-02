#include <iostream>
using namespace std;

int main() {
    int N;
    
    cout << "Введите N: ";
    cin >> N;
    
    int s = N;
    
    while (s > 0) {
        int z = 1;
        while (z <= s) {
            cout << "*";
            z++;
        }
        
        cout << endl;
        
        s--;
    }
    
    return 0;
}