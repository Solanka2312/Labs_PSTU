#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    string key;
    Node* prev;
    Node* next;
    
    Node(const string& k = "") : key(k), prev(nullptr), next(nullptr) {}
};

Node* createList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    cout << "\nВвод элементов списка:" << endl;
    for (int i = 0; i < n; i++) {
        string key;
        cout << "Элемент " << i + 1 << ": ";
        cin >> key;
        
        Node* newNode = new Node(key);
        
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

void printList(Node* head, const string& title) {
    if (!head) {
        cout << title << "Список пуст!" << endl;
        return;
    }
    
    cout << title << endl;
    
    Node* current = head;
    int count = 1;
    while (current) {
        cout << "Элемент " << count++ << ": " << current->key << endl;
        current = current->next;
    }
}

Node* deleteByKey(Node* head, const string& key) {
    if (!head) {
        cout << "Ошибка: Список пуст!" << endl;
        return nullptr;
    }
    
    Node* current = head;
    
    while (current && current->key != key) {
        current = current->next;
    }
    
    if (!current) {
        cout << "Элемент с ключом \"" << key << "\" не найден!" << endl;
        return head;
    }
    
    if (current->prev) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }
    
    if (current->next) {
        current->next->prev = current->prev;
    }
    
    delete current;
    cout << "Элемент с ключом \"" << key << "\" удален." << endl;
    return head;
}

Node* addBeforeKey(Node* head, const string& key, int k) {
    if (!head) {
        cout << "Ошибка: Список пуст!" << endl;
        return nullptr;
    }
    
    Node* current = head;
    
    while (current && current->key != key) {
        current = current->next;
    }
    
    if (!current) {
        cout << "Элемент с ключом \"" << key << "\" не найден!" << endl;
        return head;
    }
    
    cout << "\nВведите " << k << " новых элементов:" << endl;
    
    Node* prevNode = current->prev;
    
    for (int i = 0; i < k; i++) {
        string newKey;
        cout << "Новый элемент " << i + 1 << ": ";
        cin >> newKey;
        
        Node* newNode = new Node(newKey);
        newNode->next = current;
        newNode->prev = prevNode;
        
        if (prevNode) {
            prevNode->next = newNode;
        } else {
            head = newNode;
        }
        
        prevNode = newNode;
    }
    
    current->prev = prevNode;
    cout << k << " элементов добавлено перед элементом \"" << key << "\"." << endl;
    return head;
}

void saveToFile(Node* head, const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "Ошибка создания файла!" << endl;
        return;
    }
    
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    
    file.write((char*)&count, sizeof(count));
    
    current = head;
    while (current) {
        size_t len = current->key.size();
        file.write((char*)&len, sizeof(len));
        file.write(current->key.c_str(), len);
        current = current->next;
    }
    
    file.close();
    cout << "Список сохранен в файл \"" << filename << "\" (" << count << " элементов)." << endl;
}

void destroyList(Node*& head) {
    Node* current = head;
    int count = 0;
    
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
        count++;
    }
    
    head = nullptr;
    cout << "Список уничтожен (удалено " << count << " элементов)." << endl;
}

Node* restoreFromFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return nullptr;
    }
    
    int count;
    file.read((char*)&count, sizeof(count));
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < count; i++) {
        size_t len;
        file.read((char*)&len, sizeof(len));
        
        char* buffer = new char[len + 1];
        file.read(buffer, len);
        buffer[len] = '\0';
        
        Node* newNode = new Node(buffer);
        delete[] buffer;
        
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    file.close();
    cout << "Список восстановлен из файла \"" << filename << "\" (" << count << " элементов)." << endl;
    return head;
}

int main() {
    Node* list = nullptr;
    int n;
    
    // 1. Создание списка
    cout << "\n1. СОЗДАНИЕ СПИСКА" << endl;
    cout << "Введите количество элементов: ";
    cin >> n;
    list = createList(n);
    printList(list, "Созданный список:");
    
    // 2. Сохранение в файл
    cout << "\n2. СОХРАНЕНИЕ В ФАЙЛ" << endl;
    saveToFile(list, "list.dat");
    
    // 3. Удаление элемента
    cout << "\n3. УДАЛЕНИЕ ЭЛЕМЕНТА" << endl;
    string keyToDelete;
    cout << "Введите ключ для удаления: ";
    cin >> keyToDelete;
    list = deleteByKey(list, keyToDelete);
    printList(list, "Список после удаления:");
    
    // 4. Добавление элементов
    cout << "\n4. ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ" << endl;
    string keyBefore;
    int k;
    cout << "Введите ключ, перед которым добавить: ";
    cin >> keyBefore;
    cout << "Введите количество элементов K: ";
    cin >> k;
    list = addBeforeKey(list, keyBefore, k);
    printList(list, "Список после добавления:");
    
    // 5. Сохранение измененного списка
    cout << "\n5. СОХРАНЕНИЕ ИЗМЕНЕННОГО СПИСКА" << endl;
    saveToFile(list, "list_modified.dat");
    
    // 6. Уничтожение списка
    cout << "\n6. УНИЧТОЖЕНИЕ СПИСКА" << endl;
    destroyList(list);
    printList(list, "После уничтожения: ");
    
    // 7. Восстановление из файла
    cout << "\n7. ВОССТАНОВЛЕНИЕ ИЗ ФАЙЛА" << endl;
    list = restoreFromFile("list_modified.dat");
    printList(list, "Восстановленный список:");
    
    // 8. Окончательное уничтожение
    cout << "\n8. ОКОНЧАТЕЛЬНОЕ УНИЧТОЖЕНИЕ" << endl;
    destroyList(list);
    
    return 0;
}