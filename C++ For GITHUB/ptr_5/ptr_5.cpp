#include <iostream>
using namespace std;
int main() {
	int n, f = 1;
	int *ptr_n = &n;
	int *ptr_f = &f;

	cin >> *ptr_n;

	for (size_t i = 1; i <= *ptr_n; i++) {
		*ptr_f *= i;
	}
	cout << f;
}