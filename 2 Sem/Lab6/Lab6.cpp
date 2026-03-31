#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX_LEN = 256;

bool areAllLettersUnique(const char* word, int len) {
    if (len <= 1) {
        return true;
    }
    
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (word[i] == word[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char str[MAX_LEN];
    
    cout << "Введите строку (до " << MAX_LEN - 1 << " символов, в конце точка):" << endl;
    cin.getline(str, MAX_LEN);
    
    int len = strlen(str);
    if (len > 0 && str[len - 1] != '.') {
        cout << "Предупреждение: строка не заканчивается точкой!" << endl;
    }
    
    const int MAX_WORDS = 100;
    char words[MAX_WORDS][MAX_LEN];
    int wordCount = 0;
    
    char currentWord[MAX_LEN];
    int currentWordLen = 0;
    
    for (int i = 0; i <= len; i++) {
        char ch = str[i];
        
        if (ch == ' ' || ch == '\t' || ch == '.' || ch == '\0') {
            if (currentWordLen > 0) {
                currentWord[currentWordLen] = '\0'; 
                strcpy(words[wordCount], currentWord);
                wordCount++;
                currentWordLen = 0;
            }
        } 

        else {
            currentWord[currentWordLen] = ch;
            currentWordLen++;
        }
    }
    
    cout << "\nСлова, в которых все буквы различны (не повторяются):" << endl;
    int foundCount = 0;
    
    for (int i = 0; i < wordCount; i++) {
        int wordLen = strlen(words[i]);
        
        if (areAllLettersUnique(words[i], wordLen)) {
            cout << words[i] << endl;
            foundCount++;
        }
    }
    
    if (foundCount == 0) {
        cout << "Таких слов не найдено." << endl;
    }
    
    cout << "\nВсего слов в строке: " << wordCount << endl;
    cout << "Слов с уникальными буквами: " << foundCount << endl;
    
    return 0;
}