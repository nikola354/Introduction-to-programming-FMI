#include <iostream>
constexpr int row = 3;
constexpr int cols = 3;

void inputMatrix(int matrix[row][cols]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> matrix[i][j];
		}
	}
}


void sum(const int matrix1[row][cols], const int matrix2[row][cols], int result[row][cols]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

}

void multiplication(const int matrix1[row][cols], const int matrix2[row][cols], int result[row][cols]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			for (int k = 0; k < cols; k++) {
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
}


void printMatrix(const int matrix[row][cols]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

}
int main()
{
	int matrix1[row][cols];
	int matrix2[row][cols];
	int sumMatrix[row][cols];
	inputMatrix(matrix1); inputMatrix(matrix2);

	//sum(sumMatrix, matrix2, sumMatrix);

	int multiplicationMatrix[row][cols] = {0};
	multiplication(matrix1, matrix2, multiplicationMatrix);
    printMatrix(multiplicationMatrix);


}