#include <iostream>
using namespace std;

constexpr int MAX_LENGTH_STR = 10000;
constexpr int MAX_SIZE_MATR = 100;
constexpr int MAX_SYMBOLS_IN_WORD = 1024;

void stringToMatrix(const char* str, char matrix[MAX_SIZE_MATR][MAX_SYMBOLS_IN_WORD], int& row) {
    if (!str)
        return;
    int ind = 0;

    while (*str) {
        if (*str == ' ' && *(str - 1) != ' ') {
            row++;
            ind = 0;
        }
        else {
            matrix[row][ind++] = *str;
        }
       
        str++;
    }

    row++;
}

void printMatrix(const char matrix[MAX_SIZE_MATR][MAX_SYMBOLS_IN_WORD], int rows) {
    for (int i = 0; i < rows; i++) {
        int ind = 0;
        cout << "[\"";
        while (matrix[i][ind] != 0) {
            cout << matrix[i][ind++];
        }
        cout <<"\"]" << endl;
    }
}

int main()
{
    char str[MAX_LENGTH_STR];
    cin.getline(str, MAX_LENGTH_STR);
    char matrix[MAX_SIZE_MATR][MAX_SYMBOLS_IN_WORD] = { 0 };
    int row = 0;
    stringToMatrix(str, matrix, row);
    printMatrix(matrix, row);
}