#include <iostream>
using namespace std;

constexpr int MAX_ROWS = 100;
constexpr int MAX_COLS = 100;

void enterMatrix(int matrix[][MAX_COLS], int m, int n);

int getSubmatrixSum(const int matrix[][MAX_COLS], int startRow, int startCol, int endRow, int endCol);

int maxSubmatrixSum(const int matrix[][MAX_COLS], int m, int n, int p, int q);

int main() {
    int m, n, p, q;
    cin >> m >> n >> p >> q;

    int matrix[MAX_ROWS][MAX_COLS];
    enterMatrix(matrix, m, n);

    cout << maxSubmatrixSum(matrix, m, n, p, q) << endl; 
}

void enterMatrix(int matrix[][MAX_COLS], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

int getSubmatrixSum(const int matrix[][MAX_COLS], int startRow, int startCol, int endRow, int endCol) {
    int sum = 0;

    for (int i = startRow; i < endRow; i++) {
        for (int j = startCol; j < endCol; j++) {
            sum += matrix[i][j];
        }
    }

    return sum;
}

int maxSubmatrixSum(const int matrix[][MAX_COLS], int m, int n, int p, int q) {
    int rows = m - p + 1;
    int cols = n - q + 1;
    
    int maxSum = INT_MIN;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = getSubmatrixSum(matrix, i, j, i + p, j + q);

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }

    return maxSum;
}
