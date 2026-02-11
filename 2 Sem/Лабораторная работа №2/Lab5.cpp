#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int stack[MAX_SIZE];  
int top = -1;

// Функция для добавления элемента в стек
void push(int value) {
    // Проверяем, не полон ли стек
    if (top >= MAX_SIZE - 1) {
        cout << "Ой! Стек переполнен! Не могу добавить " << value << endl;
        return;
    }
    
    // Увеличиваем top и добавляем элемент
    top++;
    stack[top] = value;
    
    cout << "Добавил " << value << " в стек" << endl;
}

// Функция для удаления элемента из стека
void pop() {
    // Проверяем, не пустой ли стек
    if (top < 0) {
        cout << "Ой! Стек пустой! Нечего удалять" << endl;
        return;
    }
    
    cout << "Удалил " << stack[top] << " из стека" << endl;
    
    top--;
}

// Функция для печати стека
void printStack() {
    cout << "Сейчас в стеке: ";
    
    // Если стек пустой
    if (top < 0) {
        cout << "пусто!";
    } else {
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
    }
    
    cout << endl;
    cout << "Верхний элемент: ";
    if (top >= 0) {
        cout << stack[top];
    } else {
        cout << "нет";
    }
    cout << endl << endl;
}

int main() {
    
    // Тестируем наш стек
    push(10);      // Добавляем 10
    printStack();  // Печатаем
    
    push(20);      
    printStack();
    
    push(30);      
    printStack();  
    
    pop();         // Удаляем верхний элемент
    printStack();  // Печатаем
    
    push(40);      
    printStack();  
    
    pop();         // Удаляем
    printStack();  // Печатаем
    
    pop();         
    printStack();  
    
    pop();         // Пытаемся удалить из пустого стека
    printStack();  // Печатаем
    
   
    return 0;
}