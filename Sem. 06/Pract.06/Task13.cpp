#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 100;

bool checkIfResultHasElement(const int[], int, int);

void unionArrays(const int[], int, const int[], int, int[], int&);

void intersectionArrays(const int[], int, const int[], int, int[], int&);

void printArray(const int[], int);

int main() {
	int arr1[5] = { 2, 4, 1, 7, 8 };
	int arr2[4] = { 1, 2, 3, 5 };

	int unionArray[MAX_SIZE];
	int unionArrLength = 0;

	int intersectionArray[MAX_SIZE];
	int interArrLength = 0;

	unionArrays(arr1, 5, arr2, 4, unionArray, unionArrLength);
	cout << "Union: ";
	printArray(unionArray, unionArrLength);

	intersectionArrays(arr1, 5, arr2, 4, intersectionArray, interArrLength);
	cout << "Intersection: ";
	printArray(intersectionArray, interArrLength);

	return 0;
}

bool checkIfResultHasElement(const int result[], int size, int element) {
	for (int j = 0; j < size; j++) {
		if (element == result[j]) {
			return true;
		}
	}

	return false;
}

void unionArrays(const int arr1[], int size1, const int arr2[], int size2, int result[], int& size3) {
	for (int i = 0; i < size1; i++) {
		bool isPresent = checkIfResultHasElement(result, size3, arr1[i]);

		if (!isPresent) {
			result[size3++] = arr1[i];
		}
	}

	for (int i = 0; i < size2; i++) {
		bool isPresent = checkIfResultHasElement(result, size3, arr2[i]);

		if (!isPresent) {
			result[size3++] = arr2[i];
		}
	}
}

void intersectionArrays(const int arr1[], int size1, const int arr2[], int size2, int result[], int& size3) {
	for (int i = 0; i < size1; i++) {
		if (checkIfResultHasElement(arr2, size2, arr1[i]) && !checkIfResultHasElement(result, size3, arr1[i]))
		{
			result[size3++] = arr1[i];
		}
	}
}

void printArray(const int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}