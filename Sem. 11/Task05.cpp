#include <iostream>
using namespace std;

void printMatrix(const int* const* temp, unsigned rows, unsigned cols) {
	if (!temp)return;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}
void transpose(const int* const* matr, unsigned N, unsigned M) {
	if (!matr)return;
	int**temp = new int*[M];

	for (int i = 0; i < M; i++) {
		temp[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[j][i] = matr[i][j];
		}
	}
	printMatrix(temp, M, N);

	for (int i = 0; i < M; i++) {
		delete[] temp[i];
	}
	delete[] temp;
}

int main() {
	unsigned N, M;
	cin >> N >> M;
	
	int** matrix = new int* [N];

	for (int i = 0; i < N; i++) {
		matrix[i] = new int[M];
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];
		}
	}
	
	transpose(matrix, N, M);
	for (int i = 0; i < N; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
