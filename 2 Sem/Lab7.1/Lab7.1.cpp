#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int process(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int process(const string& str) {
    if (str.empty()) return 0;
    
    int wordCount = 0;
    bool inWord = false;
    
    for (char c : str) {
        if (c != ' ' && !inWord) {
            wordCount++;
            inWord = true;
        } else if (c == ' ') {
            inWord = false;
        }
    }
    return wordCount;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    cout << "Задание а)" << endl;
    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    cout << "Количество нечетных элементов: " << process(numbers, size) << endl;
    cout << endl;
    
    string text = "Это пример строки для подсчета количества слов";
    
    cout << "Задание б)" << endl;
    cout << "Строка: \"" << text << "\"" << endl;
    cout << "Количество слов: " << process(text) << endl;
    
    return 0;
}