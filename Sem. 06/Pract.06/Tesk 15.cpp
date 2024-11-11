// Tesk 15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int searchForZero(const int arr[], int n) {
	int low = 0; 
	int high = n - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == 0) {
			return mid;
		}
		else if (arr[mid] % 2 != 0) {
			high = mid - 1;

		}
		else {
			low = mid + 1;
		}
		

	}

	return -1; 

}

int main()
{
	int n; 
	cin >> n;
	int arr[100];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int result = searchForZero(arr, n);

	cout << result;

	
}

