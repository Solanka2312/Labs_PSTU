#include <iostream>
#include <string.h>
using namespace std;

char** deleteFirstRows(char **arr, int &size, int k) {
    if (k <= 0) {
        cout << "Ничего не удалено (K <= 0)" << endl;
        return arr;
    }
    
    if (k >= size) {
        cout << "Удаляем все " << size << " строк" << endl;
        for (int i = 0; i < size; i++) {
            delete[] arr[i];
        }
        delete[] arr;
        size = 0;
        return NULL;
    }
    
    int newSize = size - k;
    char **newArr = new char*[newSize];
    
    for (int i = k; i < size; i++) {
        newArr[i - k] = new char[strlen(arr[i]) + 1];
        strcpy(newArr[i - k], arr[i]);
    }
    
    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    size = newSize;
    return newArr;
}

int main() {
    int n;
 
    cout << "Введите количество строк: ";
    cin >> n;
    cin.get(); 
    
    char **strings = new char*[n];
    
    cout << "Введите строки:" << endl;
    for (int i = 0; i < n; i++) {
        char buffer[256];
        cin.getline(buffer, 256);
        strings[i] = new char[strlen(buffer) + 1];
        strcpy(strings[i], buffer);
    }
    
    cout << "\nИсходный массив:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  [" << i << "] " << strings[i] << endl;
    }
    
    int k;
    cout << "\nВведите количество строк K для удаления из начала: ";
    cin >> k;
    
    strings = deleteFirstRows(strings, n, k);
    
    cout << "\nМассив после удаления (размер = " << n << "):" << endl;
    if (n == 0) {
        cout << "  Массив пуст" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << "  [" << i << "] " << strings[i] << endl;
        }
    }
    
    for (int i = 0; i < n; i++) {
        delete[] strings[i];
    }
    delete[] strings;
    
    return 0;
}