#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

// Структура "Владелец автомобиля"
struct CarOwner {
    char fullName[100];     // фамилия, имя, отчество
    char carNumber[20];     // номер автомобиля
    char techPassport[20];  // номер техпаспорта
    char registrationOffice[100]; // отделение регистрации ГАИ
};

// Функция формирования файла (создание с нуля)
void createFile(const char* filename) {
    FILE* f = fopen(filename, "wb");
    if (!f) {
        cerr << "Ошибка создания файла!" << endl;
        return;
    }

    CarOwner owner;
    char choice;

    do {
        cout << "\nВведите данные владельца:\n";
        cout << "ФИО: ";
        cin.ignore();
        cin.getline(owner.fullName, 100);
        cout << "Номер автомобиля: ";
        cin.getline(owner.carNumber, 20);
        cout << "Номер техпаспорта: ";
        cin.getline(owner.techPassport, 20);
        cout << "Отделение ГАИ: ";
        cin.getline(owner.registrationOffice, 100);

        fwrite(&owner, sizeof(CarOwner), 1, f);
        cout << "Добавить еще? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    fclose(f);
    cout << "Файл успешно создан!\n";
}

// Функция печати всего файла
void printFile(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return;
    }

    CarOwner owner;
    int count = 1;
    while (fread(&owner, sizeof(CarOwner), 1, f) == 1) {
        cout << "\nЗапись #" << count++ << endl;
        cout << "  ФИО: " << owner.fullName << endl;
        cout << "  Номер авто: " << owner.carNumber << endl;
        cout << "  Техпаспорт: " << owner.techPassport << endl;
        cout << "  Отделение ГАИ: " << owner.registrationOffice << endl;
    }
    fclose(f);
}

// Функция удаления элемента с заданным номером
void deleteByNumber(const char* filename, int numberToDelete) {
    if (numberToDelete < 1) {
        cerr << "Номер должен быть >= 1!" << endl;
        return;
    }

    FILE* f = fopen(filename, "rb");
    if (!f) {
        cerr << "Ошибка открытия исходного файла!" << endl;
        return;
    }

    FILE* temp = fopen("temp.dat", "wb");
    if (!temp) {
        cerr << "Ошибка создания временного файла!" << endl;
        fclose(f);
        return;
    }

    CarOwner owner;
    int currentIndex = 1;
    bool deleted = false;

    while (fread(&owner, sizeof(CarOwner), 1, f) == 1) {
        if (currentIndex != numberToDelete) {
            fwrite(&owner, sizeof(CarOwner), 1, temp);
        } else {
            deleted = true;
            cout << "Удалена запись #" << currentIndex << ": " << owner.fullName << endl;
        }
        currentIndex++;
    }

    fclose(f);
    fclose(temp);

    if (!deleted) {
        cout << "Запись с номером " << numberToDelete << " не найдена!\n";
        remove("temp.dat");
        return;
    }

    remove(filename);
    rename("temp.dat", filename);
    cout << "Удаление выполнено успешно!\n";
}

// Функция добавления 2 элементов перед элементом с заданной фамилией
void addBeforeSurname(const char* filename, const char* targetSurname) {
    FILE* f = fopen(filename, "rb");
    if (!f) {
        cerr << "Ошибка открытия исходного файла!" << endl;
        return;
    }

    FILE* temp = fopen("temp.dat", "wb");
    if (!temp) {
        cerr << "Ошибка создания временного файла!" << endl;
        fclose(f);
        return;
    }

    CarOwner owner;
    bool found = false;
    CarOwner newOwners[2];

    // Ввод данных для двух новых владельцев
    cout << "\nВведите данные для ДВУХ новых владельцев:\n";
    for (int i = 0; i < 2; i++) {
        cout << "\n--- Новый владелец " << i + 1 << " ---\n";
        cout << "ФИО: ";
        cin.ignore();
        cin.getline(newOwners[i].fullName, 100);
        cout << "Номер автомобиля: ";
        cin.getline(newOwners[i].carNumber, 20);
        cout << "Номер техпаспорта: ";
        cin.getline(newOwners[i].techPassport, 20);
        cout << "Отделение ГАИ: ";
        cin.getline(newOwners[i].registrationOffice, 100);
    }

    // Копируем записи, вставляя новые перед нужной фамилией
    while (fread(&owner, sizeof(CarOwner), 1, f) == 1) {
        // Проверяем, начинается ли ФИО с искомой фамилии
        // (предполагаем, что фамилия - первое слово до пробела)
        char surname[100];
        strcpy(surname, owner.fullName);
        char* space = strchr(surname, ' ');
        if (space) *space = '\0';

        if (!found && strcmp(surname, targetSurname) == 0) {
            found = true;
            cout << "Найдена запись с фамилией \"" << targetSurname << "\". Добавляем перед ней 2 записи.\n";
            // Записываем два новых элемента
            for (int i = 0; i < 2; i++) {
                fwrite(&newOwners[i], sizeof(CarOwner), 1, temp);
            }
        }
        // Записываем текущий элемент
        fwrite(&owner, sizeof(CarOwner), 1, temp);
    }

    fclose(f);
    fclose(temp);

    if (!found) {
        cout << "Запись с фамилией \"" << targetSurname << "\" не найдена!\n";
        remove("temp.dat");
        return;
    }

    remove(filename);
    rename("temp.dat", filename);
    cout << "Добавление выполнено успешно!\n";
}

// Главное меню
void menu() {
    cout << "\n1. Создать файл\n";
    cout << "2. Показать файл\n";
    cout << "3. Удалить запись по номеру\n";
    cout << "4. Добавить 2 записи перед фамилией\n";
    cout << "5. Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    const char* filename = "owners.dat";
    int choice, num;
    char surname[100];

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                printFile(filename);
                break;
            case 3:
                cout << "Введите номер записи для удаления: ";
                cin >> num;
                deleteByNumber(filename, num);
                break;
            case 4:
                cout << "Введите фамилию (перед которой добавить 2 записи): ";
                cin >> surname;
                addBeforeSurname(filename, surname);
                break;
            case 5:
                cout << "Программа завершена.\n";
                break;
            default:
                cout << "Неверный выбор!\n";
        }
    } while (choice != 5);

    return 0;
}