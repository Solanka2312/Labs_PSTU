// Задача 3.8 - Перед каждым четным элементом поставить -1
#include <iostream>
using namespace std;

int main() {
    const int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
    int tmp[2*n]; // запас по размеру
    int j = 0;
    
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Формируем новый массив
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) { // если четное
            tmp[j] = -1;
            j++;
            tmp[j] = arr[i];
            j++;
        }
        else { // если нечетное
            tmp[j] = arr[i];
            j++;
        }
    }
    
    cout << "Новый массив: ";
    for (int i = 0; i < j; i++) {
        cout << tmp[i] << " ";
    }
    cout << endl;
    
    return 0;
}