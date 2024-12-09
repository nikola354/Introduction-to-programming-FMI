#include <iostream>

constexpr int MAX_SIZE = 100;

bool isItSymetrical(int arr[][MAX_SIZE], int n) {
	bool isSymetrical = true;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] != arr[j][i]) return false;
		}
	}

	return true;
}

void readArray(int arr[][MAX_SIZE], int n) {
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < n;j++) {
			std::cin >> arr[i][j];
		}
	}
}

void run() {
	int arr[MAX_SIZE][MAX_SIZE];
	int n;
	std::cin >> n;
	readArray(arr,n);
	std::cout<<std::boolalpha<<isItSymetrical(arr, n);
}

int main()
{
	run();
}
