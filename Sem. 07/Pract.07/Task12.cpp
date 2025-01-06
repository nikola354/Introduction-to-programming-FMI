#include <iostream>
using namespace std;

constexpr int MAX_ROWS = 100;
constexpr int COLS = 2;

void enterMatrix(int matrix[][COLS], int n);

void swapMatrixElements(int matrix[][COLS], int row, int col, int row1, int col1);

void sortMatrixByRows(int matrix[][COLS], int n);

void printMatrix(const int matrix[][COLS], int n);

int main() {
    int matrix[MAX_ROWS][COLS];
    int n;
    cin >> n;

    enterMatrix(matrix, n);

    sortMatrixByRows(matrix, n);

    printMatrix(matrix, n);
}

void enterMatrix(int matrix[][COLS], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < COLS; j++) {
            cin >> matrix[i][j];
        }
    }
}

void swapMatrixElements(int matrix[][COLS], int row, int col, int row1, int col1) {
    int temp = matrix[row][col];
    matrix[row][col] = matrix[row1][col1];
    matrix[row1][col1] = temp;
}

void sortMatrixByRows(int matrix[][COLS], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (matrix[j][0] < matrix[minIndex][0]) {
                minIndex = j;
            } else if ((matrix[j][0] == matrix[minIndex][0]) && matrix[j][1] < matrix[minIndex][1]) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            swapMatrixElements(matrix, i, 0, minIndex, 0);
            swapMatrixElements(matrix, i, 1, minIndex, 1);
        }
    }
}

void printMatrix(const int matrix[][COLS], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}
