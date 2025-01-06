#include <iostream>
using namespace std;

void readMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}
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

int** matrixGraph(const int* const* edges, int edgesCount, int size) {
	if (!edges) {
		return nullptr;
	}

	int** matrixGraph = new int* [size];

	for (int i = 0; i < size; i++) {
		matrixGraph[i] = new int[size];

		for (int j = 0; j < size; j++) {
			if (doesExist(edges, edgesCount, i, j) || doesExist(edges, edgesCount, j, i)) {
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
int main()
{
	int edgesCount;
	cin >> edgesCount;
	int size;
	cin >> size;

	int** edges = new int* [edgesCount];
	for (int i = 0; i < edgesCount; i++) {
		edges[i] = new int[2];
	}
	readMatrix(edges, edgesCount, 2);

	int** result = matrixGraph(edges, edgesCount, size);

	printMatrix(result, size, size);

	for (int i = 0; i < size; i++) {
		delete[] result[i];
	}

	delete[] result;

	for (int i = 0; i < edgesCount; i++) {
		delete[] edges[i];
	}
	delete[] edges;
}