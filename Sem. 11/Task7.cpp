#include <iostream>
using namespace std;

//
void PrintResult(int* arr, unsigned size) {
	if (!arr)return;

	for (unsigned i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
void RearrangeArray(int* arr, unsigned size, int element) {
	if (!arr) return;
	int* result = new int[size];
	unsigned resultIndex = 0;

	for (unsigned i = 0; i < size; i++) {
		if (arr[i] < element){
			result[resultIndex++] = arr[i];
		}
	}

	for (unsigned i = 0; i < size; i++) {
		if (arr[i] == element) {
			result[resultIndex++] = arr[i];
		}
	}

	for (unsigned i = 0; i < size; i++) {
			if (arr[i] > element && resultIndex < size) {
				result[resultIndex++] = arr[i];
			}
	}
	PrintResult(result, size);
	delete[] result;
}
int main() {
	const unsigned size = 9;
	int arr[size];

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	int element;
	bool isElement = false;
	do {
		cin >> element;
		
		for (unsigned i = 0; i < size; i++) {
			if (element == arr[i]) {
				isElement = true;
				break;
			}
		}
		if(!isElement) cout << "Invalid input! Enter element: ";
	} 
	while (!isElement);
	RearrangeArray(arr, size, element);

	cout << endl;
}