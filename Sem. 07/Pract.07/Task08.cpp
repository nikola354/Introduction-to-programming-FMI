#include <iostream>

constexpr int MAX_SIZE = 100;

int sumOfArrayMembers(int arr[][MAX_SIZE], int n, int m, int s) {
	int result = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			result += (i + j == s) ? arr[i][j] : 0;
		}
	}
	return result;
}


void readArray(int arr[][MAX_SIZE], int n,int m) {
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m;j++) {
			std::cin >> arr[i][j];
		}
	}
}

void run() {
	int arr[MAX_SIZE][MAX_SIZE];

	int n,m,s;
	std::cin >> n >> m >> s;

	readArray(arr, n, m);
	std::cout<<sumOfArrayMembers(arr, n, m, s);
	
}

int main()
{
	run();
}
