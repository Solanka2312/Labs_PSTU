#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

int countWords(const string& line) {
    if (line.empty()) return 0;
    
    int count = 0;
    bool inWord = false;
    
    for (char c : line) {
        if (c != ' ' && !inWord) {
            count++;
            inWord = true;
        } else if (c == ' ') {
            inWord = false;
        }
    }
    return count;
}

int countVowels(const string& word) {
    int count = 0;
    for (char c : word) {
        char lower = tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' || 
            lower == 'o' || lower == 'u' || lower == 'y') {
            count++;
        }
    }
    return count;
}

void findMaxVowelsWord(const string& text) {
    if (text.empty()) {
        cout << "Текст пуст!" << endl;
        return;
    }
    
    vector<string> words;
    stringstream ss(text);
    string word;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    if (words.empty()) {
        cout << "В тексте нет слов!" << endl;
        return;
    }
    
    int maxVowels = -1;
    int maxIndex = -1;
    
    for (size_t i = 0; i < words.size(); i++) {
        int vowels = countVowels(words[i]);
        if (vowels > maxVowels) {
            maxVowels = vowels;
            maxIndex = i;
        }
    }
    
    cout << "Слово с максимальным количеством гласных (" << maxVowels << "): " 
         << words[maxIndex] << " (номер " << maxIndex + 1 << ")" << endl;
}

int main() {
    cout << "Лабораторная работа №9 - Строковый ввод-вывод" << endl;
    cout << "==============================================" << endl;
    
    ofstream f1("F1.txt");
    if (!f1) {
        cerr << "Ошибка создания файла F1!" << endl;
        return 1;
    }
    
    f1 << "Эта строка содержит три слова\n";
    f1 << "Короткая\n";
    f1 << "Строка с очень большим количеством слов для проверки задания\n";
    f1 << "Еще одна строка с несколькими словами\n";
    f1 << "Здесь мы напишем предложение из пяти слов\n";
    f1 << "Слово\n";
    f1.close();
    cout << "Файл F1 создан с 6 строками." << endl;
    
    ifstream f1r("F1.txt");
    ofstream f2("F2.txt");
    
    if (!f1r || !f2) {
        cerr << "Ошибка открытия файлов!" << endl;
        return 1;
    }
    
    string line;
    int copiedLines = 0;
    cout << "\nЗадание 1: Копирование строк с >2 словами" << endl;
    while (getline(f1r, line)) {
        int words = countWords(line);
        if (words > 2) {
            f2 << line << '\n';
            copiedLines++;
            cout << "Скопирована: \"" << line << "\" (слов: " << words << ")" << endl;
        }
    }
    f1r.close();
    f2.close();
    cout << "Всего скопировано строк: " << copiedLines << endl;
    
    ifstream f2r("F2.txt");
    if (!f2r) {
        cerr << "Ошибка открытия файла F2!" << endl;
        return 1;
    }
    
    cout << "\nЗадание 2: Поиск слова с максимальным количеством гласных" << endl;
    cout << "Содержимое файла F2:" << endl;
    
    string fullText;
    while (getline(f2r, line)) {
        cout << "  " << line << endl;
        fullText += line + " ";
    }
    f2r.close();
    
    cout << "\nРезультат поиска:" << endl;
    findMaxVowelsWord(fullText);

    return 0;
}