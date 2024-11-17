#include <iostream>
#include <climits>
constexpr int M = 4;
constexpr int N = 6;
constexpr int P = 2;
constexpr int Q = 3;

void inputMatrix(int matrix[M][N]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

int sumMatrix(const int matrix[M][N], int left, int right, int bottom, int top) {
	int sum = 0;
	for (int i = top; i < bottom; i++) {
		for (int j = left; j < right; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}


int subMatrixLargestSum(const int matrix[M][N]) {
	int maxSum = INT_MIN;
	for (int i = 0; i <=(M - P); i++) {
		for (int j = 0; j <=( N - Q); j++) {
			int leftIndex = j; int rightIndex = j + Q;
			int topIndex = i; int bottomIndex = i + P;

			if (maxSum < sumMatrix(matrix, leftIndex, rightIndex, bottomIndex, topIndex)) {
				maxSum = sumMatrix(matrix, leftIndex, rightIndex, bottomIndex, topIndex);
			}
		}
	}
	return maxSum;

}

int main()
{

	int matrix[M][N];
	inputMatrix(matrix);

	std::cout << subMatrixLargestSum(matrix);
}

