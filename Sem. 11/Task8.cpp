#include <iostream>
using namespace std;

void printSubset(const int* arr, unsigned length, unsigned mask) {
	if (!arr)return;

	unsigned subsetSize = 0;
	for (unsigned i = 0; i < length; i++) {
		if (mask & (1<<i)) {
			subsetSize++;
		}
	}
	int* subset = new int[subsetSize];

	unsigned subsetIndex = 0;
	for (unsigned i = 0; i < length; i++) {
		if (mask & (1<<i) && subsetIndex < length) {
			subset[subsetIndex++] = arr[i];
		}
	}
	
	cout << "[ ";
	for (unsigned i = 0; i < subsetSize; i++) {
		
			cout << subset[i] << " ";
	}
	cout << "]" << endl;

	delete[] subset;
}

void printSubsets(const int* arr, unsigned length) {
	
	unsigned subsetsCount = 1 << length;
	
	for (unsigned i = 1; i < subsetsCount; i++) {
		printSubset(arr, length, i);
	}
}

int main() {
	const unsigned LENGTH = 5;
	int arr[LENGTH] = { 1, 2, 3, 4, 5 };

	printSubsets(arr, LENGTH);
}

