#include <climits>
#include <iostream>

constexpr size_t SIZE = 6;
constexpr size_t CLOCK_SIZE = 3;

void readMatrix(int matrix[][SIZE]) {
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void findSandClocks(const int matrix[][SIZE], size_t &centerX, size_t &centerY, int &maxSum) {
    for (int i = 1; i < SIZE - 1; ++i) {
        for (int j = 1; j < SIZE - 1; ++j) {
            int directions[] = {-1, 0, 1};

            int sum = matrix[i][j];
            for (int d : directions) {
                sum += matrix[i - 1][j + d];
                sum += matrix[i + 1][j + d];
            }

            if (sum >= maxSum) {
                centerX = j;
                centerY = i;

                maxSum = sum;
            }
        }
    }
}

void sandClocks() {
    int matrix[SIZE][SIZE];
    readMatrix(matrix);

    size_t centerX = 0, centerY = 0;
    int maxSum = INT_MIN;

    findSandClocks(matrix, centerX, centerY, maxSum);

    std::cout << "Row: " << centerY << std::endl;
    std::cout << "Column: " << centerX << std::endl;
    std::cout << "Sum: " << maxSum << std::endl;
}

int main() {
    sandClocks();

    return 0;
}
