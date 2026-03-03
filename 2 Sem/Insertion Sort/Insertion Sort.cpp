// СОРТИРОВКА ВСТАВКАМИ (Insertion Sort)
#include <iostream>
using namespace std;

int main() {
    const int n = 7;
    int arr[n] = {5, 2, 4, 6, 0, 1, 3};
    int key, j;
    
    cout << "СОРТИРОВКА ВСТАВКАМИ" << endl;
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < n; i++) {
        key = arr[i]; 
        j = i - 1;    

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j]; 
            j--;
        }

        arr[j+1] = key;

        cout << "После вставки элемента " << key << ": ";
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