
#include <iostream>
constexpr int SIZE = 2;

void inputMatrix(int matrix[][SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cin >> matrix[i][j];

        }
    }
}

void swap(int& a, int& b) {
    int temp = b;
    b = a;
    a = temp;
}

void sortMatrix(int matrix[][SIZE], int N) {
    for (int i = 0; i < N; i++) {
        
        int minIndex = i;
        for (int j = i+1; j < N; j++) {
            if (matrix[i][0] > matrix[j][0]) {
                minIndex = j;
            }
            else if (matrix[i][0] == matrix[j][0]) {
                if (matrix[i][1] > matrix[j][1]) {
                    minIndex = j;
                }
            }
        }
            if (minIndex != i) {
                swap(matrix[i][0], matrix[minIndex][0]);
                swap(matrix[i][1], matrix[minIndex][1]);
            }
        
    }
}

void printMatrix(const int matrix[][SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;

    }
}

int main()
{
    const int N = 6;
    int matrix[N][SIZE];
    inputMatrix(matrix, N);
    sortMatrix(matrix, N);
    printMatrix(matrix, N);


}

