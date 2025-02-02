#include <iostream>
using namespace std;

int** createMatrix(int rows, int cols);

int getRowSum(const int* const* matrix, int row, int cols);

void rowsSwap(int** matrix, int from, int to);

void removeOddRows(int** matrix, int& n, int m);

void printMatrix(const int* const* matrix, int n, int m);

int main() {
    int n, m;
    cin >> n >> m;

    int** matrix = createMatrix(n, m);

    removeOddRows(matrix, n, m);

    printMatrix(matrix, n, m);

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int** createMatrix(int rows, int cols) {
    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int [cols];

        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

int getRowSum(const int* const* matrix, int row, int cols) {
    if (!matrix) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < cols; i++) {
        sum += matrix[row][i];
    }

    return sum;
}

void rowsSwap(int** matrix, int from, int to) {
    if (!matrix) {
        return;
    }

    int* temp = matrix[from];
    matrix[from] = matrix[to];
    matrix[to] = temp;
}

void removeOddRows(int** matrix, int& n, int m) {
    if (!matrix) {
        return;
    }

    for (int i = 0; i < n;) {
        int sum = getRowSum(matrix, i, m);

        if  (sum % 2 != 0) {
            rowsSwap(matrix, i, n - 1);
            n--;
        } else {
            i++;
        }
    }
}

void printMatrix(const int* const* matrix, int n, int m) {
    if (!matrix) {
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
