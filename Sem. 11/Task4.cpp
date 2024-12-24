#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int** matrix = new int* [N];

	unsigned sum = 0;

	for (int i = 0; i < N; i++) {
			matrix[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			sum += matrix[i][j];
		}
	}
	cout << sum;
	for (int i = 0; i < N; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
 return 0;
}