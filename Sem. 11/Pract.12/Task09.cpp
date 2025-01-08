#include <iostream>
using namespace std;

int** readMatrix(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}
	return matrix;
}

bool doesExist(const int* const* edgesMatrix, int edgesCount, int n, int k) {
	if (!edgesMatrix) {
		return false;
	}

	for (int i = 0; i < edgesCount; i++) {
		if (edgesMatrix[i][0] == n && edgesMatrix[i][1] == k) {
			return true;
		}
	}
	return false;
}

int** matrixGraph(const int* const* edges, int maxNodeIndexFromEdges) {
	if (!edges) {
		return nullptr;
	}

	int matrixSize = maxNodeIndexFromEdges + 1;
	int** matrixGraph = new int* [matrixSize];

	for (int i = 0; i < matrixSize; i++) {
		matrixGraph[i] = new int[matrixSize];

		for (int j = 0; j < matrixSize; j++) {
			if (doesExist(edges, maxNodeIndexFromEdges, i, j) || doesExist(edges, maxNodeIndexFromEdges, j, i)) {
				matrixGraph[i][j] = 1;
			}
			else {
				matrixGraph[i][j] = 0;
			}
		}
	}

	return matrixGraph;
}

void printMatrix(const int* const* matrix, int rows, int cols) {
	if (!matrix) {
		return;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}

void freeMatrix(const int* const* matrix, int rows) {
	
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}


int main()
{
	int maxNodeIndexFromEdges;
	cin >> maxNodeIndexFromEdges;
	
	int** edges = readMatrix(maxNodeIndexFromEdges, 2);
	int** result = matrixGraph(edges, maxNodeIndexFromEdges);

	int matrixGraphSize = maxNodeIndexFromEdges + 1;
	printMatrix(result, matrixGraphSize, matrixGraphSize);

	freeMatrix(result, matrixGraphSize);
	freeMatrix(edges, maxNodeIndexFromEdges);
}