#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Введите количество строк: ";
    cin >> n;
    cin.ignore();
    
    vector<string> arr(n);
    
    cout << "\nВведите " << n << " строк:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Строка " << i + 1 << ": ";
        getline(cin, arr[i]);
    }
    
    cout << "\nИсходный массив строк:" << endl;
    for (size_t i = 0; i < arr.size(); i++) {
        cout << i + 1 << ": " << arr[i] << endl;
    };
    
    int startIndex, k;
    cout << "\nВведите номер строки, начиная с которой удалять (1-" << arr.size() << "): ";
    cin >> startIndex;
    cout << "Введите количество удаляемых строк K: ";
    cin >> k;
    
    if (startIndex < 1 || startIndex > static_cast<int>(arr.size())) {
        cout << "Ошибка: Неверный номер строки!" << endl;
        return 1;
    }
    
    int start = startIndex - 1;
    int actualK = min(k, static_cast<int>(arr.size() - start));
    
    if (actualK != k) {
        cout << "\nПредупреждение: K уменьшено до " << actualK 
             << " (выход за границы массива)" << endl;
    }
    
    arr.erase(arr.begin() + start, arr.begin() + start + actualK);
    
    cout << "\nМассив после удаления:" << endl;
    if (arr.empty()) {
        cout << "Массив пуст (удалены все элементы)" << endl;
    } else {
        for (size_t i = 0; i < arr.size(); i++) {
            cout << i + 1 << ": " << arr[i] << endl;
        }
    }

    cout << "Удалено строк: " << actualK << endl;
    cout << "Осталось строк: " << arr.size() << endl;
    
    return 0;
}