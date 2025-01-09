#include <iostream>
using namespace std;

void enterMatrix(int** matrix, int n, int m);

int getRowSum(const int* const* matrix, int row, int cols);

void removeOddRows(int** matrix, int& n, int m);

void printMatrix(const int* const* matrix, int n, int m);

int main() {
    int n, m;
    cin >> n >> m;

    int** matrix = new int* [n];
    enterMatrix(matrix, n, m);

    removeOddRows(matrix, n, m);

    printMatrix(matrix, n, m);

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void enterMatrix(int** matrix, int n, int m) {
    if (!matrix) {
        return;
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = new int [m];

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
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

void removeOddRows(int** matrix, int& n, int m) {
    if (!matrix) {
        return;
    }

    for (int i = 0; i < n;) {
        int sum = getRowSum(matrix, i, m);

        if  (sum % 2 != 0) {
            int* temp = matrix[i];
            matrix[i] = matrix[n - 1];
            matrix[n - 1] = temp;

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
