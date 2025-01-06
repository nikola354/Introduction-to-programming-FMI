#include <iostream>
using namespace std;

int** allocateMatrix(unsigned rows, unsigned cols) {
	int** matrix = new int*[rows];
	for (unsigned i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}
	return matrix;
}

void readMatrix(int** matrix, unsigned rows, unsigned cols) {
	if (!matrix)return;

	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}
}

void printMatrix(const int *const *result, unsigned rows, unsigned cols) {
	if (!result)return;

	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}

void freeMatrix(int** matrix, unsigned rows) {
	if (!matrix)return;

	for (unsigned i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int ** multiplyTwoMatrices (const int *const * matr1, const int *const * matr2, unsigned rows1, unsigned cols1, unsigned cols2) {
	if (!matr1 || !matr2)return;

	int** result = allocateMatrix(rows1, cols2);

	for (unsigned i = 0; i < rows1; i++) {
		for (unsigned j = 0; j < cols2; j++) {
			result[i][j] = 0;

			for (unsigned k = 0; k < cols1; k++) {

				result[i][j] += matr1[i][k] * matr2[k][j];
			}
		}
	}

	return result;
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

	int** matrix1 = allocateMatrix(N, M);
	int** matrix2 = allocateMatrix(P, Q);

	cout << "Enter the first matrix: " << endl;
	readMatrix(matrix1, N, M);

	cout << "Enter the second matrix: " << endl;
	readMatrix(matrix2, P, Q);

	int ** result = multiplyTwoMatrices(matrix1, matrix2, N, M, Q);
	printMatrix(result, N, Q);
	
	freeMatrix(result, N);
	freeMatrix(matrix1, N);
	freeMatrix(matrix2, P);

	return 0;
}
