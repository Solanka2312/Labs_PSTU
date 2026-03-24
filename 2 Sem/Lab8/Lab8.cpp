#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Структура "Владелец автомобиля"
struct Owner {
    string fio;
    string carNumber;
    string techPassport;
    string registration;
};

// Функция для записи одной структуры в файл
void writeOwner(ofstream& file, const Owner& o) {
    size_t len;
    
    len = o.fio.size();
    file.write((char*)&len, sizeof(len));
    file.write(o.fio.c_str(), len);
    
    len = o.carNumber.size();
    file.write((char*)&len, sizeof(len));
    file.write(o.carNumber.c_str(), len);
    
    len = o.techPassport.size();
    file.write((char*)&len, sizeof(len));
    file.write(o.techPassport.c_str(), len);
    
    len = o.registration.size();
    file.write((char*)&len, sizeof(len));
    file.write(o.registration.c_str(), len);
}

// Функция для чтения одной структуры из файла
void readOwner(ifstream& file, Owner& o) {
    size_t len;
    char* buffer;
    
    file.read((char*)&len, sizeof(len));
    buffer = new char[len + 1];
    file.read(buffer, len);
    buffer[len] = '\0';
    o.fio = buffer;
    delete[] buffer;
    
    file.read((char*)&len, sizeof(len));
    buffer = new char[len + 1];
    file.read(buffer, len);
    buffer[len] = '\0';
    o.carNumber = buffer;
    delete[] buffer;
    
    file.read((char*)&len, sizeof(len));
    buffer = new char[len + 1];
    file.read(buffer, len);
    buffer[len] = '\0';
    o.techPassport = buffer;
    delete[] buffer;
    
    file.read((char*)&len, sizeof(len));
    buffer = new char[len + 1];
    file.read(buffer, len);
    buffer[len] = '\0';
    o.registration = buffer;
    delete[] buffer;
}

// 1. Создание файла с начальными данными
void createFile() {
    ofstream file("owners.dat", ios::binary);
    
    // Создаем 5 записей
    Owner owners[5] = {
        {"Иванов Иван Иванович", "A123BC", "123456789", "ГИБДД г. Москва"},
        {"Петров Петр Петрович", "B456DE", "987654321", "ГИБДД г. Санкт-Петербург"},
        {"Сидоров Сидор Сидорович", "C789FG", "456789123", "ГИБДД г. Казань"},
        {"Кузнецов Константин Константинович", "D345HI", "321654987", "ГИБДД г. Екатеринбург"},
        {"Смирнов Сергей Сергеевич", "E678JK", "789123456", "ГИБДД г. Новосибирск"}
    };
    
    // Записываем количество записей
    int count = 5;
    file.write((char*)&count, sizeof(count));
    
    // Записываем все записи
    for (int i = 0; i < count; i++) {
        writeOwner(file, owners[i]);
    }
    
    file.close();
    cout << "Файл создан! Добавлено 5 записей.\n";
}

// 2. Печать содержимого файла
void printFile() {
    ifstream file("owners.dat", ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!\n";
        return;
    }
    
    int count;
    file.read((char*)&count, sizeof(count));
    
    cout << "\n========================================\n";
    cout << "СОДЕРЖИМОЕ ФАЙЛА:\n";
    cout << "========================================\n";
    
    for (int i = 0; i < count; i++) {
        Owner o;
        readOwner(file, o);
        
        cout << "Запись №" << i + 1 << ":\n";
        cout << "  ФИО: " << o.fio << "\n";
        cout << "  Номер авто: " << o.carNumber << "\n";
        cout << "  Техпаспорт: " << o.techPassport << "\n";
        cout << "  Регистрация: " << o.registration << "\n";
        cout << "----------------------------------------\n";
    }
    
    file.close();
}

// 3. Удаление записи по номеру
void deleteByNumber(int delNum) {
    ifstream file("owners.dat", ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!\n";
        return;
    }
    
    // Читаем все записи в массив
    int count;
    file.read((char*)&count, sizeof(count));
    
    Owner* owners = new Owner[count];
    for (int i = 0; i < count; i++) {
        readOwner(file, owners[i]);
    }
    file.close();
    
    // Проверяем номер
    if (delNum < 1 || delNum > count) {
        cout << "Ошибка: Запись с номером " << delNum << " не найдена!\n";
        delete[] owners;
        return;
    }
    
    // Создаем новый массив без удаленной записи
    int newCount = count - 1;
    Owner* newOwners = new Owner[newCount];
    
    for (int i = 0, j = 0; i < count; i++) {
        if (i + 1 != delNum) {
            newOwners[j++] = owners[i];
        }
    }
    
    // Записываем в файл
    ofstream outFile("owners.dat", ios::binary);
    outFile.write((char*)&newCount, sizeof(newCount));
    for (int i = 0; i < newCount; i++) {
        writeOwner(outFile, newOwners[i]);
    }
    outFile.close();
    
    delete[] owners;
    delete[] newOwners;
    
    cout << "Запись №" << delNum << " успешно удалена!\n";
}

// 4. Добавление двух записей перед фамилией
void addBeforeSurname(string surname) {
    ifstream file("owners.dat", ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!\n";
        return;
    }
    
    // Читаем все записи
    int count;
    file.read((char*)&count, sizeof(count));
    
    Owner* owners = new Owner[count];
    for (int i = 0; i < count; i++) {
        readOwner(file, owners[i]);
    }
    file.close();
    
    // Ищем позицию для вставки
    int insertPos = -1;
    for (int i = 0; i < count; i++) {
        if (owners[i].fio.find(surname) != string::npos) {
            insertPos = i;
            break;
        }
    }
    
    if (insertPos == -1) {
        cout << "Ошибка: Фамилия \"" << surname << "\" не найдена!\n";
        delete[] owners;
        return;
    }
    
    // Вводим две новые записи
    Owner new1, new2;
    cout << "\n=== Ввод первой новой записи ===\n";
    cout << "ФИО: "; cin.ignore(); getline(cin, new1.fio);
    cout << "Номер авто: "; getline(cin, new1.carNumber);
    cout << "Техпаспорт: "; getline(cin, new1.techPassport);
    cout << "Регистрация: "; getline(cin, new1.registration);
    
    cout << "\n=== Ввод второй новой записи ===\n";
    cout << "ФИО: "; getline(cin, new2.fio);
    cout << "Номер авто: "; getline(cin, new2.carNumber);
    cout << "Техпаспорт: "; getline(cin, new2.techPassport);
    cout << "Регистрация: "; getline(cin, new2.registration);
    
    // Создаем новый массив с добавленными записями
    int newCount = count + 2;
    Owner* newOwners = new Owner[newCount];
    
    for (int i = 0, j = 0; i < count; i++) {
        if (i == insertPos) {
            newOwners[j++] = new1;
            newOwners[j++] = new2;
        }
        newOwners[j++] = owners[i];
    }
    
    // Записываем в файл
    ofstream outFile("owners.dat", ios::binary);
    outFile.write((char*)&newCount, sizeof(newCount));
    for (int i = 0; i < newCount; i++) {
        writeOwner(outFile, newOwners[i]);
    }
    outFile.close();
    
    delete[] owners;
    delete[] newOwners;
    
    cout << "\nДве записи добавлены перед фамилией \"" << surname << "\"!\n";
}

int main() {
    cout << "========================================\n";
    cout << "ЛАБОРАТОРНАЯ РАБОТА №8\n";
    cout << "Вариант 22: Владелец автомобиля\n";
    cout << "========================================\n";
    
    // 1. Создаем файл
    cout << "\n1. СОЗДАНИЕ ФАЙЛА\n";
    cout << "----------------------------------------\n";
    createFile();
    
    // 2. Смотрим файл
    cout << "\n2. ПРОСМОТР ФАЙЛА\n";
    cout << "----------------------------------------\n";
    printFile();
    
    // 3. Удаляем запись
    int num;
    cout << "\n3. УДАЛЕНИЕ ЗАПИСИ\n";
    cout << "----------------------------------------\n";
    cout << "Введите номер для удаления (1-5): ";
    cin >> num;
    deleteByNumber(num);
    
    // 4. Смотрим после удаления
    cout << "\n4. ПРОСМОТР ПОСЛЕ УДАЛЕНИЯ\n";
    cout << "----------------------------------------\n";
    printFile();
    
    // 5. Добавляем записи
    string surname;
    cout << "\n5. ДОБАВЛЕНИЕ ЗАПИСЕЙ\n";
    cout << "----------------------------------------\n";
    cout << "Введите фамилию: ";
    cin >> surname;
    addBeforeSurname(surname);
    
    // 6. Смотрим итоговый файл
    cout << "\n6. ИТОГОВЫЙ ПРОСМОТР\n";
    cout << "----------------------------------------\n";
    printFile();
    
    cout << "\n========================================\n";
    cout << "ПРОГРАММА ЗАВЕРШЕНА!\n";
    cout << "========================================\n";
    
    return 0;
}