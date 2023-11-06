#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

const int numRows = 7;
const int numCols = 6;

// �������� ������� ����������� ������� � �������� �������
void initializeMatrix(int matrix[numRows][numCols], int lowerBound, int upperBound) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = rand() % (upperBound - lowerBound + 1) + lowerBound;
        }
    }
}

// �������� ������� �� �����
void displayMatrix(const int matrix[numRows][numCols]) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// ������ � ������� �� ������, ���� ��'�����, �� ���
void replaceOddNonNegative(int matrix[numRows][numCols]) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (matrix[i][j] % 2 != 0 && matrix[i][j] >= 0) {
                matrix[i][j] = 0;
            }
        }
    }
}

// ����� ������� ����� ���������� ������ �������������
void sortMatrix(int matrix[numRows][numCols]) {
    vector<pair<vector<int>, int>> rowsWithIndices;
    for (int i = 0; i < numRows; i++) {
        vector<int> row;
        for (int j = 0; j < numCols; j++) {
            row.push_back(matrix[i][j]);
        }
        rowsWithIndices.push_back({ row, i });
    }

    // ���������� ����� �� ������ � ������ �����������
    sort(rowsWithIndices.begin(), rowsWithIndices.end(), [](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b) {
        if (a.first[0] != b.first[0]) {
            return a.first[0] < b.first[0];
        }
        else if (a.first[1] != b.first[1]) {
            return a.first[1] < b.first[1];
        }
        else {
            return a.first[3] > b.first[3];
        }
        });

    // ���������� ������� � ������������� �������
    int temp[numRows][numCols];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            temp[i][j] = matrix[rowsWithIndices[i].second][j];
        }
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

// ������� �������
int main() {
    int matrix[numRows][numCols];
    const int lowerBound = -12;
    const int upperBound = 23;

    initializeMatrix(matrix, lowerBound, upperBound);

    cout << "��������� �������:" << endl;
    displayMatrix(matrix);

    replaceOddNonNegative(matrix);

    cout << "������������ �������:" << endl;
    displayMatrix(matrix);

    sortMatrix(matrix);

    cout << "³���������� �������:" << endl;
    displayMatrix(matrix);

    return 0;
}
