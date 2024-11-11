#include <iostream>
void readArray(int* arr, int& size);
void printArray(const int* arr, int len);
void mergeAndSort(const int* arr1, const int size1, const int* arr2, const int size2, int* result, int& resultSize);

constexpr int MAX_SIZE = 100;
int main()
{
	int arr1[MAX_SIZE];
    int arr2[MAX_SIZE];
	int result[MAX_SIZE];
	int arrSize1 = 0;
    int arrSize2 = 0;
	int resultSize = 0;
	readArray(arr1, arrSize1);
    readArray(arr2, arrSize2);
    mergeAndSort(arr1, arrSize1, arr2, arrSize2, result, resultSize);
    printArray(result, resultSize);
}

void readArray(int* arr, int& size) {
	while (size < MAX_SIZE) {
		char ch;
		std::cin.get(ch);
		if (ch == '[' || ch == ' ') {
			int num;
			std::cin >> num;
			arr[size] = num;
			size++;
		}
		else if (ch == ',') continue;
		else if (ch == ']')	return;
	}
}

void printArray(const int* arr, int len) {
	for (int i = 0; i < len; i++)
		std::cout << arr[i] << " ";
}

void mergeAndSort(const int* arr1, const int size1, const int* arr2, const int size2, int* result, int& resultSize) {
	int i = 0, j = 0;
	while (i < size1 && j < size2) {

		if (arr1[i] < arr2[j])
			result[resultSize++] = arr1[i++];
		else
			result[resultSize++] = arr2[j++];
	}

	while (i < size1)
		result[resultSize++] = arr1[i++];

	while (j < size2)
		result[resultSize++] = arr2[j++];
}
