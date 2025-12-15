#include <iostream>
#include <cmath> // для функции sqrt()

using namespace std;

int main() {
    int a, b, c;
    
    // Шаг 1: Ввод коэффициентов
    cout << "Введите коэффициент a: ";
    cin >> a;
    cout << "Введите коэффициент b: ";
    cin >> b;
    cout << "Введите коэффициент c: ";
    cin >> c;
    
    // Шаг 2: Проверка, квадратное ли это уравнение
    if (a == 0) {
        cout << "Это не квадратное уравнение (a = 0)!" << endl;
        return 0;
    }
    
    // Шаг 3: Вычисление дискриминанта
    int D = b * b - 4 * a * c;
    
    // Шаг 4: Анализ дискриминанта
    if (D > 0) {
        // Два различных корня
        int x1 = (-b + sqrt(D)) / (2 * a);
        int x2 = (-b - sqrt(D)) / (2 * a);
        cout << "Два корня:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (D == 0) {
        // Один корень
        int x = -b / (2 * a);
        cout << "Один корень:" << endl;
        cout << "x = " << x << endl;
    }
    else {
        // Нет действительных корней
        cout << "Действительных корней нет (D < 0)" << endl;
    }
    
    return 0;
}