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
        int index = 0;
        while (curr) {
            cout << "[" << index << "]" << curr->key << " ";
            curr = curr->next;
            index++;
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
    
    void deleteByIndex(int index) {
        Node *curr = head;
        int i = 0;
        while (curr && i < index) {
            curr = curr->next;
            i++;
        }
        if (!curr) {
            cout << "Элемент с номером " << index << " не найден" << endl;
            return;
        }
        
        if (curr->prev) curr->prev->next = curr->next;
        else head = curr->next;
        
        if (curr->next) curr->next->prev = curr->prev;
        else tail = curr->prev;
        
        cout << "Удален элемент с номером " << index << ": " << curr->key << endl;
        delete[] curr->key;
        delete curr;
    }
    
    void addBeforeKey(const char *key, int k) {
        Node *target = find(key);
        if (!target) {
            cout << "Элемент с ключом '" << key << "' не найден" << endl;
            return;
        }
        
        for (int i = 0; i < k; i++) {
            char buffer[100];
            cout << "Введите строку " << i+1 << " для вставки ПЕРЕД '" << key << "': ";
            cin >> buffer;
            
            Node *newNode = new Node;
            newNode->key = new char[strlen(buffer) + 1];
            strcpy(newNode->key, buffer);
            newNode->prev = target->prev;
            newNode->next = target;
            
            if (target->prev) target->prev->next = newNode;
            else head = newNode;
            target->prev = newNode;
        }
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
            cout << "Введите строку " << i+1 << " для вставки ПОСЛЕ '" << key << "': ";
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
    
    cout << "\nИсходный список (с номерами): ";
    list.print();
    
    int index;
    cout << "\nУдаление по номеру" << endl;
    cout << "Введите номер элемента для удаления: ";
    cin >> index;
    list.deleteByIndex(index);
    
    cout << "Список после удаления: ";
    list.print();
    
    cout << "\nДобавление перед и после ключа" << endl;
    char key[100];
    int k;
    
    cout << "Введите ключ: ";
    cin >> key;
    cout << "Введите количество элементов K для добавления: ";
    cin >> k;
    
    cout << "\nДобавление ПЕРЕД '" << key << "':" << endl;
    list.addBeforeKey(key, k);
    
    cout << "\nДобавление ПОСЛЕ '" << key << "':" << endl;
    list.addAfterKey(key, k);
    
    cout << "\nСписок после всех операций: ";
    list.print();
    
    return 0;
}