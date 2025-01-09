#include <iostream>

using namespace std;

int binaryToDecimal(const bool* arr, unsigned length) {
    int decimal = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i]) {
            decimal += 1 << (length - 1 - i); //power of 2
        }
    }

    return decimal;
}

int* binaryToDecimalMatrix(const bool*const* binary, unsigned rows, unsigned cols) {
    int* result = new int[rows];

    for (int i = 0; i < rows; i++) {
        result[i] = binaryToDecimal(binary[i], cols);
    }

    return result;
}

bool** readBoolMatrix(unsigned rows, unsigned cols) {
    bool** matrix = new bool*[rows];

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new bool[cols];
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

void printArray(const int* arr, unsigned length) {
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    bool **binary = readBoolMatrix(rows, cols);

    int* decimals = binaryToDecimalMatrix(binary, rows, cols);
    printArray(decimals, rows);

    //free memory:

    for (int i = 0; i < rows; ++i) {
        delete[] binary[i];
    }
    delete[] binary;
    delete[] decimals;

    return 0;
}
