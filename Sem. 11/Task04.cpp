#include <iostream>
using namespace std;

int sumAboveMainDiagonal(const int *const *matrix, int N) {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			sum += matrix[i][j];
		}
	}

	return sum;
}

int main() {
	int N;
	cin >> N;
	int** matrix = new int* [N];

	for (int i = 0; i < N; i++) {
		matrix[i] = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}
	
	
	cout << sumAboveMainDiagonal(matrix, N);
	
	for (int i = 0; i < N; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
 	return 0;
}
