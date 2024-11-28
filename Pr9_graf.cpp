#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

// Подпрограмма для ввода элементов массива
void inputMatrix(int rows, int cols, int** matrix) {
    cout << "Введите элементы матрицы (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Подпрограмма для вычисления суммы диагональных элементов
int sumDiagonalElements(int size, int** matrix) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

// Подпрограмма для вывода матрицы
void printMatrix(int rows, int cols, int** matrix) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Подпрограмма для задачи 2
void processMatrix(int rows, int cols, int** matrix) {
    for (int i = 0; i < rows; ++i) {
        int maxIdx = 0, minIdx = 0;
        // Находим индексы минимального и максимального элементов в строке
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] > matrix[i][maxIdx]) maxIdx = j;
            if (matrix[i][j] < matrix[i][minIdx]) minIdx = j;
        }
        // Меняем максимальный элемент с первым
        int temp = matrix[i][0];
        matrix[i][0] = matrix[i][maxIdx];
        matrix[i][maxIdx] = temp;

        // Меняем минимальный элемент с последним
        temp = matrix[i][cols - 1];
        matrix[i][cols - 1] = matrix[i][minIdx];
        matrix[i][minIdx] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    do {
        cout << "Выберите программу:\n";
        cout << "1. Сумма диагональных элементов массива\n";
        cout << "2. Замена максимального и минимального элементов в строках матрицы\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int size;
            cout << "Введите размер квадратного массива: ";
            cin >> size;

            // Динамическое выделение памяти для матрицы
            int** matrix = new int* [size];
            for (int i = 0; i < size; ++i) {
                matrix[i] = new int[size];
            }

            inputMatrix(size, size, matrix);
            cout << "Введённый массив:\n";
            printMatrix(size, size, matrix);

            int sum = sumDiagonalElements(size, matrix);
            cout << "Сумма диагональных элементов: " << sum << endl;

            // Освобождение памяти
            for (int i = 0; i < size; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
            break;
        }
        case 2: {
            int rows, cols;
            cout << "Введите количество строк и столбцов матрицы (через пробел): ";
            cin >> rows >> cols;

            // Динамическое выделение памяти для матрицы
            int** matrix = new int* [rows];
            for (int i = 0; i < rows; ++i) {
                matrix[i] = new int[cols];
            }

            inputMatrix(rows, cols, matrix);
            cout << "Исходная матрица:\n";
            printMatrix(rows, cols, matrix);

            processMatrix(rows, cols, matrix);
            cout << "Обработанная матрица:\n";
            printMatrix(rows, cols, matrix);

            // Освобождение памяти
            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
            break;
        }
        case 0:
            cout << "Выход из программы. До свидания!\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
