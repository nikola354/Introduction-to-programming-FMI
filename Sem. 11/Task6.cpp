#include <iostream>
using namespace std;

int** AllocateMatrix(unsigned rows, unsigned cols) {

	int** matrix = new int*[rows];
	for (unsigned i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}
	return matrix;
}

void ReadMatrix(int** matrix, unsigned rows, unsigned cols) {
	if (!matrix)return;

	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}
}

void PrintMatrix(int** result, unsigned rows, unsigned cols) {
	if (!result)return;

	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}

void FreeMatrix(int** matrix, unsigned rows) {
	if (!matrix)return;

	for (unsigned i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void MultiplyTwoMatrices (int** matr1, int** matr2, unsigned rows1, unsigned cols1, unsigned cols2) {
	if (!matr1 || !matr2)return;

	int** result = AllocateMatrix(rows1, cols2);

	for (unsigned i = 0; i < rows1; i++) {

		for (unsigned j = 0; j < cols2; j++) {

			result[i][j] = 0;

			for (unsigned k = 0; k < cols1; k++) {

				result[i][j] += matr1[i][k] * matr2[k][j];
			}
		}
	}
	PrintMatrix(result, rows1, cols2);

	FreeMatrix(result, rows1);
}

int main() {
	unsigned N, M, P, Q;
	
	cout << "Enter N: " << endl;
	cin >> N;
	
	do {
		cout << "Enter M and P: "<<endl;
		cin >> M >> P;
		if (M != P) cout << "Invalid input. Matrices with such size can not be multilied!"<<endl;
	}
		while (M != P);

	cout << "Enter Q: " << endl;
	cin >> Q;

	int** matrix1 = AllocateMatrix(N, M);
	int** matrix2 = AllocateMatrix(P, Q);

	cout << "Enter the first matrix: " << endl;
	ReadMatrix(matrix1, N, M);

	cout << "Enter the second matrix: " << endl;
	ReadMatrix(matrix2, P, Q);

	MultiplyTwoMatrices(matrix1, matrix2, N, M, Q);

	FreeMatrix(matrix1, N);
	FreeMatrix(matrix2, P);

	return 0;
}