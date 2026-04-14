#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    string vowels = "aeiouаеёиоуыэюя";
    for (char v : vowels) {
        if (c == v) return true;
    }
    return false;
}

int countWords(const string& line) {
    istringstream iss(line);
    string word;
    int cnt = 0;
    while (iss >> word) cnt++;
    return cnt;
}

int countVowelsInWord(const string& word) {
    int cnt = 0;
    for (char c : word) {
        if (isVowel(c)) cnt++;
    }
    return cnt;
}

void findWordWithMaxVowels(const string& line, int& bestWordIndex, int& maxVowels) {
    istringstream iss(line);
    string word;
    int currentIndex = 0;
    bestWordIndex = -1;
    maxVowels = -1;
    
    while (iss >> word) {
        int vowels = countVowelsInWord(word);
        if (vowels > maxVowels) {
            maxVowels = vowels;
            bestWordIndex = currentIndex;
        }
        currentIndex++;
    }
}

void createTestFile() {
    ofstream f1("F1.txt");
    if (!f1) {
        cerr << "Ошибка создания F1.txt\n";
        return;
    }
    
    f1 << "Привет мир как дела\n";
    f1 << "Короткая строка\n";
    f1 << "Это строка с тремя словами\n";
    f1 << "Еще одна длинная строка для проверки\n";
    f1 << "Два слова\n";
    f1 << "Программирование на C++ очень интересно\n";
    f1 << "Коротко\n";
    f1 << "А эта строка содержит много разных слов для теста\n";
    f1 << "Просто\n";
    f1 << "Последняя строка с большим количеством слов и гласными буквами\n";
    
    f1.close();
    cout << "Создан тестовый файл F1.txt\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    ifstream test("F1.txt");
    if (!test) {
        test.close();
        cout << "Файл F1.txt не найден. Создаю тестовый файл...\n";
        createTestFile();
    } else {
        test.close();
    }
    
    ifstream f1("F1.txt");
    ofstream f2("F2.txt");
    
    if (!f1) {
        cerr << "Ошибка открытия F1.txt\n";
        return 1;
    }
    
    if (!f2) {
        cerr << "Ошибка создания F2.txt\n";
        return 1;
    }
    
    string line;
    int globalMaxVowels = -1;
    int globalWordNumber = -1;
    int currentWordNumber = 1;
    
    cout << "\nСодержимое F1.txt\n";
    ifstream temp("F1.txt");
    string tempLine;
    while (getline(temp, tempLine)) {
        cout << tempLine << '\n';
    }
    temp.close();
     
    while (getline(f1, line)) {
        int wordCnt = countWords(line);
        
        if (wordCnt > 2) {
            f2 << line << '\n';
            cout << "Скопировано: \"" << line << "\" (слов: " << wordCnt << ")\n";
            
            int wordPos, maxVowelsInLine;
            findWordWithMaxVowels(line, wordPos, maxVowelsInLine);
            
            if (wordPos != -1) {
                int absoluteWordNumber = currentWordNumber + wordPos;
                if (maxVowelsInLine > globalMaxVowels) {
                    globalMaxVowels = maxVowelsInLine;
                    globalWordNumber = absoluteWordNumber;
                }
            }
        }
        
        currentWordNumber += countWords(line);
    }
    
    f1.close();
    f2.close();
    
    if (globalWordNumber == -1) {
        cout << "Не найдено строк с более чем 2 словами\n";
    } else {
        cout << "Cлова с наибольшим количеством гласных: " << globalWordNumber << '\n';
        cout << "Количество гласных в этом слове: " << globalMaxVowels << '\n';
    }
    
    cout << "\nСодержимое F2.txt\n";
    ifstream f2out("F2.txt");
    if (f2out) {
        string outLine;
        bool hasContent = false;
        while (getline(f2out, outLine)) {
            cout << outLine << '\n';
            hasContent = true;
        }
        if (!hasContent) {
            cout << "(файл пуст)\n";
        }
        f2out.close();
    }
    
    return 0;
}