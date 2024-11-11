#include <iostream>;
void readArray(int* arr, int& size);

int getLongestSequenceLength(const int* arr, int size);

constexpr int MAX_SIZE = 100;
int main()
{
	int arr1[MAX_SIZE];
	int arrSize1 = 0;
	readArray(arr1, arrSize1);
	std::cout << getLongestSequenceLength(arr1, arrSize1);
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

int getLongestSequenceLength(const int* arr, int size) {
	int maxLength = 1;
	int currentLength = 1;

	for (int i = 1; i < size; i++) {

		if (arr[i] == arr[i - 1])
			currentLength++;
		else {
			if (currentLength > maxLength)
				maxLength = currentLength;

			currentLength = 1;
		}
	}

	if (currentLength > maxLength)
		maxLength = currentLength;

	return maxLength;
}
