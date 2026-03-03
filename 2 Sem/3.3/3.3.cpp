// Задача 3.3 - Найти максимальный элемент и сколько раз он встречается
#include <iostream>
using namespace std;

int main() {
    const int n = 11;
    int arr[n] = {41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22};
    int max = arr[0];
    int count = 1;
    
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Ищем максимум и считаем количество
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            count = 1;
        }
        else if (arr[i] == max) {
            count++;
        }
    }
    
    cout << "Максимальный элемент: " << max << endl;
    cout << "Встречается " << count << " раз(а)" << endl;
    
    return 0;
}