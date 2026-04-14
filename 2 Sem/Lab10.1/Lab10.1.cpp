#include <iostream>
#include <string.h>
using namespace std;

char** deleteRows(char **arr, int &size, int startIndex, int k) {
    if (startIndex < 0 || startIndex >= size) {
        cout << "Ошибка: неверный номер строки!" << endl;
        return arr;
    }
    
    if (startIndex + k > size) {
        k = size - startIndex;
        cout << "Предупреждение: удаляем только " << k << " строк (до конца массива)" << endl;
    }
    
    if (k <= 0) {
        cout << "Ничего не удалено" << endl;
        return arr;
    }
    
    int newSize = size - k;
    char **newArr = new char*[newSize];
    
    for (int i = 0; i < startIndex; i++) {
        newArr[i] = new char[strlen(arr[i]) + 1];
        strcpy(newArr[i], arr[i]);
    }
    
    for (int i = startIndex + k; i < size; i++) {
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
    
    int start, k;
    cout << "\nВведите номер строки, с которой начать удаление: ";
    cin >> start;
    cout << "Введите количество строк K для удаления: ";
    cin >> k;
    
    strings = deleteRows(strings, n, start, k);
    
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