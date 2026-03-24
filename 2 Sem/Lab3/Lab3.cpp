#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double exactFunction(double x) {
    return (1 - x*x/2) * cos(x) - (x/2) * sin(x);
}


double nextTerm(double prevTerm, int n, double x) {
    if (n == 1) {
        return -1.5 * x * x;
    }
    double n_curr = n;
    double n_prev = n - 1;
    double coeff = -(2.0 * n_curr * n_curr + 1) / 
                   ((2.0 * n_curr - 1) * (2.0 * n_curr) * 
                    (2.0 * n_prev * n_prev + 1));
    return prevTerm * coeff * x * x;
}

double sumForN(double x, int n) {
    double sum = 1.0;  
    double term = 1.0;
    
    for (int i = 1; i <= n; i++) {
        term = nextTerm(term, i, x);
        sum += term;
    }
    return sum;
}

double sumForEpsilon(double x, double epsilon) {
    double sum = 1.0;
    double term = 1.0;
    int n = 1;
    
    while (fabs(term) >= epsilon) {
        term = nextTerm(term, n, x);
        sum += term;
        n++;
    }
    return sum;
}

int main() {
    
    double a = 0.1, b = 1.0;
    int k = 10;
    double step = (b - a) / k;
    double epsilon = 0.0001;
    int n = 35;
    
    cout << fixed << setprecision(6);
    cout << left << setw(12) << "x" 
         << setw(15) << "S (n=" + to_string(n) + ")" 
         << setw(15) << "S (eps)" 
         << "Y (точное)" << endl;
    
    for (double x = a; x <= b + step/2; x += step) {
        double sumN = sumForN(x, n);
        double sumEps = sumForEpsilon(x, epsilon);
        double yExact = exactFunction(x);
        
        cout << fixed << setprecision(6);
        cout << left << setw(12) << x 
             << setw(15) << sumN 
             << setw(15) << sumEps 
             << yExact << endl;
    }

    return 0;
}