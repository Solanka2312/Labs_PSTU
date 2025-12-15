#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int S = 0;
    int i = 1;
    
    while (i <= N) {
        long long term = 1;
        int j = 0;
        
        while (j <= i) {
            term *= (i + j);
            j++;
        }
        
        S += term;
        i++;
    }
    
    cout << "Сумма S = " << S << endl;
    return 0;

}
