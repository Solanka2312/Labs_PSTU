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
    
    void deleteByKey(const char *key) {
        Node *curr = head;
        while (curr) {
            if (strcmp(curr->key, key) == 0) {
                if (curr->prev) curr->prev->next = curr->next;
                else head = curr->next;
                
                if (curr->next) curr->next->prev = curr->prev;
                else tail = curr->prev;
                
                delete[] curr->key;
                delete curr;
                cout << "Удален элемент: " << key << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Элемент с ключом '" << key << "' не найден" << endl;
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
    cout << "\nВведите ключ для удаления: ";
    cin >> key;
    
    list.deleteByKey(key);
    
    cout << "Список после удаления: ";
    list.print();
    
    return 0;
}