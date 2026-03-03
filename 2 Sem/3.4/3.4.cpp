// Задача 3.4 - Найти минимальный элемент и сколько раз он встречается
#include <iostream>
using namespace std;

int main() {
    const int n = 11;
    int arr[n] = {41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22};
    int min = arr[0];
    int count = 1;
    
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Ищем минимум и считаем количество
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            count = 1;
        }
        else if (arr[i] == min) {
            count++;
        }
    }
    
    cout << "Минимальный элемент: " << min << endl;
    cout << "Встречается " << count << " раз(а)" << endl;
    
    return 0;
}