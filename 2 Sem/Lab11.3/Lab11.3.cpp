#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    char* key;
    Node *prev;
    Node *next;
};

class DoubleList {
private:
    Node *head;
    Node *tail;
    
public:
    DoubleList() : head(NULL), tail(NULL) {}
    
    void append(const char *str) {
        Node *newNode = new Node;
        newNode->key = new char[strlen(str) + 1];
        strcpy(newNode->key, str);
        newNode->next = NULL;
        newNode->prev = tail;
        
        if (tail) tail->next = newNode;
        else head = newNode;
        tail = newNode;
    }
    
    void print() {
        if (!head) {
            cout << "Список пуст" << endl;
            return;
        }
        Node *curr = head;
        while (curr) {
            cout << curr->key << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    Node* find(const char *key) {
        Node *curr = head;
        while (curr) {
            if (strcmp(curr->key, key) == 0) return curr;
            curr = curr->next;
        }
        return NULL;
    }
    
    void addAfterKey(const char *key, int k) {
        Node *target = find(key);
        if (!target) {
            cout << "Элемент с ключом '" << key << "' не найден" << endl;
            return;
        }
        
        Node *currentPos = target;
        for (int i = 0; i < k; i++) {
            char buffer[100];
            cout << "Введите строку " << i+1 << " для вставки после '" << key << "': ";
            cin >> buffer;
            
            Node *newNode = new Node;
            newNode->key = new char[strlen(buffer) + 1];
            strcpy(newNode->key, buffer);
            newNode->next = currentPos->next;
            newNode->prev = currentPos;
            
            if (currentPos->next) currentPos->next->prev = newNode;
            else tail = newNode;
            currentPos->next = newNode;
            currentPos = newNode;
        }
        cout << "Добавлено " << k << " элементов после '" << key << "'" << endl;
    }
    
    ~DoubleList() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete[] temp->key;
            delete temp;
        }
    }
};

int main() {
    DoubleList list;
    int n;

    cout << "Введите количество элементов списка: ";
    cin >> n;
    
    cout << "Введите строки (ключи):" << endl;
    for (int i = 0; i < n; i++) {
        char buffer[100];
        cin >> buffer;
        list.append(buffer);
    }
    
    cout << "\nИсходный список: ";
    list.print();
    
    char key[100];
    int k;
    
    cout << "\nВведите ключ: ";
    cin >> key;
    cout << "Введите количество элементов K для добавления: ";
    cin >> k;
    
    list.addAfterKey(key, k);
    
    cout << "Список после добавления: ";
    list.print();
    
    return 0;
}