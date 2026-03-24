#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() { 
    string str;
    cout << "Введите строку (в конце точка): ";
    getline(cin, str);
    
    cout << "\nИсходная строка: " << str << endl;
    
    string withoutDigits;
    for (char c : str) {
        if (!isdigit(c)) {
            withoutDigits += c;
        }
    }
    cout << "Строка после удаления цифр: " << withoutDigits << endl;
    
    string letters;
    for (char c : withoutDigits) {
        if (isalpha(c)) {
            letters += c;
        }
    }
    sort(letters.begin(), letters.end());
    cout << "Буквы в алфавитном порядке: " << letters << endl;
    
    string result = withoutDigits;
    replace(result.begin(), result.end(), ' ', '_');
    cout << "Результат (пробелы заменены): " << result << endl;
    return 0;
}