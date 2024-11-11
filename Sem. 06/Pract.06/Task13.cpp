#include <iostream>;
void readArray(int* arr, int& size);
void printArray(const int* arr, int len);
bool contains(const int* arr, const int len, int searchedValue);
void unite(const int* arr1, const int size1, const int* arr2, const int size2, int* result, int& size);
void intersect(const int* arr1, const int size1, const int* arr2, const int size2, int* result, int& size);


constexpr int MAX_SIZE = 100;
int main()
{
	int arr1[MAX_SIZE];
	int arrSize1 = 0;
    int arr2[MAX_SIZE];
	int arrSize2 = 0;
	int united[MAX_SIZE];
	int unitedSize = 0;
    int intersected[MAX_SIZE];
	int intersectedSize = 0;
	readArray(arr1, arrSize1);
    readArray(arr2, arrSize2);
    unite(arr1, arrSize1, arr2, arrSize2, united, unitedSize);
    intersect(arr1, arrSize1, arr2, arrSize2, intersected, intersectedSize);

    std::cout << "Union: ";
	printArray(united, unitedSize);
	std::cout <<'\n' << "Intersection: ";
    printArray(intersected, intersectedSize);
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

bool contains(const int* arr, const int len, int searchedValue) {
	for (int i = 0; i < len; i++)
		if (arr[i] == searchedValue)
			return true;
	return false;
}

void unite(const int* arr1, const int size1, const int* arr2, const int size2, int* result, int& size) {
	for (int i = 0; i < size1; i++, size++)
		result[size] = arr1[i];

	for (int j = 0; j < size2; j++)
	{
		if (!contains(result, size, arr2[j])) {
			result[size] = arr2[j];
			size++;
		}
	}
}

void intersect(const int* arr1, const int size1, const int* arr2, const int size2, int* result, int& size) {
	// more efficient way will be to order the arrays but them they will not be constants
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++)
		{
			if ((arr1[i] == arr2[j]) && !contains(result, size, arr1[i])) {
				// EDGE CASE: if arr1 and arr2 contain repeating elements we do not want to add them to the result
				result[size] = arr1[i];
				size++;
			}
		}
	}
}
