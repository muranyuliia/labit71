#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

const int numRows = 7;
const int numCols = 6;

// Ініціалізує матрицю випадковими числами в заданому діапазоні
void initializeMatrix(int matrix[numRows][numCols], int lowerBound, int upperBound) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = rand() % (upperBound - lowerBound + 1) + lowerBound;
        }
    }
}

// Виводить матрицю на екран
void displayMatrix(const int matrix[numRows][numCols]) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Замінює в матриці всі непарні, окрім від'ємних, на нулі
void replaceOddNonNegative(int matrix[numRows][numCols]) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (matrix[i][j] % 2 != 0 && matrix[i][j] >= 0) {
                matrix[i][j] = 0;
            }
        }
    }
}

// Головна функція
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int matrix[numRows][numCols];
    const int lowerBound = -12;
    const int upperBound = 23;

    initializeMatrix(matrix, lowerBound, upperBound);

    cout << "Початкова матриця:" << endl;
    displayMatrix(matrix);

    replaceOddNonNegative(matrix);

    cout << "Модифікована матриця:" << endl;
    displayMatrix(matrix);

    return 0;
}
