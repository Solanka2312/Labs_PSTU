// СОРТИРОВКА ВЫБОРОМ (Selection Sort)
#include <iostream>
using namespace std;

int main() {
    const int n = 7;
    int arr[n] = {5, 2, 4, 6, 0, 1, 3};
    int tmp, min_index;
    
    cout << "СОРТИРОВКА ВЫБОРОМ" << endl;
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < n-1; i++) {
        min_index = i;
        
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j; 
            }
        }
        
        if (min_index != i) {
            tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }
        
        cout << "После постановки " << i+1 << "-го элемента: ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
    
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}