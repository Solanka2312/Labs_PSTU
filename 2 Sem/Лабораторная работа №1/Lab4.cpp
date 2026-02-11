#include <iostream>
using namespace std;

int main() {
    const int ROWS = 3;
    const int COLS = 4;
    
    int matrix[ROWS][COLS];
    
    matrix[0][0] = 5;   // строка 0, столбец 0
    matrix[0][1] = 12;
    matrix[0][2] = 8;
    matrix[0][3] = 20;
    
    matrix[1][0] = 3;   // строка 1, столбец 0
    matrix[1][1] = 7;
    matrix[1][2] = 10;
    matrix[1][3] = 15;
    
    matrix[2][0] = 9;   // строка 2, столбец 0
    matrix[2][1] = 4;
    matrix[2][2] = 6;
    matrix[2][3] = 18;
    
    cout << "Наш массив:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << "\t";  // \t - это табуляция
        }
        cout << endl;
    }
    cout << endl;

    cout << "Считаем среднее арифметическое первого столбца" << endl;
    
    int sum = 0;
    
    // Проходим по всем строкам первого столбца
    for (int i = 0; i < ROWS; i++) {
        sum = sum + matrix[i][0];  // добавляем каждый элемент первого столбца
        cout << "Беру элемент [" << i << "][0] = " << matrix[i][0] << endl;
    }
    
    // Считаем среднее
    float average = (float)sum / ROWS;
    
    cout << "Сумма первого столбца: " << sum << endl;
    cout << "Среднее арифметическое: " << sum << " / " << ROWS << " = " << average << endl << endl;
    
    // Cчитаем, сколько элементов больше среднего предыдущего
    cout << "Считаем для каждого столбца элементы, большие среднего предыдущего" << endl;
    
    // Будем хранить среднее предыдущего столбца
    float previous_average = average;
    
    for (int col = 1; col < COLS; col++) {
        cout << endl << "Работаем со столбцом " << col << endl;
        cout << "Сравниваем с средним предыдущего столбца: " << previous_average << endl;
        
        int count = 0;  // счетчик элементов, которые больше среднего предыдущего столбца
        
        // Проходим по всем строкам текущего столбца
        for (int row = 0; row < ROWS; row++) {
            cout << "  Элемент [" << row << "][" << col << "] = " << matrix[row][col];
            
            if (matrix[row][col] > previous_average) {
                count++;
                cout << " Больше!" << endl;
            } else {
                cout << " Меньше" << endl;
            }
        }
        
        cout << "В столбце " << col << " элементов больше " << previous_average << ": " << count << endl;
        
        // Теперь для следующего столбца нужно новое среднее текущего столбца
        // Считаем среднее текущего столбца
        int col_sum = 0;
        for (int row = 0; row < ROWS; row++) {
            col_sum = col_sum + matrix[row][col];
        }
        previous_average = (float)col_sum / ROWS;
        cout << "Среднее арифметическое столбца " << col << ": " << previous_average << endl;
    }
    
    return 0;
}